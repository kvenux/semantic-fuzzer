#include <iostream>
#include <chrono>
#include <cstring>
#include <cstdlib>
#include "antlr4-runtime.h"
#include "ECMAScriptLexer.h"
#include "ECMAScriptParser.h"
#include "ECMAScriptBaseVisitor.h"
#include "ECMAScriptMutatorVisitor.h"
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
extern "C" void init_rules(char *path);
extern "C" int mutate_one_local(char *target, size_t len, int mutate_loc, char **result, size_t *retlen);

extern "C" void init_exp_pool(char *path);
extern "C" void init_statements_pool(char *path);
extern "C" int gen_ast_path(char *target, size_t len, int *buf);
extern "C" int mutate_exp_and_st(char *target, size_t len, int mutate_loc, char **result, size_t *retlen);


#define MAXSAMPLES 10000
#define MAXTEXT 200

#define AST_PATH_MAX_NUM 200

string ret[MAXSAMPLES + 2];

vector<string> rep_text_pool;
vector<vector<string>> text_pool;

vector<string> st_texts;



class StatementToReplace {
public:
	string text;
	int id_num;
	vector<int> id_starts;
	vector<int> id_ends;
	vector<string> id_texts;
	StatementToReplace (string inputs){
		text = inputs;
		id_num = 0;
	}
	void addID(int start, int end, string id_text){
		id_starts.push_back(start);
		id_ends.push_back(end);
		id_texts.push_back(id_text);
		id_num = id_starts.size();
	}

	string mutator(vector<string> candidates){
		if(id_num == 0){
			return text;
		}
		std::sort(id_starts.begin(), id_starts.end());
		std::sort(id_ends.begin(), id_ends.end());
		//cut into substrs first
		vector<string> pieces;
		string cur_piece;
		string ret = text.substr(0, id_starts[0]);
		// cout<<cur_piece<<endl;
		for(int i=1;i<id_num;i++){
			cur_piece = text.substr(id_ends[i-1] + 1, id_starts[i] - (id_ends[i-1] + 1));
			pieces.push_back(cur_piece);
			// cout<<cur_piece<<endl;
		}
		cur_piece = text.substr(id_ends.back() + 1, text.size() - id_ends.back() + 1);
		pieces.push_back(cur_piece);

		// for(int i=0;i<candidates.size();i++){
		// 	cout<<candidates[i]<<endl;
		// }
		// fix: piece may be null
		for(int i=0;i<pieces.size();i++){
			int RandIndex = rand() % candidates.size();
			string id_rep = candidates[RandIndex];
			ret = ret + id_rep + pieces[i];
		}
		return ret;
	}
};

vector<StatementToReplace> st_list;

class ExpToReplace {
public:
	string text;
	int id_num;
	vector<int> id_starts;
	vector<int> id_ends;
	vector<string> id_texts;
	ExpToReplace (string inputs){
		text = inputs;
		id_num = 0;
	}
	void addID(int start, int end, string id_text){
		if(id_text.compare("assert") == 0) return;
		id_starts.push_back(start);
		id_ends.push_back(end);
		id_texts.push_back(id_text);
		id_num = id_starts.size();
	}

	string mutator(vector<string> candidates){
		if(id_num == 0){
			return text;
		}
		std::sort(id_starts.begin(), id_starts.end());
		std::sort(id_ends.begin(), id_ends.end());
		vector<string> pieces;
		string cur_piece;
		string ret = text.substr(0, id_starts[0]);
		for(int i=1;i<id_num;i++){
			cur_piece = text.substr(id_ends[i-1] + 1, id_starts[i] - (id_ends[i-1] + 1));
			pieces.push_back(cur_piece);
		}
		cur_piece = text.substr(id_ends.back() + 1, text.size() - id_ends.back() + 1);
		pieces.push_back(cur_piece);

		// fix: piece may be null
		for(int i=0;i<pieces.size();i++){
			int RandIndex = rand() % candidates.size();
			string id_rep = candidates[RandIndex];
			ret = ret + id_rep + pieces[i];
		}
		return ret;
	}
};

vector<ExpToReplace> exp_list;

bool cmp(const string &x, const string &y) { return x < y; }


class TreeShapeListener : public ECMAScriptListener {
public:
	vector<long> rules_visitted;
	vector<long> nodes_visitted;
	vector<int> vec_src_hash;
	vector<int> vec_path_hash;
	vector<int> vec_dst_hash;
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

