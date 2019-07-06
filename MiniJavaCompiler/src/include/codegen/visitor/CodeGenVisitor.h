#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaErrorListener.h"

#include "ast/visitor/ASTBaseVisitor.h"

#include "parser/MiniJavaParser.h"

#include "structure/info/MiniJavaStmtTypeCasting.h"
#include "structure/info/MiniJavaExpTypeCasting.h"

#include "structure/code/AsmFile.hpp"

class CodeGenVisitor : public ASTBaseVisitor
{
private:
	AsmFile* asmFile;

	std::string tmpClassId;
	std::string tmpMethodId;

	void visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl);
	void visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl);

	void visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx, ASTVarAndAtt* varAndAtt);

	void visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl);
	void visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx, ASTMethodReturn* methodReturnDecl);
	void visitMethodCallParams(MiniJavaParser::MethodCallContext* ctx, ASTMethodCall* methodCall);

	void visitStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt);
	antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext* ctx, ASTExpression* exp);
public:
	CodeGenVisitor(ASTProgram* astProgram, ProgramInfo* programInfo)
		: ASTBaseVisitor(astProgram, programInfo)
	{
		this->asmFile = new AsmFile();

		this->tmpClassId = "";
		this->tmpMethodId = "";
	}

	AsmFile* visitProgram(MiniJavaParser::ProgContext* ctx);
};