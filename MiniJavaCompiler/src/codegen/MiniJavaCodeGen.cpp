#include "codegen/MiniJavaCodeGen.h"

using namespace std;

MiniJavaCodeGen::MiniJavaCodeGen(CodeStruct* codeStruct, MiniJavaParser::ProgContext* progCtx)
{
	this->codeStruct = codeStruct;
	this->progCtx = progCtx;
}

void MiniJavaCodeGen::generateCode()
{
	asmFile.open("output.asm");

	if (!asmFile.is_open())
	{
		throw MiniJavaCompilerException("Could not create assembly file");
	}

	asmFile << "extern printf" << endl;

	asmFile << endl << "global main" << endl;

	asmFile << endl << "section .data" << endl;
	asmFile << "\tnumber_format: db '%d', 10, 0" << endl;

	asmFile << endl << "section .text" << endl;

	CodeGenVisitor codeGenVisitor(&errorListener, codeStruct->astProgram, codeStruct->programInfo);
	vector<string> asmCode = codeGenVisitor.visitProgram(progCtx);

	for (string str : asmCode)
	{
		asmFile << str;
	}

	asmFile.close();
}