	void generate_paths(){
		int i,j;
		int path_num = trace_num * (trace_num - 1) / 2;
		// float propability = (float) AST_PATH_MAX_NUM / path_num;
		// cout<<propability<<endl;
		int cur_path_cnt = 0;
		
		for(i=0;i<trace_num;i++){
			if(traces[i].size() < 1)
				return;
			for(j=i+1;j<trace_num;j++){
				// int rand_int = rand() % path_num;
				// if(rand_int >= 200 || cur_path_cnt >= 200)
				if(cur_path_cnt >= 200)
					continue;
				cur_path_cnt++;
				int k=0;
				while(k<traces[i].size() && k<traces[j].size() && traces[i][k] == traces[j][k]){
					k++;
				}
				string path_res = "";
				// cout<<"i: "<<i<<endl;
				// cout<<"j: "<<j<<endl;
				// cout<<"trace_num: "<<trace_num<<endl;
				// cout<<"k: "<<k<<endl;
				// cout<<"traces[i].size() "<<i<<" "<<traces[i].size()<<endl;
				for(int index = traces[i].size() - 1; index >= k-1 ;index--){
					int cur_rule = (int)(traces[i][index] / 1E6);
					// cout<<std::to_string(cur_rule)<<endl;
					path_res += "^" + std::to_string(cur_rule);
				}
				// cout<<"traces[j].size() "<<j<<" "<<traces[j].size()<<endl;
				path_res += "_";
				for(int index = k; index < traces[j].size() ;index++){
					int cur_rule = (int)(traces[j][index] / 1E6);
					// cout<<std::to_string(cur_rule)<<endl;
					path_res += std::to_string(cur_rule) + "_";
				}

				// cout<<"path_res "<<traces_id[i]<<path_res<<traces_id[j]<<endl;
				// cout<<(int)std::hash<std::string>()(path_res)<<endl;
				int src_hash = (int)std::hash<std::string>()(traces_id[i]);
				int path_hash = (int)std::hash<std::string>()(path_res);
				int dst_hash = (int)std::hash<std::string>()(traces_id[j]);
				vec_src_hash.push_back(src_hash);
				vec_path_hash.push_back(path_hash);
				vec_dst_hash.push_back(dst_hash);
				// cout<<src_hash<<", "<<path_hash<<", "<<dst_hash<<endl;
			}
			
		}
		// cout<<"cur_path_cnt: "<<cur_path_cnt<<endl;
	}

  void visitTerminal(antlr4::tree::TerminalNode *node) override {
	if(node == NULL)	return;
	// Do something when entering the key rule.
	// cout<<node->toString()<<" getSymbol:"<<node->getSymbol()->getType()<<endl;
	if((node->getSymbol()->getType() >= 15 && node->getSymbol()->getType() <= 55)
	|| node->getSymbol()->getType() == 98 || node->getSymbol()->getType() == 99 ){
		// for(auto i = rules_visitted.begin(); i != rules_visitted.end(); ++i){
		// 	cout << *i << ' ';
		// }
		// cout<<node->toString()<<" "<<node->getSymbol()->getType()<<endl;;
		// cout<<endl;
		vector<long> cur_trace(rules_visitted);
		traces.push_back(cur_trace);
		string cur_id = node->toString();
		traces_id.push_back(cur_id);
		trace_num = traces.size();
	}
	return;
  }

  void visitErrorNode(antlr4::tree::ErrorNode *node) override {
	if(node == NULL)	return;
	// Do something when entering the key rule.
	// cout<<"visitErrorNode"<<endl;
	return;
  }

  void enterEveryRule(antlr4::ParserRuleContext *ctx) override {
	if(ctx == NULL)	return;
	// Do something when entering the key rule.
	// cout<<"enter!"<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;

	// int rule_encoding = ctx->getRuleIndex() * 1E6 + ctx->start->getStartIndex() * 1E3 + ctx->stop->getStopIndex();
	int rule_encoding = ctx->getRuleIndex() * 1E6;
	if(ctx->start == NULL) return;
	rule_encoding += ctx->start->getStartIndex() * 1E3;
	if(ctx->stop == NULL) return;
	rule_encoding += ctx->stop->getStopIndex();
	
	// rules_visitted.push_back(ctx->getRuleIndex());
	rules_visitted.push_back(rule_encoding);
	// cout<<"enter getRuleIndex "<<ctx->getRuleIndex()<<endl;
	// for(auto i = rules_visitted.begin(); i != rules_visitted.end(); ++i){
	// 	cout << *i << ' ';
	// }
	// cout<<endl;
	return;
  }

