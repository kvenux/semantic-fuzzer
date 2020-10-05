#include <iostream>
#include <chrono>
#include <cstring>
#include <cstdlib>
#include "antlr4-runtime.h"
#include "ECMAScriptLexer.h"
#include "ECMAScriptParser.h"
#include "ECMAScriptBaseVisitor.h"
#include "ECMAScriptSecondVisitor.h"
#include "ECMAScriptListener.h"

#include <dirent.h>
#include <sys/types.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>

using namespace antlr4;
using namespace std;

extern "C" int parse(char *target, size_t len, char *second, size_t lenS);
extern "C" void fuzz(int index, char **ret, size_t *retlen);

#define MAXSAMPLES 10000
#define MAXTEXT 200

string ret[MAXSAMPLES + 2];

vector<string> rep_text_pool;
vector<vector<string>> text_pool;

bool cmp(const string &x, const string &y) { return x < y; }

class TreeShapeListener : public ECMAScriptListener {
public:
	vector<long> rules_visitted;
	vector<vector<long>> traces;
	vector<string> traces_id;
	int trace_num;
	string upSymbol = "^";
	string downSymbol = "_";

	void print_all_traces(){
		for(int i=0; i<trace_num; i++){
			vector<long> cur_trace = traces[i];
			string cur_id = traces_id[i];
			for(auto j = cur_trace.begin(); j != cur_trace.end(); ++j){
				cout << *j << ' ';
			}
			cout<<cur_id;
			cout<<endl;
		}
	}

  void visitTerminal(antlr4::tree::TerminalNode *node) override {
	// Do something when entering the key rule.
	// cout<<node->toString()<<" getSymbol:"<<node->getSymbol()->getType()<<endl;
	if(node->getSymbol()->getType() == 98){
		// for(auto i = rules_visitted.begin(); i != rules_visitted.end(); ++i){
		// 	cout << *i << ' ';
		// }
		// cout<<node->toString();
		// cout<<endl;
		vector<long> cur_trace(rules_visitted);
		traces.push_back(cur_trace);
		string cur_id = node->toString();
		traces_id.push_back(cur_id);
		trace_num++;
	}
	return;
  }

  void visitErrorNode(antlr4::tree::ErrorNode *node) override {
	// Do something when entering the key rule.
	return;
  }

  void enterEveryRule(antlr4::ParserRuleContext *ctx) override {
	// Do something when entering the key rule.
	// cout<<"enter!"<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
	rules_visitted.push_back(ctx->getRuleIndex());
	// cout<<"enter getRuleIndex "<<ctx->getRuleIndex()<<endl;
	// for(auto i = rules_visitted.begin(); i != rules_visitted.end(); ++i){
	// 	cout << *i << ' ';
	// }
	// cout<<endl;
	return;
  }

  void exitEveryRule(antlr4::ParserRuleContext *ctx) override {
	// Do something when entering the key rule.
	// cout<<"exit!"<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
	rules_visitted.pop_back();
	// cout<<"exit getRuleIndex "<<ctx->getRuleIndex()<<endl;
	return;
  }
};

int init_pool(char *input_text, size_t input_len){
	string targetString = string(input_text, input_len);
	ANTLRInputStream input(targetString);
	ECMAScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ECMAScriptParser parser(&tokens);
	TokenStreamRewriter rewriter(&tokens);
	tree::ParseTree *tree = parser.program();
	ECMAScriptBaseVisitor *visitor = new ECMAScriptBaseVisitor();
	visitor->visit(tree);
	int text_size = visitor->texts.size();
	cout<< "text_size " << text_size <<endl;
	if(text_pool.size() == 0){
		text_pool.resize(55);
	}
	for (int i = 0; i < text_size; i++)
	{
		if (find(rep_text_pool.begin(), rep_text_pool.end(), visitor->texts[i]) != rep_text_pool.end())
		{
		}
		else if (visitor->texts[i].length() > MAXTEXT)
		{
		}
		else
		{
			int cur_rule_index = visitor->rule_index_array[i];
			if(cur_rule_index >= 0 && cur_rule_index < 55){
				text_pool[cur_rule_index].push_back(visitor->texts[i]);
			}
			rep_text_pool.push_back(visitor->texts[i]);
			// cout<<i<<": "<<visitor->texts[i]<<endl;
		}
	}

	// for (int i = 0; i < rep_text_pool.size(); i++){
	// 	cout<< rep_text_pool[i] << endl;
	// }

	return 1;
}

