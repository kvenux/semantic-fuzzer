
// Generated from ECMAScript.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ECMAScriptListener.h"


/**
 * This class provides an empty implementation of ECMAScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ECMAScriptBaseListener : public ECMAScriptListener {
public:

  virtual void enterProgram(ECMAScriptParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ECMAScriptParser::ProgramContext * /*ctx*/) override { }

  virtual void enterSourceElements(ECMAScriptParser::SourceElementsContext * /*ctx*/) override { }
  virtual void exitSourceElements(ECMAScriptParser::SourceElementsContext * /*ctx*/) override { }

  virtual void enterSourceElement(ECMAScriptParser::SourceElementContext * /*ctx*/) override { }
  virtual void exitSourceElement(ECMAScriptParser::SourceElementContext * /*ctx*/) override { }

  virtual void enterStatement(ECMAScriptParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ECMAScriptParser::StatementContext * /*ctx*/) override { }

  virtual void enterBlock(ECMAScriptParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ECMAScriptParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatementList(ECMAScriptParser::StatementListContext * /*ctx*/) override { }
  virtual void exitStatementList(ECMAScriptParser::StatementListContext * /*ctx*/) override { }

  virtual void enterVariableStatement(ECMAScriptParser::VariableStatementContext * /*ctx*/) override { }
  virtual void exitVariableStatement(ECMAScriptParser::VariableStatementContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(ECMAScriptParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(ECMAScriptParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterInitialiser(ECMAScriptParser::InitialiserContext * /*ctx*/) override { }
  virtual void exitInitialiser(ECMAScriptParser::InitialiserContext * /*ctx*/) override { }

  virtual void enterEmptyStatement(ECMAScriptParser::EmptyStatementContext * /*ctx*/) override { }
  virtual void exitEmptyStatement(ECMAScriptParser::EmptyStatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(ECMAScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(ECMAScriptParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(ECMAScriptParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(ECMAScriptParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterDoStatement(ECMAScriptParser::DoStatementContext * /*ctx*/) override { }
  virtual void exitDoStatement(ECMAScriptParser::DoStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(ECMAScriptParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(ECMAScriptParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(ECMAScriptParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(ECMAScriptParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForVarStatement(ECMAScriptParser::ForVarStatementContext * /*ctx*/) override { }
  virtual void exitForVarStatement(ECMAScriptParser::ForVarStatementContext * /*ctx*/) override { }

  virtual void enterForLetStatement(ECMAScriptParser::ForLetStatementContext * /*ctx*/) override { }
  virtual void exitForLetStatement(ECMAScriptParser::ForLetStatementContext * /*ctx*/) override { }

  virtual void enterForInStatement(ECMAScriptParser::ForInStatementContext * /*ctx*/) override { }
  virtual void exitForInStatement(ECMAScriptParser::ForInStatementContext * /*ctx*/) override { }

  virtual void enterForVarInStatement(ECMAScriptParser::ForVarInStatementContext * /*ctx*/) override { }
  virtual void exitForVarInStatement(ECMAScriptParser::ForVarInStatementContext * /*ctx*/) override { }

  virtual void enterForLetInStatement(ECMAScriptParser::ForLetInStatementContext * /*ctx*/) override { }
  virtual void exitForLetInStatement(ECMAScriptParser::ForLetInStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(ECMAScriptParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(ECMAScriptParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(ECMAScriptParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(ECMAScriptParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(ECMAScriptParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(ECMAScriptParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterWithStatement(ECMAScriptParser::WithStatementContext * /*ctx*/) override { }
  virtual void exitWithStatement(ECMAScriptParser::WithStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(ECMAScriptParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(ECMAScriptParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterCaseBlock(ECMAScriptParser::CaseBlockContext * /*ctx*/) override { }
  virtual void exitCaseBlock(ECMAScriptParser::CaseBlockContext * /*ctx*/) override { }

  virtual void enterCaseClauses(ECMAScriptParser::CaseClausesContext * /*ctx*/) override { }
  virtual void exitCaseClauses(ECMAScriptParser::CaseClausesContext * /*ctx*/) override { }

  virtual void enterCaseClause(ECMAScriptParser::CaseClauseContext * /*ctx*/) override { }
  virtual void exitCaseClause(ECMAScriptParser::CaseClauseContext * /*ctx*/) override { }

  virtual void enterDefaultClause(ECMAScriptParser::DefaultClauseContext * /*ctx*/) override { }
  virtual void exitDefaultClause(ECMAScriptParser::DefaultClauseContext * /*ctx*/) override { }

  virtual void enterLabelledStatement(ECMAScriptParser::LabelledStatementContext * /*ctx*/) override { }
  virtual void exitLabelledStatement(ECMAScriptParser::LabelledStatementContext * /*ctx*/) override { }

  virtual void enterThrowStatement(ECMAScriptParser::ThrowStatementContext * /*ctx*/) override { }
  virtual void exitThrowStatement(ECMAScriptParser::ThrowStatementContext * /*ctx*/) override { }

  virtual void enterTryStatement(ECMAScriptParser::TryStatementContext * /*ctx*/) override { }
  virtual void exitTryStatement(ECMAScriptParser::TryStatementContext * /*ctx*/) override { }

  virtual void enterCatchProduction(ECMAScriptParser::CatchProductionContext * /*ctx*/) override { }
  virtual void exitCatchProduction(ECMAScriptParser::CatchProductionContext * /*ctx*/) override { }

  virtual void enterFinallyProduction(ECMAScriptParser::FinallyProductionContext * /*ctx*/) override { }
  virtual void exitFinallyProduction(ECMAScriptParser::FinallyProductionContext * /*ctx*/) override { }

  virtual void enterDebuggerStatement(ECMAScriptParser::DebuggerStatementContext * /*ctx*/) override { }
  virtual void exitDebuggerStatement(ECMAScriptParser::DebuggerStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterFormalParameterList(ECMAScriptParser::FormalParameterListContext * /*ctx*/) override { }
  virtual void exitFormalParameterList(ECMAScriptParser::FormalParameterListContext * /*ctx*/) override { }

  virtual void enterFunctionBody(ECMAScriptParser::FunctionBodyContext * /*ctx*/) override { }
  virtual void exitFunctionBody(ECMAScriptParser::FunctionBodyContext * /*ctx*/) override { }

  virtual void enterArrayLiteral(ECMAScriptParser::ArrayLiteralContext * /*ctx*/) override { }
  virtual void exitArrayLiteral(ECMAScriptParser::ArrayLiteralContext * /*ctx*/) override { }

  virtual void enterElementList(ECMAScriptParser::ElementListContext * /*ctx*/) override { }
  virtual void exitElementList(ECMAScriptParser::ElementListContext * /*ctx*/) override { }

  virtual void enterElision(ECMAScriptParser::ElisionContext * /*ctx*/) override { }
  virtual void exitElision(ECMAScriptParser::ElisionContext * /*ctx*/) override { }

  virtual void enterObjectLiteral(ECMAScriptParser::ObjectLiteralContext * /*ctx*/) override { }
  virtual void exitObjectLiteral(ECMAScriptParser::ObjectLiteralContext * /*ctx*/) override { }

  virtual void enterPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext * /*ctx*/) override { }
  virtual void exitPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext * /*ctx*/) override { }

  virtual void enterPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext * /*ctx*/) override { }
  virtual void exitPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext * /*ctx*/) override { }

  virtual void enterPropertyGetter(ECMAScriptParser::PropertyGetterContext * /*ctx*/) override { }
  virtual void exitPropertyGetter(ECMAScriptParser::PropertyGetterContext * /*ctx*/) override { }

  virtual void enterPropertySetter(ECMAScriptParser::PropertySetterContext * /*ctx*/) override { }
  virtual void exitPropertySetter(ECMAScriptParser::PropertySetterContext * /*ctx*/) override { }

  virtual void enterPropertyName(ECMAScriptParser::PropertyNameContext * /*ctx*/) override { }
  virtual void exitPropertyName(ECMAScriptParser::PropertyNameContext * /*ctx*/) override { }

  virtual void enterPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext * /*ctx*/) override { }
  virtual void exitPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext * /*ctx*/) override { }

  virtual void enterArguments(ECMAScriptParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(ECMAScriptParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArgumentList(ECMAScriptParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(ECMAScriptParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterExpressionSequence(ECMAScriptParser::ExpressionSequenceContext * /*ctx*/) override { }
  virtual void exitExpressionSequence(ECMAScriptParser::ExpressionSequenceContext * /*ctx*/) override { }

  virtual void enterTernaryExpression(ECMAScriptParser::TernaryExpressionContext * /*ctx*/) override { }
  virtual void exitTernaryExpression(ECMAScriptParser::TernaryExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext * /*ctx*/) override { }
  virtual void exitPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext * /*ctx*/) override { }

  virtual void enterObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterInExpression(ECMAScriptParser::InExpressionContext * /*ctx*/) override { }
  virtual void exitInExpression(ECMAScriptParser::InExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterNotExpression(ECMAScriptParser::NotExpressionContext * /*ctx*/) override { }
  virtual void exitNotExpression(ECMAScriptParser::NotExpressionContext * /*ctx*/) override { }

  virtual void enterPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext * /*ctx*/) override { }
  virtual void exitPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext * /*ctx*/) override { }

  virtual void enterArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext * /*ctx*/) override { }
  virtual void exitArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext * /*ctx*/) override { }

  virtual void enterThisExpression(ECMAScriptParser::ThisExpressionContext * /*ctx*/) override { }
  virtual void exitThisExpression(ECMAScriptParser::ThisExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionExpression(ECMAScriptParser::FunctionExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionExpression(ECMAScriptParser::FunctionExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext * /*ctx*/) override { }
  virtual void exitPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext * /*ctx*/) override { }

  virtual void enterTypeofExpression(ECMAScriptParser::TypeofExpressionContext * /*ctx*/) override { }
  virtual void exitTypeofExpression(ECMAScriptParser::TypeofExpressionContext * /*ctx*/) override { }

  virtual void enterInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext * /*ctx*/) override { }
  virtual void exitInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext * /*ctx*/) override { }

  virtual void enterDeleteExpression(ECMAScriptParser::DeleteExpressionContext * /*ctx*/) override { }
  virtual void exitDeleteExpression(ECMAScriptParser::DeleteExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(ECMAScriptParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(ECMAScriptParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext * /*ctx*/) override { }
  virtual void exitBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext * /*ctx*/) override { }
  virtual void exitBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext * /*ctx*/) override { }

  virtual void enterParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext * /*ctx*/) override { }
  virtual void exitParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(ECMAScriptParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(ECMAScriptParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext * /*ctx*/) override { }
  virtual void exitPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext * /*ctx*/) override { }

  virtual void enterBitNotExpression(ECMAScriptParser::BitNotExpressionContext * /*ctx*/) override { }
  virtual void exitBitNotExpression(ECMAScriptParser::BitNotExpressionContext * /*ctx*/) override { }

  virtual void enterNewExpression(ECMAScriptParser::NewExpressionContext * /*ctx*/) override { }
  virtual void exitNewExpression(ECMAScriptParser::NewExpressionContext * /*ctx*/) override { }

  virtual void enterLiteralExpression(ECMAScriptParser::LiteralExpressionContext * /*ctx*/) override { }
  virtual void exitLiteralExpression(ECMAScriptParser::LiteralExpressionContext * /*ctx*/) override { }

  virtual void enterArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext * /*ctx*/) override { }
  virtual void exitMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext * /*ctx*/) override { }

  virtual void enterMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext * /*ctx*/) override { }
  virtual void exitMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext * /*ctx*/) override { }
  virtual void exitIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext * /*ctx*/) override { }

  virtual void enterBitAndExpression(ECMAScriptParser::BitAndExpressionContext * /*ctx*/) override { }
  virtual void exitBitAndExpression(ECMAScriptParser::BitAndExpressionContext * /*ctx*/) override { }

  virtual void enterBitOrExpression(ECMAScriptParser::BitOrExpressionContext * /*ctx*/) override { }
  virtual void exitBitOrExpression(ECMAScriptParser::BitOrExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext * /*ctx*/) override { }

  virtual void enterVoidExpression(ECMAScriptParser::VoidExpressionContext * /*ctx*/) override { }
  virtual void exitVoidExpression(ECMAScriptParser::VoidExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterLiteral(ECMAScriptParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(ECMAScriptParser::LiteralContext * /*ctx*/) override { }

  virtual void enterNumericLiteral(ECMAScriptParser::NumericLiteralContext * /*ctx*/) override { }
  virtual void exitNumericLiteral(ECMAScriptParser::NumericLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifierName(ECMAScriptParser::IdentifierNameContext * /*ctx*/) override { }
  virtual void exitIdentifierName(ECMAScriptParser::IdentifierNameContext * /*ctx*/) override { }

  virtual void enterReservedWord(ECMAScriptParser::ReservedWordContext * /*ctx*/) override { }
  virtual void exitReservedWord(ECMAScriptParser::ReservedWordContext * /*ctx*/) override { }

  virtual void enterKeyword(ECMAScriptParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(ECMAScriptParser::KeywordContext * /*ctx*/) override { }

  virtual void enterFutureReservedWord(ECMAScriptParser::FutureReservedWordContext * /*ctx*/) override { }
  virtual void exitFutureReservedWord(ECMAScriptParser::FutureReservedWordContext * /*ctx*/) override { }

  virtual void enterGetter(ECMAScriptParser::GetterContext * /*ctx*/) override { }
  virtual void exitGetter(ECMAScriptParser::GetterContext * /*ctx*/) override { }

  virtual void enterSetter(ECMAScriptParser::SetterContext * /*ctx*/) override { }
  virtual void exitSetter(ECMAScriptParser::SetterContext * /*ctx*/) override { }

  virtual void enterEos(ECMAScriptParser::EosContext * /*ctx*/) override { }
  virtual void exitEos(ECMAScriptParser::EosContext * /*ctx*/) override { }

  virtual void enterEof(ECMAScriptParser::EofContext * /*ctx*/) override { }
  virtual void exitEof(ECMAScriptParser::EofContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

