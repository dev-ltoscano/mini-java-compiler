#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaErrorListener.h"
#include "exception/MiniJavaCompilerException.h"

#include "parser/MiniJavaParser.h"

#include "ast/node/ASTProgram.h"

#include "structure/info/ProgramInfo.h"

class DeclarationVisitor
{
	private:
		MiniJavaErrorListener* errorListener;
		ProgramInfo* programInfo;

		std::string tmpClassId;
		std::string tmpMethodId;
	public:
		DeclarationVisitor(MiniJavaErrorListener* errorListener)
		{
			this->errorListener = errorListener;
			this->programInfo = new ProgramInfo();
		}

		MiniJavaError getError(ParserRuleContext* ctx, std::string msg)
		{
			antlr4::Token* firstToken = ctx->getStart();

			size_t errorLine = firstToken->getLine();
			size_t errorCollumn = firstToken->getCharPositionInLine();

			return MiniJavaError(errorLine, errorCollumn, msg);
		}

		ProgramInfo* visitProgram(MiniJavaParser::ProgContext* ctx, ASTProgram* program);

		void visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl);
		void visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl);

		void visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl);

		VarInfo* visitVar(ASTVar* varDecl);
		VarInfo* visitVarAndAtt(ASTVarAndAtt* varAtt);
};