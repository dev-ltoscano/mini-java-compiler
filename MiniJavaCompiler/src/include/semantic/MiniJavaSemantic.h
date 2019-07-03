/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include "exception/MiniJavaErrorListener.h"

#include "parser/MiniJavaParser.h"

#include "visitor/TransformToASTVisitor.h"
#include "visitor/DeclarationVisitor.h"
#include "visitor/ExpressionVisitor.h"

#include "structure/code/CodeStruct.h"

class MiniJavaSemantic
{
	private:
		MiniJavaErrorListener errorListener;
	public:
		CodeStruct analyze(MiniJavaParser::ProgContext* progCtx);

		bool hasErrors();
		void printErrorList();
};