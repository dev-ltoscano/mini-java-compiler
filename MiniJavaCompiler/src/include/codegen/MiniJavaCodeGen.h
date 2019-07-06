#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaCompilerException.h"
#include "parser/MiniJavaParser.h"

#include "structure/code/CodeStruct.h"
#include "codegen/visitor/CodeGenVisitor.h"

#include "structure/code/AsmFileWriter.h"

class MiniJavaCodeGen
{
	private:
		MiniJavaParser::ProgContext* progCtx;
		CodeStruct* codeStruct;
	public:
		MiniJavaCodeGen(CodeStruct* codeStruct, MiniJavaParser::ProgContext* progCtx);
		void generateCode();
};