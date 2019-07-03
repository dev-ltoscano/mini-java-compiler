#pragma once

#include <fstream>

#include "exception/MiniJavaCompilerException.h"
#include "structure/code/CodeStruct.h"

class MiniJavaCodeGen
{
	private:
		CodeStruct* codeStruct;
	public:
		MiniJavaCodeGen(CodeStruct* codeStruct);
		void generateCode();
};