/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <string>

#include "parser/MiniJavaParser.h"

#include "ast/node/ASTProgram.h"
#include "ast/node/ASTMainClass.h"
#include "ast/node/ASTClass.h"
#include "ast/node/ASTVar.h"
#include "ast/node/ASTMethod.h"

#include "ast/node/ASTStatement.h"
#include "ast/node/ASTStatementList.h"
#include "ast/node/ASTIf.h"
#include "ast/node/ASTIfElse.h"
#include "ast/node/ASTWhile.h"
#include "ast/node/ASTSout.h"
#include "ast/node/ASTAssign.h"
#include "ast/node/ASTAssignArray.h"

#include "ast/node/ASTExpression.h"
#include "ast/node/ASTExpressionList.h"
#include "ast/node/ASTLiteralBoolean.h"
#include "ast/node/ASTLiteralInteger.h"
#include "ast/node/ASTLiteralString.h"
#include "ast/node/ASTId.h"
#include "ast/node/ASTSuper.h"
#include "ast/node/ASTThis.h"
#include "ast/node/ASTMethodCall.h"
#include "ast/node/ASTNewObject.h"
#include "ast/node/ASTNewIntegerArray.h"
#include "ast/node/ASTAnd.h"
#include "ast/node/ASTOr.h"
#include "ast/node/ASTComp.h"
#include "ast/node/ASTNegation.h"
#include "ast/node/ASTNegative.h"
#include "ast/node/ASTAccessIntegerArray.h"
#include "ast/node/ASTLength.h"
#include "ast/node/ASTArithmetic.h"

class TransformToASTVisitor
{
	public:
		ASTProgram* visitProgram(MiniJavaParser::ProgContext* ctx);

		ASTMainClass* visitMainClass(MiniJavaParser::MainClassContext* ctx);
		ASTClass* visitClass(MiniJavaParser::ClassDeclContext* ctx);

		ASTMethod* visitMethod(MiniJavaParser::MethodDeclContext* ctx);
		ASTMethodType* visitMethodType(MiniJavaParser::MethodTypeContext* ctx);
		ASTMethodParams* visitMethodParams(MiniJavaParser::MethodParamsContext* ctx);
		ASTMethodBody* visitMethodBody(MiniJavaParser::MethodBodyContext* ctx);
		ASTMethodReturn* visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx);
		ASTMethodCall* visitMethodCall(MiniJavaParser::MethodCallContext* ctx);

		ASTVar* visitVar(MiniJavaParser::VarDeclContext* ctx);
		ASTVarAndAtt* visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx);
		ASTVarType* visitVarType(MiniJavaParser::VarTypeContext* ctx);

		ASTStatement* visitStatement(MiniJavaParser::StatementContext* ctx);
		ASTExpression* visitExpression(MiniJavaParser::ExpressionContext* ctx);

		ASTExpressionList* visitExpList(MiniJavaParser::ExpListContext* ctx);
};