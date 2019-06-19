#include "semantic/visitor/CollectInformation.h"

#include <iostream>

using namespace std;
using namespace antlrcpp;

Any CollectInformation::visitMainClass(MiniJavaParser::MainClassContext* ctx)
{
	cout << "CollectInformation::visitMainClass" << endl;

	try
	{
		ClassInfo* classInfo = new ClassInfo();
		classInfo->id = "MainClass";
		classInfo->inheritedClassId = "None";

		programInfo->addClass(classInfo);

		tmpClassId = classInfo->id;

		MethodInfo* methodInfo = new MethodInfo();
		methodInfo->id = "main";
		methodInfo->returnType = "void";

		programInfo->addClassMethod(tmpClassId, methodInfo);

		tmpMethodId = methodInfo->id;

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}

Any CollectInformation::visitClassDecl(MiniJavaParser::ClassDeclContext* ctx)
{
	cout << "CollectInformation::visitClassDecl" << endl;

	try
	{
		ClassInfo* classInfo = new ClassInfo();
		classInfo->id = ctx->ID().at(0)->toString();

		if (ctx->EXTENDS())
		{
			classInfo->inheritedClassId = ctx->ID().at(1)->toString();
		}
		else
		{
			classInfo->inheritedClassId = "None";
		}

		programInfo->addClass(classInfo);

		tmpClassId = classInfo->id;
		tmpMethodId = "";

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}

Any CollectInformation::visitVarDecl(MiniJavaParser::VarDeclContext* ctx)
{
	cout << "CollectInformation::visitVarDecl" << endl;

	try
	{
		VarInfo* varInfo = new VarInfo();
		varInfo->id = ctx->ID()->toString();

		if (ctx->varType()->INT())
		{
			if (ctx->varType()->LSB() && ctx->varType()->RSB())
			{
				varInfo->type = "int[]";
			}
			else
			{
				varInfo->type = "int";
			}
		}
		else if (ctx->varType()->BOOLEAN())
		{
			varInfo->type = "boolean";
		}
		else if (ctx->varType()->STRING())
		{
			varInfo->type = "String";
		}
		else if (ctx->varType()->ID())
		{
			varInfo->type = ctx->varType()->ID()->toString();
		}

		if (tmpMethodId.empty())
		{
			programInfo->addClassVar(tmpClassId, varInfo);
		}
		else
		{
			programInfo->addClassMethodVar(tmpClassId, tmpMethodId, varInfo);
		}

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}

Any CollectInformation::visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx)
{
	cout << "CollectInformation::visitVarDeclAndAtt" << endl;

	try
	{
		VarInfo* varInfo = new VarInfo();
		varInfo->id = ctx->ID()->toString();

		if (ctx->varType()->INT())
		{
			if (ctx->varType()->LSB() && ctx->varType()->RSB())
			{
				varInfo->type = "int[]";
			}
			else
			{
				varInfo->type = "int";
			}
		}
		else if (ctx->varType()->BOOLEAN())
		{
			varInfo->type = "boolean";
		}
		else if (ctx->varType()->STRING())
		{
			varInfo->type = "String";
		}
		else if (ctx->varType()->ID())
		{
			varInfo->type = ctx->varType()->ID()->toString();
		}

		if (tmpMethodId.empty())
		{
			programInfo->addClassVar(tmpClassId, varInfo);
		}
		else
		{
			programInfo->addClassMethodVar(tmpClassId, tmpMethodId, varInfo);
		}

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}

Any CollectInformation::visitMethodDecl(MiniJavaParser::MethodDeclContext* ctx)
{
	cout << "CollectInformation::visitMethodDecl" << endl;

	try
	{
		MethodInfo* methodInfo = new MethodInfo();
		methodInfo->id = ctx->ID()->toString();

		if (ctx->methodType()->VOID())
		{
			methodInfo->returnType = "void";
		}
		else if (ctx->methodType()->INT())
		{
			if (ctx->methodType()->LSB() && ctx->methodType()->RSB())
			{
				methodInfo->returnType = "int[]";
			}
			else
			{
				methodInfo->returnType = "int";
			}
		}
		else if (ctx->methodType()->BOOLEAN())
		{
			methodInfo->returnType = "boolean";
		}
		else if (ctx->methodType()->ID())
		{
			methodInfo->returnType = ctx->methodType()->ID()->toString();
		}

		programInfo->addClassMethod(tmpClassId, methodInfo);
		tmpMethodId = methodInfo->id;

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}

Any CollectInformation::visitMethodParams(MiniJavaParser::MethodParamsContext* ctx)
{
	cout << "CollectInformation::visitMethodParams" << endl;

	try
	{
		vector<antlr4::tree::TerminalNode*> paramList = ctx->ID();

		for (int i = 0; i < paramList.size(); i++)
		{
			VarInfo* varInfo = new VarInfo();
			varInfo->id = paramList.at(i)->toString();

			if (ctx->varType().at(i)->INT())
			{
				if (ctx->varType().at(i)->LSB() && ctx->varType().at(i)->RSB())
				{
					varInfo->type = "int[]";
				}
				else
				{
					varInfo->type = "int";
				}
			}
			else if (ctx->varType().at(i)->BOOLEAN())
			{
				varInfo->type = "boolean";
			}
			else if (ctx->varType().at(i)->ID())
			{
				varInfo->type = ctx->varType().at(i)->ID()->toString();
			}

			programInfo->addClassMethodParam(tmpClassId, tmpMethodId, varInfo);
		}

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		MiniJavaError error = getError(ctx, ex.what());
		getErrorListener()->addError(error.line, error.positionInLine, error.msg);
	}

	return Any();
}