  void exitEveryRule(antlr4::ParserRuleContext *ctx) override {
	if(ctx == NULL)	return;
	// Do something when entering the key rule.
	// cout<<"exit!"<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
	rules_visitted.pop_back();
	// cout<<"exit getRuleIndex "<<ctx->getRuleIndex()<<endl;
	return;
  }
};

void tree_walk_new(TreeShapeListener *listener, tree::ParseTree *t){
	try{
		// if (is<ErrorNode *>(t)) {
   		// 	listener->visitErrorNode(dynamic_cast<ErrorNode *>(t));
    	// 	return;
  		// }
		if(t == NULL) return;
		cout<<"tree_walk_new bef "<<endl;
		ParserRuleContext *ctx = dynamic_cast<ParserRuleContext *>(t);
		if(ctx == NULL) return;
		cout<<"tree_walk_new  "<<ctx->getRuleIndex()<<endl;
		for (auto &child : t->children) {
			tree_walk_new(listener, child);
		}
	}
	catch (const std::exception& e){
		return ;
	}	
}

void tree_walk_enter_rule(TreeShapeListener *listener, tree::ParseTree *t){
	ParserRuleContext *ctx = dynamic_cast<ParserRuleContext *>(t);
	if(ctx == NULL) return;
	listener->enterEveryRule(ctx);
	return;
}

void tree_walk_exit_rule(TreeShapeListener *listener, tree::ParseTree *t){
	ParserRuleContext *ctx = dynamic_cast<ParserRuleContext *>(t);
	if(ctx == NULL) return;
	listener->exitEveryRule(ctx);
	return;
}


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
	// cout<< "text_size " << text_size <<endl;

	// for(int i=0;i<visitor->declearation_texts.size();i++){
	// 	cout<<visitor->declearation_pos[i]<<": "<<visitor->declearation_texts[i]<<endl;
	// }

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
	delete visitor;

	return 1;
}

void init_exp_pool(char *path){
	ifstream in_fs(path);
	stringstream buffer;
	buffer << in_fs.rdbuf();
	cout<<path<<endl;

	string targetString = buffer.str();
	ANTLRInputStream input(targetString);
	ECMAScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ECMAScriptParser parser(&tokens);
	TokenStreamRewriter rewriter(&tokens);
	tree::ParseTree *tree = parser.program();
	ECMAScriptBaseVisitor *visitor = new ECMAScriptBaseVisitor();
	visitor->visit(tree);
	int text_size = visitor->texts.size();
	// cout<< "text_size " << text_size <<endl;

	// for(int i=0;i<visitor->declearation_texts.size();i++){
	// 	cout<<visitor->declearation_pos[i]<<": "<<visitor->declearation_texts[i]<<endl;
	// }

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

	
	// cout<<"visitor->exp_texts.size() "<<visitor->exp_texts.size()<<endl;

	// for(int i=0;i<visitor->exp_texts.size();i++){
	// 	cout<<i<<": "<<visitor->exp_texts[i]<<endl;
	// }

	visitor->remove_duplicated_exp();

	// cout<<"visitor->exp_unique_texts.size() "<<visitor->exp_unique_texts.size()<<endl;

	// for(int i=0;i<visitor->exp_unique_texts.size();i++){
	// 	cout<<i<<": "<<visitor->exp_unique_texts[i]<<endl;
	// }

	int exp_size = visitor->exp_unique_texts.size();
	for(int i=0;i<exp_size;i++){
		exp_list.push_back(ExpToReplace(visitor->exp_unique_texts[i]));
		string cur_text = visitor->exp_unique_texts[i];
		int cur_st_start = visitor->exp_unique_starts[i];
		int cur_st_end = visitor->exp_unique_ends[i];
		vector <int> cur_id_list;
		for(int j=0;j<visitor->id_starts.size();j++){
			if(visitor->id_starts[j] >= cur_st_start && visitor->id_ends[j] <= cur_st_end){
				int cur_id_start = visitor->id_starts[j] - cur_st_start;
				int cur_id_end = visitor->id_ends[j] - cur_st_start;
				string cur_id_text = cur_text.substr(cur_id_start, cur_id_end - cur_id_start + 1);
				exp_list.back().addID(cur_id_start, cur_id_end, cur_id_text);
			}
		}
	}

	// vector<string> candds;
	// candds.push_back("id0");
	// candds.push_back("id1");
	// candds.push_back("id2");
	// candds.push_back("id3");
	// for (int i = 0; i < exp_list.size(); i++){
	// 	string res = exp_list[i].mutator(candds);
	// 	cout<<res<<endl;
	// }
	// string res = exp_list[24].mutator(candds);
	// cout<<res<<endl;

	// for (int i = 0; i < rep_text_pool.size(); i++){
	// 	cout<< rep_text_pool[i] << endl;
	// }
	cout<<"init expressions exp_list size: "<<exp_list.size()<<endl;

	delete visitor;
}

