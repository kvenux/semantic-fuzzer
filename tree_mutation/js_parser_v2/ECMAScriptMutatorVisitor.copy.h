
// Generated from C:\Users\xiang\Documents\GitHub\js_parser\ECMAScript.g4 by ANTLR 4.7

#pragma once

#include <iostream>
#include <vector>
#include "antlr4-runtime.h"
#include "ECMAScriptVisitor.h"

using namespace std;

/**
 * This class provides an empty implementation of ECMAScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ECMAScriptMutatorVisitor : public ECMAScriptVisitor {
public:
  // vector<misc::Interval> intervals;
  // vector<string> texts;
  // vector<int> rule_index_array;

  // declearation related
  vector<string> decl_texts;
  vector<string> decl_id_texts;
  vector<int> decl_starts;
  vector<int> decl_ends;

  // function parameters related
  vector<string> fnpr_texts;
  vector<string> fnpr_id_texts;
  vector<int> fnpr_starts;
  vector<int> fnpr_ends;
  vector<int> fnpr_domain_ends;

  // function related
  vector<int> fun_starts;
  vector<int> fun_ends;

  // statements related
  vector<string> st_texts;
  vector<int> st_starts;
  vector<int> st_ends;
  vector<misc::Interval> st_intervals;

  // statements related
  vector<string> exp_texts;
  vector<int> exp_starts;
  vector<int> exp_ends;
  vector<misc::Interval> exp_intervals;
  

  void remove_del_st(){
    // cout<<"remove_del_st"<<endl;
    // cout<<"decl_texts.size()"<<decl_texts.size()<<endl;
    // fix: decl in for iteration is deleted
		for(int i=0;i<decl_texts.size();i++){
      // cout<<i<<": "<<decl_texts[i]<<endl;
      // cout<<"starts: "<<decl_starts[i]<<endl;
      // cout<<"ends: "<<decl_ends[i]<<endl;
      // cout<<"st_texts.size()"<<st_texts.size()<<endl;
      for(int j=0;j<st_texts.size();j++){
        // decl in st
        if(decl_starts[i]>= st_starts[j] && decl_ends[i] <= st_ends[j]){
          // cout<<decl_texts[i]<<" in "<<st_texts[j]<<endl;
          st_texts.erase(st_texts.begin() + j);
          st_starts.erase(st_starts.begin() + j);
          st_ends.erase(st_ends.begin() + j);
          st_intervals.erase(st_intervals.begin() + j);
        }
        // st in decl
        if(decl_starts[i]<= st_starts[j] && decl_ends[i] >= st_ends[j]){
          // cout<<decl_texts[i]<<" in "<<st_texts[j]<<endl;
          st_texts.erase(st_texts.begin() + j);
          st_starts.erase(st_starts.begin() + j);
          st_ends.erase(st_ends.begin() + j);
          st_intervals.erase(st_intervals.begin() + j);
        }
      }
		}

    for(int i=0;i<fnpr_texts.size();i++){
      // for each fnpr
      for(int j=0;j<fun_starts.size();j++){
        // decl in st
        if(fnpr_starts[i]>= fun_starts[j] && fnpr_ends[i] <= fun_ends[j]){
          // cout<<decl_texts[i]<<" in "<<st_texts[j]<<endl;
          fnpr_domain_ends[i] = fun_ends[j];
        }
      }
		}

    // cout<<"after remove st_texts.size()"<<st_texts.size()<<endl;
    // for(int i=0;i<fnpr_texts.size();i++){
		// 	cout<<i<<": "<<fnpr_texts[i]<<endl;
    //   cout<<"fnpr_starts: "<<fnpr_starts[i]<<endl;
    //   cout<<"fnpr_ends: "<<fnpr_ends[i]<<endl;
    //   cout<<"fnpr_id_texts: "<<fnpr_id_texts[i]<<endl;
    //   cout<<"fnpr_domain_ends: "<<fnpr_domain_ends[i]<<endl;
		// }
  }

  virtual antlrcpp::Any visitProgram(ECMAScriptParser::ProgramContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    //cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    //cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSourceElements(ECMAScriptParser::SourceElementsContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    //cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    //cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSourceElement(ECMAScriptParser::SourceElementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    //cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ECMAScriptParser::StatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
      return visitChildren(ctx);
    }
    st_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    st_intervals.push_back(ctx->getSourceInterval());
    st_starts.push_back(ctx->start->getStartIndex());
    st_ends.push_back(ctx->stop->getStopIndex());
    // cout<<"start index: "<<ctx->start->getStartIndex()<<", "<<ctx->stop->getStopIndex()<<endl;
    // cout<<"intervals: "<<ctx->getSourceInterval().a<<", "<<ctx->getSourceInterval().b<<endl;
    // cout<<st_texts.back()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(ECMAScriptParser::BlockContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(ECMAScriptParser::StatementListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableStatement(ECMAScriptParser::VariableStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(ECMAScriptParser::VariableDeclarationContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
      return visitChildren(ctx);
    }
    decl_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    decl_starts.push_back(ctx->start->getStartIndex());
    decl_ends.push_back(ctx->stop->getStopIndex());
    decl_id_texts.push_back(ctx->Identifier()->toString());

    // cout<<"ctx->Identifier()->toString() "<<ctx->Identifier()->toString()<<endl;
    // cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    // cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitialiser(ECMAScriptParser::InitialiserContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(ECMAScriptParser::EmptyStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(ECMAScriptParser::ExpressionStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(ECMAScriptParser::IfStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoStatement(ECMAScriptParser::DoStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(ECMAScriptParser::WhileStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(ECMAScriptParser::ForStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForVarStatement(ECMAScriptParser::ForVarStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLetStatement(ECMAScriptParser::ForLetStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForInStatement(ECMAScriptParser::ForInStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForVarInStatement(ECMAScriptParser::ForVarInStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLetInStatement(ECMAScriptParser::ForLetInStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinueStatement(ECMAScriptParser::ContinueStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());

    // cout<<ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex()))<<endl;

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakStatement(ECMAScriptParser::BreakStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());

    // cout<<ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex()))<<endl;

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(ECMAScriptParser::ReturnStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWithStatement(ECMAScriptParser::WithStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStatement(ECMAScriptParser::SwitchStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseBlock(ECMAScriptParser::CaseBlockContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseClauses(ECMAScriptParser::CaseClausesContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseClause(ECMAScriptParser::CaseClauseContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultClause(ECMAScriptParser::DefaultClauseContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelledStatement(ECMAScriptParser::LabelledStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThrowStatement(ECMAScriptParser::ThrowStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTryStatement(ECMAScriptParser::TryStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCatchProduction(ECMAScriptParser::CatchProductionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // cout<<ctx->Identifier()->toString()<<endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinallyProduction(ECMAScriptParser::FinallyProductionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDebuggerStatement(ECMAScriptParser::DebuggerStatementContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    //cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    //cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    // fun_starts.push_back(ctx->start->getStartIndex());
    // fun_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterList(ECMAScriptParser::FormalParameterListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
      return visitChildren(ctx);
    }
    for(int i=0;i<ctx->Identifier().size();i++){
      fnpr_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
      fnpr_starts.push_back(ctx->start->getStartIndex());
      fnpr_ends.push_back(ctx->stop->getStopIndex());
      fnpr_id_texts.push_back(ctx->Identifier()[i]->toString());
      fnpr_domain_ends.push_back(ctx->stop->getStopIndex());
    }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBody(ECMAScriptParser::FunctionBodyContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteral(ECMAScriptParser::ArrayLiteralContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementList(ECMAScriptParser::ElementListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElision(ECMAScriptParser::ElisionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteral(ECMAScriptParser::ObjectLiteralContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyGetter(ECMAScriptParser::PropertyGetterContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertySetter(ECMAScriptParser::PropertySetterContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyName(ECMAScriptParser::PropertyNameContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(ECMAScriptParser::ArgumentsContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentList(ECMAScriptParser::ArgumentListContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionSequence(ECMAScriptParser::ExpressionSequenceContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTernaryExpression(ECMAScriptParser::TernaryExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInExpression(ECMAScriptParser::InExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpression(ECMAScriptParser::NotExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThisExpression(ECMAScriptParser::ThisExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionExpression(ECMAScriptParser::FunctionExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeofExpression(ECMAScriptParser::TypeofExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeleteExpression(ECMAScriptParser::DeleteExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(ECMAScriptParser::EqualityExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalExpression(ECMAScriptParser::RelationalExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitNotExpression(ECMAScriptParser::BitNotExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpression(ECMAScriptParser::NewExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(ECMAScriptParser::LiteralExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());

    // cout<<ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex()))<<endl;
    // cout<<ctx->Identifier()->getSourceInterval().a<<" "<<ctx->Identifier()->getSourceInterval().b<<endl;
    // cout<<ctx->start->getStartIndex()<<" "<<ctx->stop->getStopIndex()<<endl;
    // cout<<"IdentifierExpressionContext->Identifier()->toString() "<<ctx->Identifier()->toString()<<endl;
    
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitAndExpression(ECMAScriptParser::BitAndExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOrExpression(ECMAScriptParser::BitOrExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoidExpression(ECMAScriptParser::VoidExpressionContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    // if(ctx->start->getStartIndex() == 0 && ctx->start->getStartIndex() == 0){
    //   return visitChildren(ctx);
    // }
    // exp_texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // exp_intervals.push_back(ctx->getSourceInterval());
    // exp_starts.push_back(ctx->start->getStartIndex());
    // exp_ends.push_back(ctx->stop->getStopIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(ECMAScriptParser::LiteralContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericLiteral(ECMAScriptParser::NumericLiteralContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierName(ECMAScriptParser::IdentifierNameContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReservedWord(ECMAScriptParser::ReservedWordContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(ECMAScriptParser::KeywordContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFutureReservedWord(ECMAScriptParser::FutureReservedWordContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetter(ECMAScriptParser::GetterContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetter(ECMAScriptParser::SetterContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(ECMAScriptParser::EosContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEof(ECMAScriptParser::EofContext *ctx) override {
    // intervals.push_back(ctx->getSourceInterval());
    // texts.push_back(ctx->start->getInputStream()->getText(misc::Interval(ctx->start->getStartIndex(),ctx->stop->getStopIndex())));
    // rule_index_array.push_back(ctx->getRuleIndex());
    //cout<<"getRuleIndex "<<ctx->getRuleIndex()<<endl;
    //cout<<ctx->start->getText()<<" "<<ctx->start->getType()<<endl;
    return visitChildren(ctx);
  }


};

