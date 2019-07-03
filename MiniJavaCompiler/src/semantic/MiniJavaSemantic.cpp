/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "semantic/MiniJavaSemantic.h"

CodeStruct MiniJavaSemantic::analyze(MiniJavaParser::ProgContext* progCtx)
{
	TransformToASTVisitor transformAST;
	ASTProgram* astProgram = transformAST.visitProgram(progCtx);

	DeclarationVisitor declarationVisitor(&errorListener, astProgram);
	ProgramInfo* programInfo = declarationVisitor.visitProgram(progCtx);

	ExpressionVisitor expressionVisitor(&errorListener, astProgram, programInfo);
	expressionVisitor.visitProgram(progCtx);

	return CodeStruct(astProgram, programInfo);
}

bool MiniJavaSemantic::hasErrors()
{
	return errorListener.hasErrors();
}

void MiniJavaSemantic::printErrorList()
{
	errorListener.printErrorList();
}