void init_statements_pool(char *path){
	ifstream in_fs(path);
	stringstream buffer;
	buffer << in_fs.rdbuf();

	string targetString = buffer.str();
	ANTLRInputStream input(targetString);
	ECMAScriptLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ECMAScriptParser parser(&tokens);
	TokenStreamRewriter rewriter(&tokens);
	tree::ParseTree *tree = parser.program();
	ECMAScriptBaseVisitor *visitor = new ECMAScriptBaseVisitor();
	visitor->visit(tree);
	int text_size = visitor->texts.size();
	// cout<< "text_size " << text_size <<endl;

	// for(int i=0;i<visitor->declearation_texts.size();i++){
	// 	cout<<visitor->declearation_pos[i]<<": "<<visitor->declearation_texts[i]<<endl;
	// }

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

	int st_size = visitor->st_texts.size();

	StatementToReplace *st;
	for(int i=0;i<st_size;i++){
		// cout<<i<<": "<<visitor->st_texts[i]<<endl;
		// st = new StatementToReplace(st_texts[i]);
		st_list.push_back(StatementToReplace(visitor->st_texts[i]));
		// cout<<st_list.back().text<<endl;
		string cur_text = visitor->st_texts[i];
		int cur_st_start = visitor->st_starts[i];
		int cur_st_end = visitor->st_ends[i];
		vector <int> cur_id_list;
		for(int j=0;j<visitor->id_starts.size();j++){
			// cout<<visitor->id_starts[j]<<" ";
			if(visitor->id_starts[j] >= cur_st_start && visitor->id_ends[j] <= cur_st_end){
				// cur_id_list.push_back()
				int cur_id_start = visitor->id_starts[j] - cur_st_start;
				int cur_id_end = visitor->id_ends[j] - cur_st_start;
				string cur_id_text = cur_text.substr(cur_id_start, cur_id_end - cur_id_start + 1);
				st_list.back().addID(cur_id_start, cur_id_end, cur_id_text);
				// cout<<"pos: "<<cur_id_start<<" "<<cur_id_end<<endl;
				// cout<<"id: "<<cur_text.substr(cur_id_start, cur_id_end - cur_id_start + 1)<<endl;
			}
		}
		// cout<<"id size: "<<st_list.back().id_starts.size()<<endl;
		// for(int j=0;j<st_list.back().id_num;j++){
		// 	cout<<"pos: "<<st_list.back().id_starts[j]<<" "<<st_list.back().id_ends[j]<<endl;
		// }
	}

	// vector<string> candds;
	// candds.push_back("id0");
	// candds.push_back("id1");
	// candds.push_back("id2");
	// candds.push_back("id3");
	// string res = st_list[24].mutator(candds);
	// cout<<res<<endl;

	// for (int i = 0; i < rep_text_pool.size(); i++){
	// 	cout<< rep_text_pool[i] << endl;
	// }
	cout<<"init statements st_list size: "<<st_list.size()<<endl;

	delete visitor;
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
	// cout<<"interval_size: "<<interval_size<<endl;
	vector<misc::Interval> intervals;
	intervals.clear();
	vector<int> cur_rules;
	cur_rules.clear();
	for (int i = 0; i < interval_size; i++)
	{
		if (find(intervals.begin(), intervals.end(), visitor->intervals[i]) != intervals.end())
		{
		}
		// else if (visitor->intervals[i].a <= visitor->intervals[i].b)
		else if (visitor->intervals[i].a < visitor->intervals[i].b)
		{
			intervals.push_back(visitor->intervals[i]);
			cur_rules.push_back(visitor->rule_index_array[i]);
		}
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
		cout<<"no candidates: "<<cur_rule_index<<endl;
		return 0;
	}
	int rep_text_index = rand() % text_pool[cur_rule_index].size();
	// cout<<text_pool[cur_rule_index][rep_text_index]<<endl;
	// cout<<intervals[mutate_loc].toString()<<endl;
	rewriter.replace(intervals[mutate_loc].a, intervals[mutate_loc].b, text_pool[cur_rule_index][rep_text_index]);
	// cout<<rewriter.getText()<<endl;
}

