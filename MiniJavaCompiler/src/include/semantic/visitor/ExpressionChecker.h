#pragma once

#include <string>

#include "parser/visitor/MiniJavaBaseVisitor.h"
#include "exception/MiniJavaErrorListener.h"
#include "parser/MiniJavaParser.h"
#include "structure/info/ProgramInfo.h"

class ExpressionChecker : public MiniJavaBaseVisitor
{
	public:
		ExpressionChecker(ProgramInfo *programInfo, MiniJavaErrorListener* errorListener) : MiniJavaBaseVisitor(errorListener) 
		{
			this->programInfo = programInfo;
		};

		antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx);
		antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext* ctx);
		antlrcpp::Any visitMethodCall(string classId, MiniJavaParser::MethodCallContext* ctx);
		antlrcpp::Any visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx);
		antlrcpp::Any visitStatement(MiniJavaParser::StatementContext* ctx);
		antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext* ctx);
};