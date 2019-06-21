#include "semantic/visitor/ExpressionVisitor.h"

void ExpressionVisitor::visitProgram(MiniJavaParser::ProgContext* ctx)
{
	cout << "ExpressionVisitor::visitProgram()" << endl;

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
}

void ExpressionVisitor::visitMainClass(MiniJavaParser::MainClassContext* ctx, ASTMainClass* mainClassDecl)
{
	cout << "ExpressionVisitor::visitMainClass()" << endl;

	try
	{
		tmpClassId = mainClassDecl->getId();
		tmpMethodId = mainClassDecl->getMainMethod()->getId();

		vector<ASTVarAndAtt*>* varAttList = mainClassDecl->getMainMethod()->getMethodBody()->getVarAndAttList();

		for (int i = 0; i < varAttList->size(); i++)
		{
			visitVarAndAtt(ctx->methodBody()->varDeclAndAtt().at(i), varAttList->at(i));
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

void ExpressionVisitor::visitClass(MiniJavaParser::ClassDeclContext* ctx, ASTClass* classDecl)
{
	cout << "ExpressionVisitor::visitClass()" << endl;

	try
	{
		tmpClassId = classDecl->getId();

		vector<ASTVarAndAtt*>* varAttList = classDecl->getVarAndAttList();

		for (int i = 0; i < varAttList->size(); i++)
		{
			visitVarAndAtt(ctx->varDeclAndAtt().at(i), varAttList->at(i));
		}

		vector<ASTMethod*>* methodList = classDecl->getMethodList();

		for (int i = 0; i < methodList->size(); i++)
		{
			visitMethod(ctx->methodDecl().at(i), methodList->at(i));
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

void ExpressionVisitor::visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx, ASTVarAndAtt* varAndAtt)
{
	cout << "ExpressionVisitor::visitVarAndAtt()" << endl;

	try
	{
		switch (varAndAtt->getAttExpression()->getExpressionType())
		{
			case MiniJavaExpType::LiteralInteger:
			case MiniJavaExpType::Length:
			case MiniJavaExpType::Negative:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::INT)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaExpType::NewIntegerArray:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::INT_ARRAY)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case AccessIntegerArray:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::INT)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaExpType::LiteralBoolean:
			case MiniJavaExpType::And:
			case MiniJavaExpType::Or:
			case MiniJavaExpType::Comp:
			case MiniJavaExpType::Negation:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::BOOLEAN)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaExpType::LiteralString:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::STRING)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaExpType::IdType:
			{
				string attVarId = MiniJavaExpTypeCasting::castToId(varAndAtt->getAttExpression())->getId();
				string attVarType = getVariable(tmpClassId, tmpMethodId, attVarId, true)->type;

				switch (varAndAtt->getVarType()->getType())
				{
					case MiniJavaType::INT:
					{
						if (attVarType != "int")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::BOOLEAN:
					{
						if (attVarType != "boolean")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::STRING:
					{
						if (attVarType != "String")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::ID:
					{
						if (attVarType != varAndAtt->getVarType()->getIDType())
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
				}
				break;
			}
			case MiniJavaExpType::NewObject:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::ID)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				else
				{
					string objId = varAndAtt->getVarType()->getIDType();
					string newObjId = MiniJavaExpTypeCasting::castToNewObject(varAndAtt->getAttExpression())->getId();

					if ((objId != newObjId) && !isSubType(objId, newObjId))
					{
						throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
					}
				}

				break;
			}
			case MiniJavaExpType::MethodCall:
			{
				ASTMethodCall* methodCall = MiniJavaExpTypeCasting::castToMethodCall(varAndAtt->getAttExpression());

				string methodId = methodCall->getId();
				string attVarType;

				if (methodCall->superCall())
				{
					ClassInfo* classInfo = getClass(tmpClassId);

					if (classInfo->inheritedClassId == "None")
					{
						throw MiniJavaCompilerException("The class '" + tmpClassId + "' does not inherit from any other class");
					}
					else
					{
						attVarType = getMethod(tmpClassId, methodId, true)->returnType;
					}
				}
				else
				{
					attVarType = getMethod(tmpClassId, methodId, false)->returnType;
				}

				switch (varAndAtt->getVarType()->getType())
				{
					case MiniJavaType::INT:
					{
						if (attVarType != "int")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::BOOLEAN:
					{
						if (attVarType != "boolean")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::STRING:
					{
						if (attVarType != "String")
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
					case MiniJavaType::ID:
					{
						if (attVarType != varAndAtt->getVarType()->getIDType())
						{
							throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
						}

						break;
					}
				}
				break;
			}
			case MiniJavaExpType::Super:
			{
				throw MiniJavaCompilerException("Invalid assignment");
			}
			case MiniJavaExpType::This:
			{
				if (varAndAtt->getVarType()->getType() != MiniJavaType::ID)
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				else
				{
					string classId = getClass(tmpClassId)->id;

					if (varAndAtt->getVarType()->getIDType() != classId)
					{
						throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
					}
				}

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

void ExpressionVisitor::visitMethod(MiniJavaParser::MethodDeclContext* ctx, ASTMethod* methodDecl)
{
	cout << "ExpressionVisitor::visitMethod()" << endl;

	try
	{
		tmpMethodId = methodDecl->getId();

		vector<ASTVarAndAtt*>* varAndAttList = methodDecl->getMethodBody()->getVarAndAttList();

		for (int i = 0; i < varAndAttList->size(); i++)
		{
			visitVarAndAtt(ctx->methodBody()->varDeclAndAtt().at(i), varAndAttList->at(i));
		}

		vector<ASTStatement*>* stmtList = methodDecl->getMethodBody()->getStatementList();

		for (int i = 0; i < stmtList->size(); i++)
		{
			visitMethodStatement(ctx->methodBody()->statement().at(i), stmtList->at(i));
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

void ExpressionVisitor::visitMethodStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt)
{
	cout << "ExpressionVisitor::visitMethodStatement()" << endl;
}
