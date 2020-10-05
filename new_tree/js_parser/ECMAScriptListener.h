
// Generated from ECMAScript.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ECMAScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ECMAScriptParser.
 */
class  ECMAScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ECMAScriptParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ECMAScriptParser::ProgramContext *ctx) = 0;

  virtual void enterSourceElements(ECMAScriptParser::SourceElementsContext *ctx) = 0;
  virtual void exitSourceElements(ECMAScriptParser::SourceElementsContext *ctx) = 0;

  virtual void enterSourceElement(ECMAScriptParser::SourceElementContext *ctx) = 0;
  virtual void exitSourceElement(ECMAScriptParser::SourceElementContext *ctx) = 0;

  virtual void enterStatement(ECMAScriptParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ECMAScriptParser::StatementContext *ctx) = 0;

  virtual void enterBlock(ECMAScriptParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ECMAScriptParser::BlockContext *ctx) = 0;

  virtual void enterStatementList(ECMAScriptParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(ECMAScriptParser::StatementListContext *ctx) = 0;

  virtual void enterVariableStatement(ECMAScriptParser::VariableStatementContext *ctx) = 0;
  virtual void exitVariableStatement(ECMAScriptParser::VariableStatementContext *ctx) = 0;

  virtual void enterVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext *ctx) = 0;
  virtual void exitVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext *ctx) = 0;

  virtual void enterVariableDeclaration(ECMAScriptParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(ECMAScriptParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterInitialiser(ECMAScriptParser::InitialiserContext *ctx) = 0;
  virtual void exitInitialiser(ECMAScriptParser::InitialiserContext *ctx) = 0;

  virtual void enterEmptyStatement(ECMAScriptParser::EmptyStatementContext *ctx) = 0;
  virtual void exitEmptyStatement(ECMAScriptParser::EmptyStatementContext *ctx) = 0;

  virtual void enterExpressionStatement(ECMAScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(ECMAScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterIfStatement(ECMAScriptParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(ECMAScriptParser::IfStatementContext *ctx) = 0;

  virtual void enterDoStatement(ECMAScriptParser::DoStatementContext *ctx) = 0;
  virtual void exitDoStatement(ECMAScriptParser::DoStatementContext *ctx) = 0;

  virtual void enterWhileStatement(ECMAScriptParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(ECMAScriptParser::WhileStatementContext *ctx) = 0;

  virtual void enterForStatement(ECMAScriptParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(ECMAScriptParser::ForStatementContext *ctx) = 0;

  virtual void enterForVarStatement(ECMAScriptParser::ForVarStatementContext *ctx) = 0;
  virtual void exitForVarStatement(ECMAScriptParser::ForVarStatementContext *ctx) = 0;

  virtual void enterForLetStatement(ECMAScriptParser::ForLetStatementContext *ctx) = 0;
  virtual void exitForLetStatement(ECMAScriptParser::ForLetStatementContext *ctx) = 0;

  virtual void enterForInStatement(ECMAScriptParser::ForInStatementContext *ctx) = 0;
  virtual void exitForInStatement(ECMAScriptParser::ForInStatementContext *ctx) = 0;

  virtual void enterForVarInStatement(ECMAScriptParser::ForVarInStatementContext *ctx) = 0;
  virtual void exitForVarInStatement(ECMAScriptParser::ForVarInStatementContext *ctx) = 0;

  virtual void enterForLetInStatement(ECMAScriptParser::ForLetInStatementContext *ctx) = 0;
  virtual void exitForLetInStatement(ECMAScriptParser::ForLetInStatementContext *ctx) = 0;

  virtual void enterContinueStatement(ECMAScriptParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(ECMAScriptParser::ContinueStatementContext *ctx) = 0;

  virtual void enterBreakStatement(ECMAScriptParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(ECMAScriptParser::BreakStatementContext *ctx) = 0;

  virtual void enterReturnStatement(ECMAScriptParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(ECMAScriptParser::ReturnStatementContext *ctx) = 0;

  virtual void enterWithStatement(ECMAScriptParser::WithStatementContext *ctx) = 0;
  virtual void exitWithStatement(ECMAScriptParser::WithStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(ECMAScriptParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(ECMAScriptParser::SwitchStatementContext *ctx) = 0;

  virtual void enterCaseBlock(ECMAScriptParser::CaseBlockContext *ctx) = 0;
  virtual void exitCaseBlock(ECMAScriptParser::CaseBlockContext *ctx) = 0;

  virtual void enterCaseClauses(ECMAScriptParser::CaseClausesContext *ctx) = 0;
  virtual void exitCaseClauses(ECMAScriptParser::CaseClausesContext *ctx) = 0;

  virtual void enterCaseClause(ECMAScriptParser::CaseClauseContext *ctx) = 0;
  virtual void exitCaseClause(ECMAScriptParser::CaseClauseContext *ctx) = 0;

  virtual void enterDefaultClause(ECMAScriptParser::DefaultClauseContext *ctx) = 0;
  virtual void exitDefaultClause(ECMAScriptParser::DefaultClauseContext *ctx) = 0;

  virtual void enterLabelledStatement(ECMAScriptParser::LabelledStatementContext *ctx) = 0;
  virtual void exitLabelledStatement(ECMAScriptParser::LabelledStatementContext *ctx) = 0;

  virtual void enterThrowStatement(ECMAScriptParser::ThrowStatementContext *ctx) = 0;
  virtual void exitThrowStatement(ECMAScriptParser::ThrowStatementContext *ctx) = 0;

  virtual void enterTryStatement(ECMAScriptParser::TryStatementContext *ctx) = 0;
  virtual void exitTryStatement(ECMAScriptParser::TryStatementContext *ctx) = 0;

  virtual void enterCatchProduction(ECMAScriptParser::CatchProductionContext *ctx) = 0;
  virtual void exitCatchProduction(ECMAScriptParser::CatchProductionContext *ctx) = 0;

  virtual void enterFinallyProduction(ECMAScriptParser::FinallyProductionContext *ctx) = 0;
  virtual void exitFinallyProduction(ECMAScriptParser::FinallyProductionContext *ctx) = 0;

  virtual void enterDebuggerStatement(ECMAScriptParser::DebuggerStatementContext *ctx) = 0;
  virtual void exitDebuggerStatement(ECMAScriptParser::DebuggerStatementContext *ctx) = 0;

  virtual void enterFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterFormalParameterList(ECMAScriptParser::FormalParameterListContext *ctx) = 0;
  virtual void exitFormalParameterList(ECMAScriptParser::FormalParameterListContext *ctx) = 0;

  virtual void enterFunctionBody(ECMAScriptParser::FunctionBodyContext *ctx) = 0;
  virtual void exitFunctionBody(ECMAScriptParser::FunctionBodyContext *ctx) = 0;

  virtual void enterArrayLiteral(ECMAScriptParser::ArrayLiteralContext *ctx) = 0;
  virtual void exitArrayLiteral(ECMAScriptParser::ArrayLiteralContext *ctx) = 0;

  virtual void enterElementList(ECMAScriptParser::ElementListContext *ctx) = 0;
  virtual void exitElementList(ECMAScriptParser::ElementListContext *ctx) = 0;

  virtual void enterElision(ECMAScriptParser::ElisionContext *ctx) = 0;
  virtual void exitElision(ECMAScriptParser::ElisionContext *ctx) = 0;

  virtual void enterObjectLiteral(ECMAScriptParser::ObjectLiteralContext *ctx) = 0;
  virtual void exitObjectLiteral(ECMAScriptParser::ObjectLiteralContext *ctx) = 0;

  virtual void enterPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext *ctx) = 0;
  virtual void exitPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext *ctx) = 0;

  virtual void enterPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext *ctx) = 0;
  virtual void exitPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext *ctx) = 0;

  virtual void enterPropertyGetter(ECMAScriptParser::PropertyGetterContext *ctx) = 0;
  virtual void exitPropertyGetter(ECMAScriptParser::PropertyGetterContext *ctx) = 0;

  virtual void enterPropertySetter(ECMAScriptParser::PropertySetterContext *ctx) = 0;
  virtual void exitPropertySetter(ECMAScriptParser::PropertySetterContext *ctx) = 0;

  virtual void enterPropertyName(ECMAScriptParser::PropertyNameContext *ctx) = 0;
  virtual void exitPropertyName(ECMAScriptParser::PropertyNameContext *ctx) = 0;

  virtual void enterPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext *ctx) = 0;
  virtual void exitPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext *ctx) = 0;

  virtual void enterArguments(ECMAScriptParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(ECMAScriptParser::ArgumentsContext *ctx) = 0;

  virtual void enterArgumentList(ECMAScriptParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(ECMAScriptParser::ArgumentListContext *ctx) = 0;

  virtual void enterExpressionSequence(ECMAScriptParser::ExpressionSequenceContext *ctx) = 0;
  virtual void exitExpressionSequence(ECMAScriptParser::ExpressionSequenceContext *ctx) = 0;

  virtual void enterTernaryExpression(ECMAScriptParser::TernaryExpressionContext *ctx) = 0;
  virtual void exitTernaryExpression(ECMAScriptParser::TernaryExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext *ctx) = 0;
  virtual void exitPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext *ctx) = 0;

  virtual void enterObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext *ctx) = 0;
  virtual void exitObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext *ctx) = 0;

  virtual void enterInExpression(ECMAScriptParser::InExpressionContext *ctx) = 0;
  virtual void exitInExpression(ECMAScriptParser::InExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterNotExpression(ECMAScriptParser::NotExpressionContext *ctx) = 0;
  virtual void exitNotExpression(ECMAScriptParser::NotExpressionContext *ctx) = 0;

  virtual void enterPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext *ctx) = 0;
  virtual void exitPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext *ctx) = 0;

  virtual void enterArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext *ctx) = 0;
  virtual void exitArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext *ctx) = 0;

  virtual void enterThisExpression(ECMAScriptParser::ThisExpressionContext *ctx) = 0;
  virtual void exitThisExpression(ECMAScriptParser::ThisExpressionContext *ctx) = 0;

  virtual void enterFunctionExpression(ECMAScriptParser::FunctionExpressionContext *ctx) = 0;
  virtual void exitFunctionExpression(ECMAScriptParser::FunctionExpressionContext *ctx) = 0;

  virtual void enterUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext *ctx) = 0;
  virtual void exitUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext *ctx) = 0;
  virtual void exitPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext *ctx) = 0;

  virtual void enterTypeofExpression(ECMAScriptParser::TypeofExpressionContext *ctx) = 0;
  virtual void exitTypeofExpression(ECMAScriptParser::TypeofExpressionContext *ctx) = 0;

  virtual void enterInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext *ctx) = 0;
  virtual void exitInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext *ctx) = 0;

  virtual void enterUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext *ctx) = 0;
  virtual void exitUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext *ctx) = 0;

  virtual void enterDeleteExpression(ECMAScriptParser::DeleteExpressionContext *ctx) = 0;
  virtual void exitDeleteExpression(ECMAScriptParser::DeleteExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(ECMAScriptParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(ECMAScriptParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext *ctx) = 0;
  virtual void exitBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext *ctx) = 0;
  virtual void exitBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext *ctx) = 0;

  virtual void enterParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext *ctx) = 0;
  virtual void exitParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(ECMAScriptParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(ECMAScriptParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext *ctx) = 0;
  virtual void exitPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext *ctx) = 0;

  virtual void enterBitNotExpression(ECMAScriptParser::BitNotExpressionContext *ctx) = 0;
  virtual void exitBitNotExpression(ECMAScriptParser::BitNotExpressionContext *ctx) = 0;

  virtual void enterNewExpression(ECMAScriptParser::NewExpressionContext *ctx) = 0;
  virtual void exitNewExpression(ECMAScriptParser::NewExpressionContext *ctx) = 0;

  virtual void enterLiteralExpression(ECMAScriptParser::LiteralExpressionContext *ctx) = 0;
  virtual void exitLiteralExpression(ECMAScriptParser::LiteralExpressionContext *ctx) = 0;

  virtual void enterArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext *ctx) = 0;
  virtual void exitArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext *ctx) = 0;

  virtual void enterMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext *ctx) = 0;
  virtual void exitMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext *ctx) = 0;

  virtual void enterMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext *ctx) = 0;
  virtual void exitMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext *ctx) = 0;

  virtual void enterIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext *ctx) = 0;
  virtual void exitIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext *ctx) = 0;

  virtual void enterBitAndExpression(ECMAScriptParser::BitAndExpressionContext *ctx) = 0;
  virtual void exitBitAndExpression(ECMAScriptParser::BitAndExpressionContext *ctx) = 0;

  virtual void enterBitOrExpression(ECMAScriptParser::BitOrExpressionContext *ctx) = 0;
  virtual void exitBitOrExpression(ECMAScriptParser::BitOrExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext *ctx) = 0;
  virtual void exitAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext *ctx) = 0;

  virtual void enterVoidExpression(ECMAScriptParser::VoidExpressionContext *ctx) = 0;
  virtual void exitVoidExpression(ECMAScriptParser::VoidExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterLiteral(ECMAScriptParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(ECMAScriptParser::LiteralContext *ctx) = 0;

  virtual void enterNumericLiteral(ECMAScriptParser::NumericLiteralContext *ctx) = 0;
  virtual void exitNumericLiteral(ECMAScriptParser::NumericLiteralContext *ctx) = 0;

  virtual void enterIdentifierName(ECMAScriptParser::IdentifierNameContext *ctx) = 0;
  virtual void exitIdentifierName(ECMAScriptParser::IdentifierNameContext *ctx) = 0;

  virtual void enterReservedWord(ECMAScriptParser::ReservedWordContext *ctx) = 0;
  virtual void exitReservedWord(ECMAScriptParser::ReservedWordContext *ctx) = 0;

  virtual void enterKeyword(ECMAScriptParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(ECMAScriptParser::KeywordContext *ctx) = 0;

  virtual void enterFutureReservedWord(ECMAScriptParser::FutureReservedWordContext *ctx) = 0;
  virtual void exitFutureReservedWord(ECMAScriptParser::FutureReservedWordContext *ctx) = 0;

  virtual void enterGetter(ECMAScriptParser::GetterContext *ctx) = 0;
  virtual void exitGetter(ECMAScriptParser::GetterContext *ctx) = 0;

  virtual void enterSetter(ECMAScriptParser::SetterContext *ctx) = 0;
  virtual void exitSetter(ECMAScriptParser::SetterContext *ctx) = 0;

  virtual void enterEos(ECMAScriptParser::EosContext *ctx) = 0;
  virtual void exitEos(ECMAScriptParser::EosContext *ctx) = 0;

  virtual void enterEof(ECMAScriptParser::EofContext *ctx) = 0;
  virtual void exitEof(ECMAScriptParser::EofContext *ctx) = 0;


};

