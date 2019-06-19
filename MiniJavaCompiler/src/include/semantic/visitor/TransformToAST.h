#pragma once

#include <string>

#include "exception/MiniJavaErrorListener.h"
#include "parser/MiniJavaParser.h"

#include "ast/node/ASTProgram.h"
#include "ast/node/ASTMainClass.h"
#include "ast/node/ASTClass.h"
#include "ast/node/ASTMethod.h"
#include "ast/node/ASTVar.h"

//virtual antlrcpp::Any visitMethodBody(MiniJavaParser::MethodBodyContext* context) = 0;
//
//virtual antlrcpp::Any visitMethodReturn(MiniJavaParser::MethodReturnContext* context) = 0;
//
//virtual antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext* context) = 0;
//
//virtual antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext* context) = 0;
//
//virtual antlrcpp::Any visitStatement(MiniJavaParser::StatementContext* context) = 0;
//
//virtual antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext* context) = 0;
//
//virtual antlrcpp::Any visitExpList(MiniJavaParser::ExpListContext* context) = 0;

class TransformToAST
{
	public:
		ASTProgram* visitProgram(MiniJavaParser::ProgContext* ctx)
		{
			ASTProgram* program = new ASTProgram();

			ASTMainClass* mainClass = visitMainClass(ctx->mainClass());
			program->setMainClass(mainClass);

			std::vector<MiniJavaParser::ClassDeclContext*> classList = ctx->classDecl();

			for (MiniJavaParser::ClassDeclContext* classCtx : classList)
			{
				ASTClass* classDecl = visitClass(classCtx);
				program->addClass(classDecl);
			}

			return program;
		}

		ASTMainClass* visitMainClass(MiniJavaParser::MainClassContext* ctx)
		{
			return new ASTMainClass(new ASTMethod("main", new ASTMethodType(MiniJavaType::VOID)));
		}

		ASTClass* visitClass(MiniJavaParser::ClassDeclContext* ctx)
		{
			ASTClass* classNode = new ASTClass(ctx->ID().at(0)->toString());

			std::vector<MiniJavaParser::VarDeclContext*> varList = ctx->varDecl();

			for (MiniJavaParser::VarDeclContext* varCtx : varList)
			{
				ASTVar* var = visitVar(varCtx);
				classNode->addVar(var);
			}

			std::vector<MiniJavaParser::MethodDeclContext*> methodList = ctx->methodDecl();

			for (MiniJavaParser::MethodDeclContext* methodCtx : methodList)
			{
				ASTMethod* method = visitMethod(methodCtx);
				classNode->addMethod(method);
			}

			return classNode;
		}

		ASTMethod* visitMethod(MiniJavaParser::MethodDeclContext* ctx)
		{
			ASTMethodType* methodReturnType = visitMethodType(ctx->methodType());
			ASTMethodParams* methodParams = visitMethodParams(ctx->methodParams());

			return new ASTMethod(ctx->ID()->toString(), methodReturnType, methodParams);
		}

		ASTMethodType* visitMethodType(MiniJavaParser::MethodTypeContext* ctx)
		{
			if (ctx->VOID())
			{
				return new ASTMethodType(MiniJavaType::VOID);
			}
			else if (ctx->INT())
			{
				if (ctx->LSB() && ctx->RSB())
				{
					return new ASTMethodType(MiniJavaType::INT_ARRAY);
				}
				else
				{
					return new ASTMethodType(MiniJavaType::INT);
				}
			}
			else if (ctx->STRING())
			{
				return new ASTMethodType(MiniJavaType::STRING);
			}
			else if (ctx->BOOLEAN())
			{
				return new ASTMethodType(MiniJavaType::BOOLEAN);
			}
			else
			{
				return new ASTMethodType(ctx->ID()->toString(), MiniJavaType::ID);
			}
		}

		ASTMethodParams* visitMethodParams(MiniJavaParser::MethodParamsContext* ctx)
		{
			ASTMethodParams* methodParams = new ASTMethodParams();

			std::vector<antlr4::tree::TerminalNode*> varList = ctx->ID();

			for (int i = 0; i < varList.size(); i++)
			{
				std::string varId = varList.at(i)->toString();
				ASTVarType *varType = visitVarType(ctx->varType().at(i));

				methodParams->addParam(new ASTVar(varId, varType));
			}

			return methodParams;
		}

		ASTVar* visitVar(MiniJavaParser::VarDeclContext* ctx)
		{
			ASTVarType* varType = visitVarType(ctx->varType());
			return new ASTVar(ctx->ID()->toString(), varType);
		}

		ASTVarType* visitVarType(MiniJavaParser::VarTypeContext* ctx)
		{
			if (ctx->INT())
			{
				if (ctx->LSB() && ctx->RSB())
				{
					return new ASTVarType(MiniJavaType::INT_ARRAY);
				}
				else
				{
					return new ASTVarType(MiniJavaType::INT);
				}
			}
			else if (ctx->BOOLEAN())
			{
				return new ASTVarType(MiniJavaType::BOOLEAN);
			}
			else if (ctx->STRING())
			{
				return new ASTVarType(MiniJavaType::STRING);
			}
			else
			{
				return new ASTVarType(ctx->ID()->toString(), MiniJavaType::ID);
			}
		}
};