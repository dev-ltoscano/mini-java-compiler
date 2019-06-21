#include "semantic/visitor/DeclarationVisitor.h"

ProgramInfo* DeclarationVisitor::visitProgram(MiniJavaParser::ProgContext* ctx)
{
	cout << "DeclarationVisitor::visitProgram()" << endl;

	try
	{
		visitMainClass(ctx->mainClass(), program->getMainClass());

		vector<ASTClass*>* classList = program->getClassList();

		for (int i = 0; i < classList->size(); i++)
		{
			visitClass(ctx->classDecl().at(i), classList->at(i));
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (ex.getLine() == 0)
		{
			ex.setLine(getErrorLine(ctx->getStart()));
			ex.setCollumn(getErrorCollumn(ctx->getStart()));
		}

		errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}

	return this->programInfo;
}

void DeclarationVisitor::visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl)
{
	cout << "DeclarationVisitor::visitMainClass()" << endl;

	try
	{
		ClassInfo* mainClassInfo = new ClassInfo();
		mainClassInfo->id = mainClassDecl->getId();
		mainClassInfo->inheritedClassId = "None";

		programInfo->addMainClass(mainClassInfo);

		tmpClassId = mainClassInfo->id;

		ASTMethod* mainMethod = mainClassDecl->getMainMethod();

		MethodInfo* mainMethodInfo = new MethodInfo();
		mainMethodInfo->id = mainMethod->getId();

		if (mainMethod->getMethodReturnType()->getType() != MiniJavaType::ID)
		{
			mainMethodInfo->returnType = typeToString(mainMethod->getMethodReturnType()->getType());
		}
		else
		{
			mainMethodInfo->returnType = mainMethod->getMethodReturnType()->getIDType();
		}

		programInfo->addClassMethod(mainClassInfo->id, mainMethodInfo);

		ASTMethodParams* mainMethodParams = mainMethod->getMethodParams();
		vector<ASTVar*>* paramList = mainMethodParams->getParamList();
		ASTVar* tmpParam;

		for (int i = 0; i < paramList->size(); i++)
		{
			tmpParam = paramList->at(i);

			VarInfo* varInfo = new VarInfo();
			varInfo->id = tmpParam->getId();
			
			if (tmpParam->getVarType()->getType() != MiniJavaType::ID)
			{
				varInfo->type = typeToString(tmpParam->getVarType()->getType());
			}
			else
			{
				varInfo->type = tmpParam->getVarType()->getIDType();
			}

			programInfo->addClassMethodParam(mainClassInfo->id, mainMethodInfo->id, varInfo);
		}

		ASTMethodBody* mainMethodBody = mainMethod->getMethodBody();
		vector<ASTVar*>* varList = mainMethodBody->getVarList();
		ASTVar* tmpVar;
		
		for (int i = 0; i < varList->size(); i++)
		{
			tmpVar = varList->at(i);

			VarInfo* varInfo = new VarInfo();
			varInfo->id = tmpVar->getId();

			if (tmpVar->getVarType()->getType() != MiniJavaType::ID)
			{
				varInfo->type = typeToString(tmpVar->getVarType()->getType());
			}
			else
			{
				varInfo->type = tmpVar->getVarType()->getIDType();
			}

			programInfo->addClassMethodVar(mainClassInfo->id, mainMethodInfo->id, varInfo);
		}

		vector<ASTVarAndAtt*>* varAttList = mainMethodBody->getVarAndAttList();
		ASTVarAndAtt* tmpVarAtt;

		for (int i = 0; i < varAttList->size(); i++)
		{
			tmpVarAtt = varAttList->at(i);

			VarInfo* varInfo = new VarInfo();
			varInfo->id = tmpVarAtt->getId();

			if (tmpVarAtt->getVarType()->getType() != MiniJavaType::ID)
			{
				varInfo->type = typeToString(tmpVarAtt->getVarType()->getType());
			}
			else
			{
				varInfo->type = tmpVarAtt->getVarType()->getIDType();
			}

			programInfo->addClassMethodVar(mainClassInfo->id, mainMethodInfo->id, varInfo);
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (ex.getLine() == 0)
		{
			ex.setLine(getErrorLine(ctx->getStart()));
			ex.setCollumn(getErrorCollumn(ctx->getStart()));
		}

		errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
}

void DeclarationVisitor::visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl)
{
	cout << "DeclarationVisitor::visitClass()" << endl;

	try
	{
		ClassInfo* classInfo = new ClassInfo();
		classInfo->id = classDecl->getId();
		classInfo->inheritedClassId = classDecl->getInheritedClass();

		programInfo->addClass(classInfo);

		tmpClassId = classInfo->id;

		vector<ASTVar*>* varList = classDecl->getVarList();
		ASTVar* tmpVar;

		for (int i = 0; i < varList->size(); i++)
		{
			try
			{
				tmpVar = varList->at(i);

				VarInfo* varInfo = visitVar(tmpVar);
				programInfo->addClassVar(tmpClassId, varInfo);
			}
			catch (MiniJavaCompilerException& ex)
			{
				if (ex.getLine() == 0)
				{
					ex.setLine(getErrorLine(ctx->varDecl().at(i)->getStart()));
					ex.setCollumn(getErrorCollumn(ctx->varDecl().at(i)->getStart()));
				}

				errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
			}
		}

		vector<ASTVarAndAtt*>* varAttList = classDecl->getVarAndAttList();
		ASTVarAndAtt* tmpVarAtt;

		for (int i = 0; i < varAttList->size(); i++)
		{
			try
			{
				tmpVarAtt = varAttList->at(i);

				VarInfo* varInfo = visitVarAndAtt(tmpVarAtt);
				programInfo->addClassVar(tmpClassId, varInfo);
			}
			catch (MiniJavaCompilerException& ex)
			{
				if (ex.getLine() == 0)
				{
					ex.setLine(getErrorLine(ctx->varDeclAndAtt().at(i)->getStart()));
					ex.setCollumn(getErrorCollumn(ctx->varDeclAndAtt().at(i)->getStart()));
				}

				errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
			}
		}

		vector<ASTMethod*>* methodList = classDecl->getMethodList();
		ASTMethod* tmpMethod;

		for (int i = 0; i < methodList->size(); i++)
		{
			tmpMethod = methodList->at(i);
			visitMethod(ctx->methodDecl().at(i), tmpMethod);
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (ex.getLine() == 0)
		{
			ex.setLine(getErrorLine(ctx->getStart()));
			ex.setCollumn(getErrorCollumn(ctx->getStart()));
		}

		errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
}

void DeclarationVisitor::visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl)
{
	cout << "DeclarationVisitor::visitMethod()" << endl;

	try
	{
		MethodInfo* methodInfo = new MethodInfo();
		methodInfo->id = methodDecl->getId();

		if (methodDecl->getMethodReturnType()->getType() != MiniJavaType::ID)
		{
			methodInfo->returnType = typeToString(methodDecl->getMethodReturnType()->getType());
		}
		else
		{
			methodInfo->returnType = methodDecl->getMethodReturnType()->getIDType();
		}

		programInfo->addClassMethod(tmpClassId, methodInfo);

		tmpMethodId = methodInfo->id;

		vector<ASTVar*>* paramList = methodDecl->getMethodParams()->getParamList();
		ASTVar* tmpParam;

		for (int i = 0; i < paramList->size(); i++)
		{
			try
			{
				tmpParam = paramList->at(i);

				VarInfo* paramInfo = visitVar(tmpParam);
				programInfo->addClassMethodParam(tmpClassId, tmpMethodId, paramInfo);
			}
			catch (MiniJavaCompilerException& ex)
			{
				if (ex.getLine() == 0)
				{
					ex.setLine(getErrorLine(ctx->methodParams()->varType(i)->getStart()));
					ex.setCollumn(getErrorCollumn(ctx->methodParams()->varType(i)->getStart()));
				}

				errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
			}
		}

		vector<ASTVar*>* tmpVarList = methodDecl->getMethodBody()->getVarList();
		ASTVar* tmpVar;

		for (int i = 0; i < tmpVarList->size(); i++)
		{
			try
			{
				tmpVar = tmpVarList->at(i);

				VarInfo* methodVar = visitVar(tmpVar);
				programInfo->addClassMethodVar(tmpClassId, tmpMethodId, methodVar);
			}
			catch (MiniJavaCompilerException& ex)
			{
				if (ex.getLine() == 0)
				{
					ex.setLine(getErrorLine(ctx->methodBody()->varDecl().at(i)->getStart()));
					ex.setCollumn(getErrorCollumn(ctx->methodBody()->varDecl().at(i)->getStart()));
				}

				errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
			}
		}

		vector<ASTVarAndAtt*>* tmpVarAttList = methodDecl->getMethodBody()->getVarAndAttList();
		ASTVarAndAtt* tmpVarAtt;

		for (int i = 0; i < tmpVarAttList->size(); i++)
		{
			try
			{
				tmpVarAtt = tmpVarAttList->at(i);

				VarInfo* methodVar = visitVarAndAtt(tmpVarAtt);
				programInfo->addClassMethodVar(tmpClassId, tmpMethodId, methodVar);
			}
			catch (MiniJavaCompilerException& ex)
			{
				if (ex.getLine() == 0)
				{
					ex.setLine(getErrorLine(ctx->methodBody()->varDeclAndAtt().at(i)->getStart()));
					ex.setCollumn(getErrorCollumn(ctx->methodBody()->varDeclAndAtt().at(i)->getStart()));
				}

				errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
			}
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (ex.getLine() == 0)
		{
			ex.setLine(getErrorLine(ctx->getStart()));
			ex.setCollumn(getErrorCollumn(ctx->getStart()));
		}

		errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
}

VarInfo* DeclarationVisitor::visitVar(ASTVar* varDecl)
{
	cout << "DeclarationVisitor::visitVar()" << endl;
	VarInfo* varInfo = new VarInfo();

	varInfo->id = varDecl->getId();

	if (varDecl->getVarType()->getType() != MiniJavaType::ID)
	{
		varInfo->type = typeToString(varDecl->getVarType()->getType());
	}
	else
	{
		varInfo->type = varDecl->getVarType()->getIDType();
	}

	return varInfo;
}

VarInfo* DeclarationVisitor::visitVarAndAtt(ASTVarAndAtt* varAtt)
{
	cout << "DeclarationVisitor::visitVarAndAtt()" << endl;
	VarInfo* varInfo = new VarInfo();

	varInfo->id = varAtt->getId();

	if (varAtt->getVarType()->getType() != MiniJavaType::ID)
	{
		varInfo->type = typeToString(varAtt->getVarType()->getType());
	}
	else
	{
		varInfo->type = varAtt->getVarType()->getIDType();
	}

	return varInfo;
}