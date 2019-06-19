#pragma once

#include <string>
#include <vector>

#include "parser/visitor/MiniJavaBaseVisitor.h"
#include "exception/MiniJavaErrorListener.h"
#include "parser/MiniJavaParser.h"
#include "structure/info/ProgramInfo.h"

class CollectInformation : public MiniJavaBaseVisitor
{
	public:
		CollectInformation(MiniJavaErrorListener* errorListener) : MiniJavaBaseVisitor(errorListener)
		{
			this->programInfo = new ProgramInfo();
		};

		antlrcpp::Any visitMainClass(MiniJavaParser::MainClassContext* ctx);
		antlrcpp::Any visitClassDecl(MiniJavaParser::ClassDeclContext* ctx);

		antlrcpp::Any visitVarDecl(MiniJavaParser::VarDeclContext* ctx);
		antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx);

		antlrcpp::Any visitMethodDecl(MiniJavaParser::MethodDeclContext* ctx);
		antlrcpp::Any visitMethodParams(MiniJavaParser::MethodParamsContext* ctx);
};