int mutate_one(char *target, size_t len, int mutate_loc){
	string targetString = string(target, len);
	ANTLRInputStream input(targetString);
	ECMAScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ECMAScriptParser parser(&tokens);
	TokenStreamRewriter rewriter(&tokens);
	tree::ParseTree *tree = parser.program();
	ECMAScriptBaseVisitor *visitor = new ECMAScriptBaseVisitor();
	visitor->visit(tree);
	int interval_size = visitor->intervals.size();
	cout<<"interval_size: "<<interval_size<<endl;
	vector<misc::Interval> intervals;
	intervals.clear();
	vector<int> cur_rules;
	cur_rules.clear();
	for (int i = 0; i < interval_size; i++)
	{
		// if (find(intervals.begin(), intervals.end(), visitor->intervals[i]) != intervals.end())
		// {
		// }
		// // else if (visitor->intervals[i].a <= visitor->intervals[i].b)
		// else if (visitor->intervals[i].a < visitor->intervals[i].b)
		// {
			intervals.push_back(visitor->intervals[i]);
			cur_rules.push_back(visitor->rule_index_array[i]);
		// }
	}
	interval_size = intervals.size();
	mutate_loc = mutate_loc < 0? 0: mutate_loc;
	mutate_loc = mutate_loc > (interval_size-1) ? interval_size-1: mutate_loc;
	// cout<<intervals.size()<<endl;
	int cur_rule_index = cur_rules[mutate_loc];
	// cout<<"cur_rule_index: "<<cur_rule_index<<endl;
	// cout<<"text_pool[cur_rule_index].size(): "<<text_pool[cur_rule_index].size()<<endl;
	// cout<<"text_pool[cur_rule_index][1]: "<<text_pool[cur_rule_index][1]<<endl;
	if(text_pool[cur_rule_index].size() == 0){
		cout<<"no candidates"<<endl;
		return 0;
	}
	int rep_text_index = rand() % text_pool[cur_rule_index].size();
	// cout<<text_pool[cur_rule_index][rep_text_index]<<endl;
	// cout<<intervals[mutate_loc].toString()<<endl;
	rewriter.replace(intervals[mutate_loc].a, intervals[mutate_loc].b, text_pool[cur_rule_index][rep_text_index]);
	cout<<rewriter.getText()<<endl;
}

