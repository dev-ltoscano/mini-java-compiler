#pragma once

#include <string>
#include <vector>

#include "exception/MiniJavaCompilerException.h"

#include "structure/code/CodeStruct.h"
#include "codegen/visitor/CodeGenVisitor.h"

#include "structure/code/AsmFileWriter.h"

class MiniJavaCodeGen
{
	private:
		CodeStruct* codeStruct;
	public:
		MiniJavaCodeGen(CodeStruct* codeStruct);
		void generateCode();
};