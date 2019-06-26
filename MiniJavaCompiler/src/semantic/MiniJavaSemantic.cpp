/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "semantic/MiniJavaSemantic.h"

void MiniJavaSemantic::analyze(MiniJavaParser::ProgContext* progCtx)
{
	TransformToASTVisitor transformAST;
	ASTProgram* program = transformAST.visitProgram(progCtx);

	DeclarationVisitor declarationVisitor(&errorListener, program);
	ProgramInfo* programInfo = declarationVisitor.visitProgram(progCtx);

	ExpressionVisitor expressionVisitor(&errorListener, program, programInfo);
	expressionVisitor.visitProgram(progCtx);
}

bool MiniJavaSemantic::hasErrors()
{
	return errorListener.hasErrors();
}

void MiniJavaSemantic::printErrorList()
{
	errorListener.printErrorList();
}