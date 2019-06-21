/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <string>
#include <vector>

#include "ast/visitor/ASTBaseVisitor.h"

#include "parser/MiniJavaParser.h"

class DeclarationVisitor : public ASTBaseVisitor
{
	private:
		void visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl);
		void visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl);

		void visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl);

		VarInfo* visitVar(ASTVar* varDecl);
		VarInfo* visitVarAndAtt(ASTVarAndAtt* varAtt);
	public:
		DeclarationVisitor(MiniJavaErrorListener* errorListener, ASTProgram* program) : ASTBaseVisitor(errorListener, program) { }

		ProgramInfo* visitProgram(MiniJavaParser::ProgContext* ctx);
};