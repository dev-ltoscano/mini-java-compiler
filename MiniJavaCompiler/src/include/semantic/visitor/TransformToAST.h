#pragma once

#include <iostream>
#include <string>

#include "parser/MiniJavaParser.h"

#include "ast/node/ASTProgram.h"
#include "ast/node/ASTMainClass.h"
#include "ast/node/ASTClass.h"
#include "ast/node/ASTVar.h"
#include "ast/node/ASTMethod.h"

#include "ast/node/ASTStatement.h"
#include "ast/node/ASTStatementList.h"
#include "ast/node/ASTExpression.h"
#include "ast/node/ASTSout.h"
#include "ast/node/ASTLiteralBoolean.h"
#include "ast/node/ASTLiteralInteger.h"
#include "ast/node/ASTId.h"
#include "ast/node/ASTIf.h"
#include "ast/node/ASTIfElse.h"
#include "ast/node/ASTWhile.h"
#include "ast/node/ASTAssign.h"
#include "ast/node/ASTAssignArray.h"

//virtual antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext* context) = 0;
//virtual antlrcpp::Any visitExpList(MiniJavaParser::ExpListContext* context) = 0;

class TransformToAST
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

		ASTVar* visitVar(MiniJavaParser::VarDeclContext* ctx);
		ASTVarAndAtt* visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx);
		ASTVarType* visitVarType(MiniJavaParser::VarTypeContext* ctx);

		ASTStatement* visitStatement(MiniJavaParser::StatementContext* ctx);
		ASTExpression* visitExpression(MiniJavaParser::ExpressionContext* ctx);
};