int mutate_one_local(char *target, size_t len, int mutate_loc, char **result, size_t *retlen){
	try{
		// auto t1 = std::chrono::high_resolution_clock::now();
		// auto t2 = std::chrono::high_resolution_clock::now();
		// auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
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
		// cout<<"interval_size: "<<interval_size<<endl;
		// cout<<targetString<<endl;
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
			if(visitor->rule_index_array[i] == 29 || visitor->rule_index_array[i] == 31
				|| visitor->rule_index_array[i] == 53
				|| visitor->rule_index_array[i] == 32
				|| visitor->rule_index_array[i] == 45
				|| visitor->rule_index_array[i] == 46){
					continue;
				}
				if (visitor->intervals[i].a < visitor->intervals[i].b){
					intervals.push_back(visitor->intervals[i]);
					cur_rules.push_back(visitor->rule_index_array[i]);
				}
				
				// cout<<"visitor->rule_index_array[i]"<<visitor->rule_index_array[i]<<endl;
				// cout<<visitor->texts[i]<<endl;
				// cout<<"-----------------"<<endl;
				// cout<<text_pool[visitor->rule_index_array[i]][1]<<endl;
				// cout<<"================="<<endl;

			// }
		}
		
		interval_size = intervals.size();
		mutate_loc = mutate_loc < 0? 0: mutate_loc;
		mutate_loc = mutate_loc > (interval_size-1) ? interval_size-1: mutate_loc;
		// cout<<"interval_size: "<<intervals.size()<<endl;
		// cout<<"mutate_loc"<<mutate_loc<<endl;
		if(mutate_loc < 0){
			return 0;
		}
		int cur_rule_index = cur_rules[mutate_loc];
		// cout<<"cur_rule_index: "<<cur_rule_index<<endl;
		// cout<<"text_pool[cur_rule_index].size(): "<<text_pool[cur_rule_index].size()<<endl;
		// cout<<"text_pool[cur_rule_index][1]: "<<text_pool[cur_rule_index][1]<<endl;
		if(text_pool[cur_rule_index].size() == 0){
			// cout<<"no candidates: "<<cur_rule_index<<endl;
			return 0;
		}
		int rep_text_index = rand() % text_pool[cur_rule_index].size();
		// cout<<text_pool[cur_rule_index][rep_text_index]<<endl;
		// cout<<intervals[mutate_loc].toString()<<endl;
		rewriter.replace(intervals[mutate_loc].a, intervals[mutate_loc].b, text_pool[cur_rule_index][rep_text_index]);
		// cout<<rewriter.getText()<<endl;
		*retlen = rewriter.getText().length();
		*result = strdup(rewriter.getText().c_str());
		delete visitor;
		// delete tree;
		// delete &tokens;
		// delete &lexer;
		// delete &input;
		// delete &targetString;
		// delete &rewriter;
	}
	catch (range_error e){
		return 0;
	}
	return 1;
}

int mutate_statement(char *target, size_t len, int mutate_loc, char **result, size_t *retlen){
	try{
		string targetString = string(target, len);
		ANTLRInputStream input(targetString);
		ECMAScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ECMAScriptParser parser(&tokens);
		TokenStreamRewriter rewriter(&tokens);
		tree::ParseTree *tree = parser.program();
		ECMAScriptMutatorVisitor *visitor = new ECMAScriptMutatorVisitor();
		visitor->visit(tree);
		

		visitor->remove_del_st();
		int st_size = visitor->st_texts.size();
		mutate_loc = mutate_loc < 0? 0: mutate_loc;
		mutate_loc = mutate_loc > (st_size-1) ? st_size-1: mutate_loc;
		int cur_end_pos = visitor->st_ends[mutate_loc];
		vector<string> candidates;
		for(int i=0;i<visitor->decl_id_texts.size();i++){
			if(visitor->decl_ends[i] < cur_end_pos){
				candidates.push_back(visitor->decl_id_texts[i]);
			}
		}
		// for(int i=0;i<candidates.size();i++){
		// 	cout<<candidates[i]<<endl;
		// }

		int rand_index = rand()%st_list.size();
		string res = st_list[rand_index].mutator(candidates);
		// cout<<res<<endl;
		// cout<<"start index: "<<ctx->start->getStartIndex()<<", "<<ctx->stop->getStopIndex()<<endl;
		
		rewriter.replace(visitor->st_intervals[mutate_loc].a, visitor->st_intervals[mutate_loc].b, res);
		// cout<<rewriter.getText()<<endl;
		*retlen = rewriter.getText().length();
		*result = strdup(rewriter.getText().c_str());
		delete visitor;
		// delete tree;
		// delete &tokens;
		// delete &lexer;
		// delete &input;
		// delete &targetString;
		// delete &rewriter;
	}
	catch (range_error e){
		return 0;
	}
	return 1;
}

