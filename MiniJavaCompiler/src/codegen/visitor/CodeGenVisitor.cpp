/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "codegen/visitor/CodeGenVisitor.h"

using namespace std;

vector<string> CodeGenVisitor::visitProgram(MiniJavaParser::ProgContext* ctx)
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

	return asmCode;
}

void CodeGenVisitor::visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl)
{
	try
	{
		asmCode.push_back("\tmain:\n");

		vector<ASTStatement*>* stmtList = mainClassDecl->getMainMethod()->getMethodBody()->getStatementList();

		for (int i = 0; i < stmtList->size(); i++)
		{
			visitStatement(ctx->methodBody()->statement().at(i), stmtList->at(i));
		}

		asmCode.push_back("\t\tmov rax, 60\n");
		asmCode.push_back("\t\txor rdi, rdi\n");
		asmCode.push_back("\t\tsyscall\n");
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
				ASTSout* soutStmt = MiniJavaStmtTypeCasting::castToSout(stmt);

				antlrcpp::Any expType = visitExpression(ctx->expression().at(0), soutStmt->getExpression());

				asmCode.push_back("\t\tmov rdi, number_format\n");
				asmCode.push_back("\t\tmov rsi, " + to_string(expType.as<ASTLiteralInteger*>()->getInteger()) + "\n");
				asmCode.push_back("\t\txor rax, rax\n");
				asmCode.push_back("\t\tcall printf\n");
				break;
			}
			case MiniJavaStmtType::ASSIGN:
			{
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
				break;
			}
			case MiniJavaExpType::IdType:
			{
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