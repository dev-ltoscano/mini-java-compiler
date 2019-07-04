#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "exception/MiniJavaCompilerException.h"
#include "parser/MiniJavaParser.h"
#include "structure/code/CodeStruct.h"
#include "codegen/visitor/CodeGenVisitor.h"

class MiniJavaCodeGen
{
	private:
		MiniJavaParser::ProgContext* progCtx;
		CodeStruct* codeStruct;
		ofstream asmFile;

		MiniJavaErrorListener errorListener;
	public:
		MiniJavaCodeGen(CodeStruct* codeStruct, MiniJavaParser::ProgContext* progCtx);
		void generateCode();
};