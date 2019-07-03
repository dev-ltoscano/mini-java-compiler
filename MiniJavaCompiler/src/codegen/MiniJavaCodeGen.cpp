#include "codegen/MiniJavaCodeGen.h"

MiniJavaCodeGen::MiniJavaCodeGen(CodeStruct* codeStruct)
{
	this->codeStruct = codeStruct;
}

void MiniJavaCodeGen::generateCode()
{
	ofstream asmFile("output.asm");

	if (!asmFile.is_open())
	{
		throw MiniJavaCompilerException("Could not create assembly file");
	}

	asmFile << "global _start" << endl;

	asmFile << endl;

	asmFile << "section .data" << endl;
	asmFile << "msg:  db \"Hello, World\", 10" << endl;

	asmFile << endl;

	asmFile << "section .bss" << endl;

	asmFile << endl;

	asmFile << "section .text" << endl;
	asmFile << "_start: mov rax, 1" << endl;
	asmFile << "       mov rdi, 1" << endl;
	asmFile << "       mov rsi, msg" << endl;
	asmFile << "       mov rdx, 13" << endl;
	asmFile << "       syscall" << endl;
	asmFile << "       mov rax, 60" << endl;
	asmFile << "       xor rdi, rdi" << endl;
	asmFile << "       syscall" << endl << endl;

	asmFile.close();
}