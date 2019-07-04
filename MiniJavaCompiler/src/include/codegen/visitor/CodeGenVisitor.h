#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaErrorListener.h"

#include "ast/visitor/ASTBaseVisitor.h"

#include "parser/MiniJavaParser.h"

#include "structure/info/MiniJavaStmtTypeCasting.h"
#include "structure/info/MiniJavaExpTypeCasting.h"

class CodeGenVisitor : public ASTBaseVisitor
{
private:
	vector<std::string> asmCode;
	ASTProgram* astProgram;
	ProgramInfo* programInfo;

	void visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl);
	void visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl);

	void visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx, ASTVarAndAtt* varAndAtt);

	void visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl);
	void visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx, ASTMethodReturn* methodReturnDecl);
	void visitMethodCallParams(MiniJavaParser::MethodCallContext* ctx, ASTMethodCall* methodCall);

	void visitStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt);
	antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext* ctx, ASTExpression* exp);
public:
	CodeGenVisitor(MiniJavaErrorListener* errorListener, ASTProgram* astProgram, ProgramInfo* programInfo)
		: ASTBaseVisitor(errorListener, program, programInfo) 
	{
		this->astProgram = astProgram;
		this->programInfo = programInfo;
	}

	vector<std::string> visitProgram(MiniJavaParser::ProgContext* ctx);
};