int parse(char *target, size_t len, char *second, size_t lenS)
{
	vector<misc::Interval> intervals;
	intervals.clear();
	vector<string> texts;
	texts.clear();
	int num_of_smaples = 0;
	//parse the target
	string targetString;
	try
	{	
		auto t1 = std::chrono::high_resolution_clock::now();
		targetString = string(target, len);
		ANTLRInputStream input(targetString);
		//ANTLRInputStream input(target);
		ECMAScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ECMAScriptParser parser(&tokens);
		TokenStreamRewriter rewriter(&tokens);
		tree::ParseTree *tree = parser.program();

		// ECMAScriptParser::ProgramContext *new_tree = parser.program();
		// cout << new_tree->getToken() << endl;
		// misc::Interval test_interval = tree->getSourceInterval();
		// cout << test_interval.length() << endl;
		// cout << test_interval.hashCode() << endl;
		// tree::ParseTree *new_tree = parser.key();
		
		// TreeShapeListener listener;
		// tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
		// // listener.print_all_traces();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
		cout << "duration: " << duration<<endl;

		// exit(0);

		// cout << tree->toStringTree() << endl;
		if (parser.getNumberOfSyntaxErrors() > 0)
		{
			//std::cerr<<"NumberOfSyntaxErrors:"<<parser.getNumberOfSyntaxErrors()<<endl;
			return 0;
		}
		else
		{
			ECMAScriptBaseVisitor *visitor = new ECMAScriptBaseVisitor();
			visitor->visit(tree);
			int text_size = visitor->texts.size();
			// for (int i = 0; i < text_size; i++){
			// 	cout<< i << visitor->texts[i] <<endl;
			// }

			int interval_size = visitor->intervals.size();
			cout<<"interval_size: "<<interval_size<<endl;
			auto t1 = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < interval_size; i++)
			{
				if (find(intervals.begin(), intervals.end(), visitor->intervals[i]) != intervals.end())
				{
				}
				else if (visitor->intervals[i].a <= visitor->intervals[i].b)
				{
					intervals.push_back(visitor->intervals[i]);
				}
				// cout<<visitor->intervals[i].toString()<<endl;
			}
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
			cout << "intervals duration: " << duration<<endl;

			int texts_size = visitor->texts.size();
			// cout<<"texts_size: "<<texts_size<<endl;
			for (int i = 0; i < texts_size; i++)
			{
				if (find(texts.begin(), texts.end(), visitor->texts[i]) != texts.end())
				{
				}
				else if (visitor->texts[i].length() > MAXTEXT)
				{
				}
				else
				{
					texts.push_back(visitor->texts[i]);
					// cout<<i<<": "<<visitor->texts[i]<<endl;
				}
				
			}
			cout<<"texts.size(): "<<texts.size()<<endl;
			delete visitor;
			//parse sencond
			string secondString;
			try
			{
				secondString = string(second, lenS);
				//cout<<targetString<<endl;
				//cout<<secondString<<endl;

				ANTLRInputStream inputS(secondString);
				ECMAScriptLexer lexerS(&inputS);
				CommonTokenStream tokensS(&lexerS);
				ECMAScriptParser parserS(&tokensS);
				tree::ParseTree *treeS = parserS.program();

				if (parserS.getNumberOfSyntaxErrors() > 0)
				{
					//std::cerr<<"NumberOfSyntaxErrors S:"<<parserS.getNumberOfSyntaxErrors()<<endl;
				}
				else
				{
					ECMAScriptSecondVisitor *visitorS = new ECMAScriptSecondVisitor();
					visitorS->visit(treeS);
					texts_size = visitorS->texts.size();
					for (int i = 0; i < texts_size; i++)
					{
						if (find(texts.begin(), texts.end(), visitorS->texts[i]) != texts.end())
						{
						}
						else if (visitorS->texts[i].length() > MAXTEXT)
						{
						}
						else
						{
							texts.push_back(visitorS->texts[i]);
						}
					}
					delete visitorS;
				}
				cout<<"texts.size(): "<<texts.size()<<endl;

				interval_size = intervals.size();
				sort(texts.begin(), texts.end());
				texts_size = texts.size();

				t1 = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < interval_size; i++)
				{
					for (int j = 0; j < texts_size; j++)
					{
						// cout<<j<<texts[j]<<endl;
						// cout<<i<<" "<<intervals[i].a<<" "<<intervals[i].b<<endl;
						rewriter.replace(intervals[i].a, intervals[i].b, texts[j]);
						ret[num_of_smaples++] = rewriter.getText();
						cout<<rewriter.getText()<<endl;
						break;
						if (num_of_smaples >= MAXSAMPLES)
							break;
					}
					if (num_of_smaples >= MAXSAMPLES)
						break;
				}
				auto t2 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
				cout << "duration for "<<interval_size*texts_size<<" : " << duration<<endl;
			}
			catch (range_error e)
			{
				//std::cerr<<"range_error"<<second<<endl;
			}
		}
	}
	catch (range_error e)
	{
		//std::cerr<<"range_error:"<<target<<endl;
	}

	return num_of_smaples;
}

