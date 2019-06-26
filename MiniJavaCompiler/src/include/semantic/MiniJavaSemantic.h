/*
*	Jefferson do Nascimento Amar� (201765125C)
*	Luis Augusto Toscano Guimar�es (201365165AC)
*/

#pragma once

#include "exception/MiniJavaErrorListener.h"

#include "parser/MiniJavaParser.h"

#include "visitor/TransformToASTVisitor.h"
#include "visitor/DeclarationVisitor.h"
#include "visitor/ExpressionVisitor.h"

class MiniJavaSemantic
{
	private:
		MiniJavaErrorListener errorListener;
	public:
		void analyze(MiniJavaParser::ProgContext* progCtx);

		bool hasErrors();
		void printErrorList();
};