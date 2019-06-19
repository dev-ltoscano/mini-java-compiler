/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/
#pragma once

#include <string>

#include "antlr4/antlr4-runtime.h"

#include "MiniJavaVisitor.h"
#include "exception/MiniJavaCompilerException.h"
#include "exception/MiniJavaErrorListener.h"
#include "structure/info/ProgramInfo.h"

/**
 * This class provides an empty implementation of MiniJavaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MiniJavaBaseVisitor : public MiniJavaVisitor
{
protected:
	MiniJavaErrorListener* errorListener;

	ProgramInfo *programInfo;
	std::string tmpClassId;
	std::string tmpMethodId;
	std::string tmpVarId;
public:
	MiniJavaBaseVisitor()
	{
		this->errorListener = nullptr;
		this->programInfo = nullptr;
	}

	MiniJavaBaseVisitor(MiniJavaErrorListener* errorListener)
	{
		this->errorListener = errorListener;
		this->programInfo = nullptr;
	}

	MiniJavaErrorListener* getErrorListener()
	{
		return this->errorListener;
	}

	MiniJavaError getError(ParserRuleContext* ctx, std::string msg)
	{
		antlr4::Token* firstToken = ctx->getStart();

		size_t errorLine = firstToken->getLine();
		size_t errorCollumn = firstToken->getCharPositionInLine();

		return MiniJavaError(errorLine, errorCollumn, msg);
	}

	ClassInfo* getClass(ParserRuleContext* ctx, string classId)
	{
		try
		{
			return programInfo->getClass(classId);
		}
		catch (exception& ex)
		{
			throw MiniJavaCompilerException(&getError(ctx, "The class '" + classId + "' was not declared"));
		}
	}

	VarInfo* getVariable(ParserRuleContext* ctx, string classId, string methodId, string varId)
	{
		try
		{
			return programInfo->getClassMethodVar(classId, methodId, varId);
		}
		catch (exception& ex)
		{
			try
			{
				return programInfo->getClassMethodParam(classId, methodId, varId);
			}
			catch (exception& ex)
			{
				try
				{
					return programInfo->getClassVar(classId, varId);
				}
				catch (exception& ex)
				{
					throw MiniJavaCompilerException(&getError(ctx, "The variable '" + varId + "' was not declared"));
				}
			}
		}
	}

	MethodInfo* getMethod(ParserRuleContext* ctx, string classId, string methodId)
	{
		try
		{
			return programInfo->getClassMethod(classId, methodId);
		}
		catch (exception& ex)
		{
			ClassInfo* classInfo = programInfo->getClass(classId);

			if (classInfo->inheritedClassId == "None")
			{
				throw MiniJavaCompilerException(&getError(ctx, "Class '" + classId + "' does not have method '" + methodId + "' and does not inherit from any superclass"));
			}
			else
			{
				while (classInfo->inheritedClassId != "None")
				{
					classInfo = programInfo->getClass(classInfo->inheritedClassId);

					try
					{
						return programInfo->getClassMethod(classId, methodId);
					}
					catch (exception& ex)
					{

					}
				}

				throw MiniJavaCompilerException(&getError(ctx, "Method '" + methodId + "' does not belong to class '" + classId + "' and its super classes"));
			}
		}
	}

	bool isSubType(std::string superType, std::string subType)
	{
		if ((subType == "int") || (subType == "boolean") || (subType == "String"))
		{
			return false;
		}

		ClassInfo* subClassInfo = programInfo->getClass(subType);

		if (subClassInfo->inheritedClassId == "None")
		{
			return false;
		}
		else
		{
			ClassInfo* superClassInfo = programInfo->getClass(subClassInfo->inheritedClassId);

			if (superClassInfo->id == superType)
			{
				return true;
			}
			else
			{
				while (superClassInfo->inheritedClassId != "None")
				{
					superClassInfo = programInfo->getClass(superClassInfo->inheritedClassId);

					if (superClassInfo->id == superType)
					{
						return true;
					}
				}

				return false;
			}
		}
	}

	/*antlrcpp::Any visit(antlr4::tree::ParseTree* tree)
	{
		try
		{
			return tree->accept(this);
		}
		catch (MiniJavaCompilerException& ex)
		{
			getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
		}
		catch (exception& ex)
		{
			getErrorListener()->addError(0, 0, ex.what());
		}

		return antlrcpp::Any();
	}*/

	antlrcpp::Any visitTerminal(antlr4::tree::TerminalNode* node)
	{
		return antlrcpp::Any(node->toString());
	}

	virtual antlrcpp::Any visitProg(MiniJavaParser::ProgContext *ctx) override 
	{
		visitChildren(ctx);
		return antlrcpp::Any(programInfo);
	}

	virtual antlrcpp::Any visitMainClass(MiniJavaParser::MainClassContext *ctx) override 
	{
		tmpClassId = "MainClass";
		tmpMethodId = "main";
		tmpVarId = "";

		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitClassDecl(MiniJavaParser::ClassDeclContext *ctx) override 
	{
		tmpClassId = ctx->ID().at(0)->toString();
		tmpMethodId = "";
		tmpVarId = "";

		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodDecl(MiniJavaParser::MethodDeclContext *ctx) override 
	{
		tmpMethodId = ctx->ID()->toString();
		tmpVarId = "";

		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodBody(MiniJavaParser::MethodBodyContext *ctx) override
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodReturn(MiniJavaParser::MethodReturnContext *ctx) override 
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext *ctx) override 
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodParams(MiniJavaParser::MethodParamsContext *ctx) override 
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitMethodType(MiniJavaParser::MethodTypeContext *ctx) override 
	{
		if (ctx->VOID())
		{
			return antlrcpp::Any(string("void"));
		}
		else if (ctx->INT())
		{
			if (ctx->LSB() && ctx->RSB())
			{
				return antlrcpp::Any(string("int[]"));
			}
			else
			{
				return antlrcpp::Any(string("int"));
			}
		}
		else if (ctx->STRING())
		{
			return antlrcpp::Any(string("String"));
		}
		else if (ctx->BOOLEAN())
		{
			return antlrcpp::Any(string("boolean"));
		}
		else
		{
			return antlrcpp::Any(ctx->ID()->toString());
		}
	}

	virtual antlrcpp::Any visitVarType(MiniJavaParser::VarTypeContext *ctx) override
	{
		if (ctx->INT())
		{
			if (ctx->LSB() && ctx->RSB())
			{
				return antlrcpp::Any(string("int[]"));
			}
			else
			{
				return antlrcpp::Any(string("int"));
			}
		}
		else if (ctx->BOOLEAN())
		{
			return antlrcpp::Any(string("boolean"));
		}
		else if (ctx->STRING())
		{
			return antlrcpp::Any(string("String"));
		}
		else
		{
			return antlrcpp::Any(ctx->ID()->toString());
		}
	}

	virtual antlrcpp::Any visitVarDecl(MiniJavaParser::VarDeclContext *ctx) override 
	{
		tmpVarId = ctx->ID()->toString();
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext *ctx) override 
	{
		tmpVarId = ctx->ID()->toString();
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitStatement(MiniJavaParser::StatementContext *ctx) override 
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext *ctx) override
	{
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitExpList(MiniJavaParser::ExpListContext *ctx) override 
	{
		return visitChildren(ctx);
	}
};