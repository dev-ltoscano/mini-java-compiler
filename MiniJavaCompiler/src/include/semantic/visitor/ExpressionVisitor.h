#pragma once

#include "ast/visitor/ASTBaseVisitor.h"

#include "parser/MiniJavaParser.h"

#include "structure/info/MiniJavaStmtTypeCasting.h"
#include "structure/info/MiniJavaExpTypeCasting.h"

class ExpressionVisitor : public ASTBaseVisitor
{
	private:
		MiniJavaParser::ExpressionContext* tmpExpCtx;

		void visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl);
		void visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl);

		void visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx, ASTVarAndAtt* varAndAtt);

		void visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl);
		void visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx, ASTMethodReturn* methodReturnDecl);
		void visitMethodCallParams(MiniJavaParser::MethodCallContext* ctx, ASTMethodCall* methodCall);

		void visitStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt);
		string visitExpression(MiniJavaParser::ExpressionContext* ctx, ASTExpression* exp);

		bool checkCircularHierarchy(std::string subType);
		bool isSubType(std::string superType, std::string subType);
	public:
		ExpressionVisitor(MiniJavaErrorListener* errorListener, ASTProgram* program, ProgramInfo* programInfo)
			: ASTBaseVisitor(errorListener, program, programInfo)
		{
			this->tmpExpCtx = nullptr;
		}

		void visitProgram(MiniJavaParser::ProgContext* ctx);
};