/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "codegen/visitor/CodeGenVisitor.h"

#include <iostream>

using namespace std;

AsmFile* CodeGenVisitor::visitProgram(MiniJavaParser::ProgContext* ctx)
{
	try
	{
		visitMainClass(ctx->mainClass(), astProgram->getMainClass());
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

	return asmFile;
}

void CodeGenVisitor::visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl)
{
	try
	{
		cout << "CodeGenVisitor::visitMainClass()" << endl;

		tmpClassId = mainClassDecl->getId();
		tmpMethodId = mainClassDecl->getMainMethod()->getId();

		asmFile->setGlobalFunctionLabel(tmpMethodId);

		AsmFunction* mainFunction = new AsmFunction(tmpMethodId);
		asmFile->addFunction(mainFunction);

		vector<ASTVarAndAtt*>* varAttList = mainClassDecl->getMainMethod()->getMethodBody()->getVarAndAttList();

		for (int i = 0; i < varAttList->size(); i++)
		{
			visitVarAndAtt(ctx->methodBody()->varDeclAndAtt().at(i), varAttList->at(i));
		}

		vector<ASTStatement*>* stmtList = mainClassDecl->getMainMethod()->getMethodBody()->getStatementList();

		for (int i = 0; i < stmtList->size(); i++)
		{
			visitStatement(ctx->methodBody()->statement().at(i), stmtList->at(i));
		}

		mainFunction->addBodyInstruction("mov rax, 60");
		mainFunction->addBodyInstruction("xor rdi, rdi");
		mainFunction->addBodyInstruction("syscall");
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

void CodeGenVisitor::visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl)
{
	try
	{
		
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

void CodeGenVisitor::visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx, ASTVarAndAtt* varAndAtt)
{
	try
	{
		cout << "CodeGenVisitor::visitVarAndAtt()" << endl;
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

void CodeGenVisitor::visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl)
{
	try
	{
		
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

void CodeGenVisitor::visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx, ASTMethodReturn* methodReturnDecl)
{
	try
	{
		
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

void CodeGenVisitor::visitMethodCallParams(MiniJavaParser::MethodCallContext* ctx, ASTMethodCall* methodCall)
{
	try
	{
		
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

void CodeGenVisitor::visitStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt)
{
	try
	{
		cout << "CodeGenVisitor::visitStatement()" << endl;

		switch (stmt->getStatementType())
		{
			case MiniJavaStmtType::IF:
			{
				break;
			}
			case MiniJavaStmtType::IFELSE:
			{
				break;
			}
			case MiniJavaStmtType::WHILE:
			{
				break;
			}
			case MiniJavaStmtType::SOUT:
			{
				asmFile->addExternFunction("printf");
				AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);

				ASTSout* soutStmt = MiniJavaStmtTypeCasting::castToSout(stmt);
				antlrcpp::Any exp = visitExpression(ctx->expression().at(0), soutStmt->getExpression());

				if (exp.is<ASTLiteralString*>())
				{
					asmFile->addData("msg_0: db " + exp.as<ASTLiteralString*>()->getString() + ", 0");

					asmFunction->addBodyInstruction("mov rdi, string_format");
					asmFunction->addBodyInstruction("mov rsi, msg_0");
					asmFunction->addBodyInstruction("xor rax, rax");
					asmFunction->addBodyInstruction("call printf");
				}
				else if (exp.is<ASTId*>())
				{
					ASTId* varId = exp.as<ASTId*>();
					VarInfo* varInfo = getVariable(tmpClassId, tmpMethodId, varId->getId(), true);

					if (varInfo->type == "String")
					{
						asmFunction->addBodyInstruction("mov rdi, string_format");
						asmFunction->addBodyInstruction("mov rsi, [" + varId->getId() + "]");
						asmFunction->addBodyInstruction("xor rax, rax");
						asmFunction->addBodyInstruction("call printf");
					}
					else if (varInfo->type == "int")
					{
						asmFunction->addBodyInstruction("mov rdi, number_format");
						asmFunction->addBodyInstruction("mov rsi, [" + varId->getId() + "]");
						asmFunction->addBodyInstruction("xor rax, rax");
						asmFunction->addBodyInstruction("call printf");
					}
				}
				else
				{
					asmFunction->addBodyInstruction("mov rdi, number_format");
					asmFunction->addBodyInstruction("mov rsi, " + to_string(exp.as<ASTLiteralInteger*>()->getInteger()));
					asmFunction->addBodyInstruction("xor rax, rax");
					asmFunction->addBodyInstruction("call printf");
				}
				break;
			}
			case MiniJavaStmtType::ASSIGN:
			{
				AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);

				ASTAssign* assignStmt = MiniJavaStmtTypeCasting::castToAssign(stmt);

				string varId = assignStmt->getId()->getId();
				VarInfo* varInfo = getVariable(tmpClassId, tmpMethodId, varId, true);
				asmFile->addBss(varId + ": resb 4");

				antlrcpp::Any exp = visitExpression(ctx->expression().at(0), assignStmt->getExpression());

				if (exp.is<ASTArithmetic*>())
				{
					ASTArithmetic* arithmetic = exp.as<ASTArithmetic*>();

					ASTLiteralInteger* firstExpression = MiniJavaExpTypeCasting::castToLiteralInteger(arithmetic->getFirstExpression());
					ASTLiteralInteger* secondExpression = MiniJavaExpTypeCasting::castToLiteralInteger(arithmetic->getSecondExpression());

					switch (arithmetic->getOperation())
					{
						case MiniJavaOp::SUM:
						{
							asmFunction->addBodyInstruction("mov rdi, " + to_string(firstExpression->getInteger()));
							asmFunction->addBodyInstruction("mov rsi, " + to_string(secondExpression->getInteger()));
							asmFunction->addBodyInstruction("add rdi, rsi");
							asmFunction->addBodyInstruction("mov [" + varId + "], rdi");
							break;
						}
					}
				}

				break;
			}
			case MiniJavaStmtType::ASSIGN_ARRAY:
			{
				break;
			}
			case MiniJavaStmtType::METHODCALL:
			{
				break;
			}
			case MiniJavaStmtType::STMTLIST:
			{
				break;
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

antlrcpp::Any CodeGenVisitor::visitExpression(MiniJavaParser::ExpressionContext* ctx, ASTExpression* exp)
{
	try
	{
		cout << "CodeGenVisitor::visitExpression()" << endl;

		switch (exp->getExpressionType())
		{
			case MiniJavaExpType::LiteralInteger:
			{
				return antlrcpp::Any(MiniJavaExpTypeCasting::castToLiteralInteger(exp));
			}
			case MiniJavaExpType::LiteralBoolean:
			{
				break;
			}
			case MiniJavaExpType::LiteralString:
			{
				return antlrcpp::Any(MiniJavaExpTypeCasting::castToLiteralString(exp));
				break;
			}
			case MiniJavaExpType::IdType:
			{
				return antlrcpp::Any(MiniJavaExpTypeCasting::castToId(exp));
				break;
			}
			case MiniJavaExpType::NewObject:
			{
				break;
			}
			case MiniJavaExpType::NewIntegerArray:
			{
				break;
			}
			case MiniJavaExpType::Arithmetic:
			{
				return antlrcpp::Any(MiniJavaExpTypeCasting::castToArithmetic(exp));
				break;
			}
			case MiniJavaExpType::And:
			{
				break;
			}
			case MiniJavaExpType::Or:
			{
				break;
			}
			case MiniJavaExpType::Comp:
			{
				break;
			}
			case MiniJavaExpType::Negation:
			{
				break;
			}
			case MiniJavaExpType::Negative:
			{
				break;
			}
			case MiniJavaExpType::Length:
			{
				break;
			}
			case MiniJavaExpType::MethodCall:
			{
				break;
			}
			case MiniJavaExpType::AccessIntegerArray:
			{
				break;
			}
			case MiniJavaExpType::Super:
			{
				break;
			}
			case MiniJavaExpType::This:
			{
				break;
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

	return antlrcpp::Any(nullptr);
}