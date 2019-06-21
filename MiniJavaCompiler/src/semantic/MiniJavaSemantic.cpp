/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "semantic/MiniJavaSemantic.h"

using namespace std;

void MiniJavaSemantic::analyze(MiniJavaParser::ProgContext* progCtx)
{
	TransformToASTVisitor transformAST;
	ASTProgram* program = transformAST.visitProgram(progCtx);

	DeclarationVisitor declarationVisitor(&errorListener, program);
	ProgramInfo* programInfo = declarationVisitor.visitProgram(progCtx);

	ExpressionVisitor expressionVisitor(&errorListener, program, programInfo);
	expressionVisitor.visitProgram(progCtx);

	/*unordered_map<string, ClassInfo*> classList = programInfo->getClassList();

	for (pair<string, ClassInfo*> classInfo : classList)
	{
		cout << "CLASS: " << classInfo.first << " | INHERITED: " << classInfo.second->inheritedClassId << endl;

		unordered_map<string, VarInfo*> varList = classInfo.second->varInfoMap;

		cout << "     Variable list:" << endl;

		for (pair<string, VarInfo*> varInfo : varList)
		{
			cout << "          ID: " << varInfo.second->id << " | TYPE: " << varInfo.second->type << endl;
		}

		unordered_map<string, MethodInfo*> methodList = classInfo.second->methodInfoMap;

		cout << endl << "     Method list:" << endl;

		for (pair<string, MethodInfo*> methodInfo : methodList)
		{
			cout << "          ID: " << methodInfo.second->id
				<< " | RETURN: " << methodInfo.second->returnType
				<< " | PARAMS: " << methodInfo.second->paramInfoMap.size()
				<< " | VARS: " << methodInfo.second->varInfoMap.size() << endl;

			unordered_map<string, VarInfo*> paramList = methodInfo.second->paramInfoMap;

			cout << "               Parameter list:" << endl;

			for (pair<string, VarInfo*> paramInfo : paramList)
			{
				cout << "                    ID: " << paramInfo.second->id << " | TYPE: " << paramInfo.second->type << endl;
			}

			unordered_map<string, VarInfo*> varList = methodInfo.second->varInfoMap;

			cout << "               Variable list:" << endl;

			for (pair<string, VarInfo*> varInfo : varList)
			{
				cout << "                    ID: " << varInfo.second->id << " | TYPE: " << varInfo.second->type << endl;
			}
		}

		cout << endl;
	}*/
}

bool MiniJavaSemantic::hasErrors()
{
	return errorListener.hasErrors();
}

void MiniJavaSemantic::printErrorList()
{
	errorListener.printErrorList();
}