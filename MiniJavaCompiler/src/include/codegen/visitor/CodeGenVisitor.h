#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaErrorListener.h"

#include "ast/visitor/ASTBaseVisitor.h"

#include "structure/info/MiniJavaStmtTypeCasting.h"
#include "structure/info/MiniJavaExpTypeCasting.h"

#include "structure/code/AsmFile.hpp"
#include "structure/code/AsmCodeGen.hpp"

class CodeGenVisitor : public ASTBaseVisitor
{
private:
	AsmFile* asmFile;

	std::string tmpClassId;
	std::string tmpMethodId;

	int tmpId;

	void visitMainClass(ASTMainClass* mainClassDecl);
	void visitClass(ASTClass* classDecl);

	void visitVar(ASTVar* var);
	void visitVarAndAtt(ASTVarAndAtt* varAndAtt);

	void visitMethod(ASTMethod* methodDecl);
	void visitMethodReturn(ASTMethodReturn* methodReturnDecl);
	void visitMethodCallParams(ASTMethodCall* methodCall);

	void visitStatement(ASTStatement* stmt);
	void visitExpression(ASTExpression* exp);
public:
	CodeGenVisitor(ASTProgram* astProgram, ProgramInfo* programInfo)
		: ASTBaseVisitor(astProgram, programInfo)
	{
		this->asmFile = new AsmFile();

		this->tmpClassId = "";
		this->tmpMethodId = "";

		this->tmpId = 0;
	}

	AsmFile* visitProgram();
};