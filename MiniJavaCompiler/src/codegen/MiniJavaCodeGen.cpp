#include "codegen/MiniJavaCodeGen.h"

using namespace std;

MiniJavaCodeGen::MiniJavaCodeGen(CodeStruct* codeStruct)
{
	this->codeStruct = codeStruct;
}

void MiniJavaCodeGen::generateCode()
{
	cout << "MiniJavaCodeGen::generateCode()" << endl;
	CodeGenVisitor codeGenVisitor(codeStruct->astProgram, codeStruct->programInfo);
	AsmFile* asmFile = codeGenVisitor.visitProgram();

	AsmFileWriter asmFileWriter(asmFile);
	asmFileWriter.saveFile("output.asm");
}