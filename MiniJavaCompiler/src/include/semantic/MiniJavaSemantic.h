#pragma once

#include "exception/MiniJavaErrorListener.h"
#include "parser/MiniJavaParser.h"

#include "visitor/TransformToAST.h"
#include "visitor/DeclarationVisitor.h"

#include "visitor/CollectInformation.h"
#include "visitor/ExpressionChecker.h"

class MiniJavaSemantic
{
	private:
		MiniJavaErrorListener errorListener;
	public:
		void analyze(MiniJavaParser::ProgContext* progCtx);

		bool hasErrors();
		void printErrorList();
};