void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
	size_t pos = data.find(toSearch);
	while( pos != std::string::npos)
	{
		vec.push_back(pos);
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

void splitString(std::vector<string> & ret, std::string data, std::string toSearch)
{
	std::vector<size_t> vec;
	findAllOccurances(vec, data , toSearch);
	std::cout<<"All Index Positions are:"<<std::endl;
	if(vec.size()<1){
		return;
	}
	ret.push_back(data.substr(0, vec[0]));
	for(int i=1;i<vec.size();i++){
		ret.push_back(data.substr(vec[i-1]+toSearch.size(), vec[i]-vec[i-1]-toSearch.size()));
	}
}


void fuzz(int index, char **result, size_t *retlen)
{
	*retlen = ret[index].length();
	*result = strdup(ret[index].c_str());
}

int main()
{
	ifstream in;
	char target[100 * 1024];
	int len = 0;
	in.open("/home/keven/Projects/Fuzzing/Superion/tree_mutation/js_parser/test.js");
	while (!in.eof())
	{
		in.read(target, 102400);
	}
	len = in.gcount();
	cout << target << endl;
	cout << len << endl;
	in.close();

	char second[100 * 1024];
	int lenS = 0;
	in.open("/home/keven/Projects/Fuzzing/Superion/tree_mutation/js_parser/test2.js");
	while (!in.eof())
	{
		in.read(second, 102400);
	}
	lenS = in.gcount();
	cout << second << endl;
	cout << lenS << endl;
	in.close();

	// int num_of_smaples = parse(target, len, second, lenS);

	// vector<vector<string>> mat;
	// mat.resize(100);
	// cout<<mat.size()<<endl;
	// for(int i=0;i<100;i++){
	// 	mat[i].push_back("hello");
	// }
	// cout<<mat[98][0]<<endl;
	// cout<<mat[98].size()<<endl;
	// string s = "scott@@tiger";
	// cout<<s.substr(0, s.find("@@"))<<endl;
	// cout<<s.substr(s.find("@@"), s.size())<<endl;
	// ofstream fout;
	// fout.open("test.txt");
	// fout<<s;
	// fout.close();
	string s = "@@o, i@@x, y@@arg";
	string sub = "@@";

	// std::vector<size_t> vec;
	// findAllOccurances(vec, s , "@@");
	// std::cout<<"All Index Position of 'is' in given string are,"<<std::endl;
	// for(size_t pos : vec)
	// 	std::cout<<pos<<std::endl;

	// std::vector<std::string> strs;
	// boost::split(strs, s, boost::regex("\\@@"));
	// for(auto i=0;i<strs.size();i++){
	// 	cout<<strs[i]<<endl;
	// }
	// exit(0);

	struct dirent *entry;
	string path = "/home/keven/Projects/Fuzzing/jerryscript/test_candidates/";
	DIR *dir = opendir("/home/keven/Projects/Fuzzing/jerryscript/test_candidates");
	if (dir == NULL) {
		return 0;
	}
	while ((entry = readdir(dir)) != NULL) {
		cout << path + entry->d_name << endl;
		string file_name(entry->d_name);
		// cout<<file_name.size()<<endl;
		if(file_name.size() <= 2) continue;
		char buffer_in[100 * 1024];
		int len_in = 0;
		in.open(path + entry->d_name);
		while (!in.eof())
		{
			in.read(buffer_in, 102400);
		}
		len_in = in.gcount();
		// cout << buffer_in << endl;
		// cout << len_in << endl;
		in.close();
		init_pool(buffer_in, len_in);
	}
	closedir(dir);

	init_pool(target, len);
	init_pool(second, lenS);

	string out_buf = "";
	for(int i=0;i<55;i++){
		for(int j=0;j<text_pool[i].size();j++){
			out_buf += text_pool[i][j] + "@#@";
		}
		out_buf += "&$%";
	}
	cout<<out_buf.size()<<endl;

	ofstream fout;
	fout.open("init_rules_v1");
	fout<<out_buf;
	fout.close();

	// std::vector<size_t> vec;
	// findAllOccurances(vec, out_buf , "@@");
	// std::cout<<"All Index Positions are:"<<std::endl;
	// for(size_t pos : vec)
	// 	std::cout<<pos<<std::endl;

	// vector<string> toret;
	// splitString(toret, out_buf, "&$%");
	// cout<<toret.size()<<endl;

	// vector<string> onevec;
	// splitString(onevec, toret[31], "@#@");
	// cout<<onevec.size()<<endl;

	// for(int i=0;i<onevec.size();i++){
	// 	cout<<i<<": "<<onevec[i]<<endl;
	// }
	
	exit(0);
	// mutate_one(target, len, 1);
	// mutate_one(target, len, 2);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	mutate_one(target, len, 3);
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i=0;i<21;i++)
		mutate_one(target, len, i);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	cout << "duration: " << duration<<endl;

	// mutate_one(target, len, -1);
	// mutate_one(target, len, 0);
	// mutate_one(target, len, 100);

	// for (int i = 0; i < num_of_smaples; i++)
	// {
	// 	char *retbuf = nullptr;
	// 	size_t retlen = 0;
	// 	fuzz(i, &retbuf, &retlen);
	// 	// cout<<i<<retlen<<retbuf<<endl;
	// }
	// cout << "num_of_smaples:" << num_of_smaples << endl;
}