int mutate_expression(char *target, size_t len, int mutate_loc, char **result, size_t *retlen){
	try{
		string targetString = string(target, len);
		ANTLRInputStream input(targetString);
		ECMAScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ECMAScriptParser parser(&tokens);
		TokenStreamRewriter rewriter(&tokens);
		tree::ParseTree *tree = parser.program();
		ECMAScriptMutatorVisitor *visitor = new ECMAScriptMutatorVisitor();
		visitor->visit(tree);

		visitor->remove_del_st();
		int st_size = visitor->st_texts.size();
		mutate_loc = mutate_loc < 0? 0: mutate_loc;
		mutate_loc = mutate_loc > (st_size-1) ? st_size-1: mutate_loc;
		int cur_end_pos = visitor->st_ends[mutate_loc];
		vector<string> candidates;
		for(int i=0;i<visitor->decl_id_texts.size();i++){
			if(visitor->decl_ends[i] < cur_end_pos){
				candidates.push_back(visitor->decl_id_texts[i]);
			}
		}
		// for(int i=0;i<candidates.size();i++){
		// 	cout<<candidates[i]<<endl;
		// }

		int rand_index = rand()%exp_list.size();
		string res = exp_list[rand_index].mutator(candidates);
		// cout<<res<<endl;
		// cout<<"start index: "<<ctx->start->getStartIndex()<<", "<<ctx->stop->getStopIndex()<<endl;
		
		rewriter.replace(visitor->st_intervals[mutate_loc].a, visitor->st_intervals[mutate_loc].b, res);
		// cout<<rewriter.getText()<<endl;
		*retlen = rewriter.getText().length();
		*result = strdup(rewriter.getText().c_str());
		delete visitor;
	}
	catch (range_error e){
		return 0;
	}
	return 1;
}

int mutate_exp_and_st(char *target, size_t len, int mutate_loc, char **result, size_t *retlen){
	// auto t1 = std::chrono::high_resolution_clock::now();
	// auto t2 = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	try{
		string targetString = string(target, len);
		ANTLRInputStream input(targetString);
		ECMAScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ECMAScriptParser parser(&tokens);
		TokenStreamRewriter rewriter(&tokens);	
		tree::ParseTree *tree = parser.program();
		ECMAScriptMutatorVisitor *visitor = new ECMAScriptMutatorVisitor();
		visitor->visit(tree);
		
		visitor->remove_del_st();
		
		int st_size = visitor->st_texts.size();
		int exp_size = visitor->exp_texts.size();
		int uniform_size = st_size + exp_size;
		mutate_loc = mutate_loc < 0? 0: mutate_loc;
		mutate_loc = mutate_loc > (uniform_size-1) ? uniform_size-1: mutate_loc;

		// cout<<"mutate_loc "<<mutate_loc<<endl;
		int cur_end_pos = 0;
		vector<string> candidates;
		if(mutate_loc < st_size)
			cur_end_pos = visitor->st_ends[mutate_loc];
		else
			cur_end_pos = visitor->exp_ends[mutate_loc - st_size];
		// cout<<"cur_end_pos "<<cur_end_pos<<endl;
		// cout<<"visitor->decl_id_texts.size() "<<visitor->decl_id_texts.size()<<endl;
		for(int i=0;i<visitor->decl_id_texts.size();i++){
			if(visitor->decl_ends[i] < cur_end_pos){
				candidates.push_back(visitor->decl_id_texts[i]);
			}
		}
		for(int i=0;i<visitor->fnpr_id_texts.size();i++){
			if(visitor->fnpr_ends[i] < cur_end_pos && cur_end_pos <= visitor->fnpr_domain_ends[i]){
				candidates.push_back(visitor->fnpr_id_texts[i]);
			}
		}
		
		if(candidates.size() == 0){
			return 0;
		}
		int rand_index = 0;
		string res;
		// cout<<"rand_index "<<rand_index<<endl;
		// cout<<"candidates size "<<candidates.size()<<endl;
		// cout<<"visitor->st_texts[mutate_loc] "<<visitor->st_texts[mutate_loc]<<endl;
		if(mutate_loc < st_size){
			rand_index = rand()%st_list.size();
			res = st_list[rand_index].mutator(candidates);
			if(visitor->st_intervals[mutate_loc].a > visitor->st_intervals[mutate_loc].b)
				return 0;
			rewriter.replace(visitor->st_intervals[mutate_loc].a, visitor->st_intervals[mutate_loc].b, res);
		}
		else{
			rand_index = rand()%exp_list.size();
			res = exp_list[rand_index].mutator(candidates);
			if(visitor->exp_intervals[mutate_loc - st_size].a > visitor->exp_intervals[mutate_loc - st_size].b)
				return 0;
			rewriter.replace(visitor->exp_intervals[mutate_loc - st_size].a, visitor->exp_intervals[mutate_loc - st_size].b, res);
		}
		
		*retlen = rewriter.getText().length();
		*result = strdup(rewriter.getText().c_str());
		delete visitor;
	}
	catch (range_error e){
		return 0;
	}
	return 1;
}


int gen_ast_path(char *target, size_t len, int *buf){
	try{
		string targetString = string(target, len);
		// cout<<targetString<<endl;
		ANTLRInputStream input(targetString);
		ECMAScriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ECMAScriptParser parser(&tokens);
		TokenStreamRewriter rewriter(&tokens);
		tree::ParseTree *tree = parser.program();

		TreeShapeListener listener;
		// tree_walk_new(&listener, tree);
		// exit(0);

		// TreeShapeListener listener;
		tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
	
		listener.generate_paths();
		// cout<<listener.vec_src_hash.size()<<endl;
		// cout<<listener.vec_path_hash.size()<<endl;
		// cout<<listener.vec_dst_hash.size()<<endl;
		
		std::copy(listener.vec_src_hash.begin(), listener.vec_src_hash.end(), buf);
		std::copy(listener.vec_path_hash.begin(), listener.vec_path_hash.end(), buf + AST_PATH_MAX_NUM);
		std::copy(listener.vec_dst_hash.begin(), listener.vec_dst_hash.end(), buf + AST_PATH_MAX_NUM * 2);
		// for(int i=0;i<10;i++){
		// 	cout<<listener.vec_dst_hash[i]<<endl;
		// }

	}
	catch (const std::exception& e){
		return 0;
	}
	return 1;
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
		cout << "start counting: " <<endl;
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
		
		TreeShapeListener listener;
		tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
		// listener.print_all_traces();
		listener.generate_paths();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
		cout << "duration: " << duration<<endl;

		exit(0);

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

void init_rules(char *path){
	ifstream in_fs(path);
	stringstream buffer;
	buffer << in_fs.rdbuf();
	cout<<buffer.str().size()<<endl;
	
	vector<string> toret;
	splitString(toret, buffer.str(), "&$%");
	cout<<toret.size()<<endl;

	text_pool.resize(55);

	int rules_num = 0;
	for(int i=0;i<55;i++){
		splitString(text_pool[i], toret[i], "@#@");
		cout<<i<<": "<<text_pool[i].size()<<endl;
		if(text_pool[i].size() > 0)
			cout<<text_pool[i][0]<<endl;
		rules_num += text_pool[i].size();
	}
	cout<<rules_num<<endl;
}

int main()
{
	ifstream in;
	char target[100 * 1024];
	int len = 0;
	in.open("expressions.js");
	while (!in.eof())
	{
		in.read(target, 102400);
	}
	len = in.gcount();
	// cout << target << endl;
	// cout << len << endl;
	in.close();
	// init_exp_pool(target, len);

	struct dirent *entry;
	string path = "/home/keven/Projects/Fuzzing/jerryscript/test_candidates_filter/";
	DIR *dir = opendir("/home/keven/Projects/Fuzzing/jerryscript/test_candidates_filter");
	if (dir == NULL) {
		return 0;
	}
	while ((entry = readdir(dir)) != NULL) {
		string file_name(entry->d_name);
		cout<<file_name<<endl;
		if(file_name.size() <= 2) continue;
		string file_path(path + entry->d_name);
		char *cstr = new char[file_path.length() + 1];
		strcpy(cstr, file_path.c_str());
		init_exp_pool(cstr);
		cout<<exp_list.size()<<endl;
		
	}
	closedir(dir);

	vector<string> candds;
	candds.push_back("id0");
	
	for(int i=0;i<exp_list.size();i++){
		cout<<i<<" "<<exp_list.size()<<endl;
		// cout<<exp_list[i].text<<endl;
		if(i>= exp_list.size()) break;
		string res_i = exp_list[i].mutator(candds);
		for(int j=i+1;j<exp_list.size();j++){
			if(j>= exp_list.size()) break;
			string res_j = exp_list[j].mutator(candds);
			if(res_i.compare(res_j) == 0){
				// cout<<res_i<<" "<<res_i<<endl;
				exp_list.erase(exp_list.begin() + j);
			}
		}
	}
	cout<<exp_list.size()<<endl;

	string out_buf = "";
	for(int i=200;i<exp_list.size();i++){
		// cout<<exp_list[i].text<<endl;
		// string cur_exp_buf = "";
		string cur_buf = "";
		cur_buf += exp_list[i].text;
		cur_buf += "@#@";
		for(int j=0;j<exp_list[i].id_texts.size();j++){
			cur_buf += to_string(exp_list[i].id_starts[j]) + ",";
			cur_buf += to_string(exp_list[i].id_ends[j]) + ",";
			cur_buf += exp_list[i].id_texts[j] + ",";
		}
		cur_buf += "@#@";
		cur_buf += "&$%";
		cout<<cur_buf<<endl;
		out_buf += cur_buf;
		// if(i> 210) break;
	}
	int cur_index = 202;
	cout<<exp_list[cur_index].text<<endl;
	cout<<"id_texts.size() "<<exp_list[cur_index].id_texts.size()<<endl;
	for(int j=0;j<exp_list[cur_index].id_texts.size();j++){
		cout<<exp_list[cur_index].id_starts[j]<<" ";
		cout<<exp_list[cur_index].id_ends[j]<<" ";
		cout<<exp_list[cur_index].id_texts[j]<<" ";
		cout<<endl;
	}

	ofstream fout;
	fout.open("init_exps_all");
	fout<<out_buf;
	fout.close();

	exit(0);

	// char path[]="expressions.js";
	// init_exp_pool(path);
	// cout<<exp_list.size()<<endl;
	// init_exp_pool("statements.js");
	// cout<<exp_list.size()<<endl;
	// // init_statements_pool("statements.js");
	exit(0);

	char second[100 * 1024];
	int lenS = 0;
	// in.open("/home/keven/Projects/Fuzzing/Superion/tree_mutation/js_parser/test2.js");
	in.open("test4.js");
	while (!in.eof())
	{
		in.read(second, 102400);
	}
	lenS = in.gcount();
	// cout << second << endl;
	// cout << lenS << endl;
	in.close();

	int *int_buf=NULL;
	int_buf = (int *)malloc(AST_PATH_MAX_NUM * 3 * sizeof(int));
	gen_ast_path(second, lenS, int_buf);

	exit(0);

	// init_pool(target, len);
	

	// for(int i=0;i<55;i++){
	// 	if(text_pool[i].size() > 0){
	// 		cout<<"type: "<<i<<" num: "<<text_pool[i].size()<<endl;
	// 		// cout<<text_pool[i][0]<<endl;
	// 	}
	// }



	// init_statements_pool(target, len);

	// exit(0);

	cout << second << endl;
	cout << lenS << endl;
	char *s_buf=NULL;
	size_t s_len = 0;
	// mutate_exp_and_st(second, lenS, 0, &s_buf, &s_len);
	// cout << s_buf << endl;
	// cout << s_len << endl;
	// mutate_exp_and_st(second, lenS, 0, &s_buf, &s_len);
	mutate_one_local(second, lenS, 0, &s_buf, &s_len);
	cout << s_buf << endl;
	cout << s_len << endl;
	exit(0);
	
	// mutate_one(target, len, 1);
	// mutate_one(target, len, 2);
	
}
