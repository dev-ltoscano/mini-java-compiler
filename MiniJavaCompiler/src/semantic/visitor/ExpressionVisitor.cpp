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

		vector<ASTStatement*>* stmtList = mainClassDecl->getMainMethod()->getMethodBody()->getStatementList();

		for (int i = 0; i < stmtList->size(); i++)
		{
			visitStatement(ctx->methodBody()->statement().at(i), stmtList->at(i));
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

		if (checkCircularHierarchy(classDecl->getId()))
		{
			throw MiniJavaCompilerException("The class '" + tmpClassId + "' has circular hierarchy");
		}

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
		string expType = visitExpression(ctx->expression(), varAndAtt->getAttExpression());
		
		if (varAndAtt->getVarType()->getType() != MiniJavaType::ID)
		{
			if (typeToString(varAndAtt->getVarType()->getType()) != expType)
			{
				throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
			}
		}
		else
		{
			if (varAndAtt->getVarType()->getIDType() != expType)
			{
				throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
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
			visitStatement(ctx->methodBody()->statement().at(i), stmtList->at(i));
		}

		methodDecl->getMethodParams()->getParamList();
		visitMethodReturn(ctx->methodReturn(), methodDecl->getMethodReturn());
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

void ExpressionVisitor::visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx, ASTMethodReturn* methodReturnDecl)
{
	cout << "ExpressionVisitor::visitMethodReturn()" << endl;

	try
	{
		MethodInfo* methodInfo = getMethod(tmpClassId, tmpMethodId, true);

		if (!ctx && (methodInfo->returnType == "void"))
		{
			return;
		}
		else if (!ctx && (methodInfo->returnType != "void"))
		{
			throw MiniJavaCompilerException("The method '" + tmpMethodId + "' has no return expression");
		}

		ASTExpression* returnExpression = methodReturnDecl->getReturnExpression();
		string returnExpType = visitExpression(ctx->expression(), returnExpression);

		if (methodInfo->returnType != returnExpType)
		{
			throw MiniJavaCompilerException("The return of method '" + tmpMethodId + "' in classe '" + tmpClassId + "' has incorrect type");
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (!ctx)
		{
			throw ex;
		}
		else
		{
			if (ex.getLine() == 0)
			{
				ex.setLine(getErrorLine(ctx->getStart()));
				ex.setCollumn(getErrorCollumn(ctx->getStart()));
			}

			errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
		}
	}
}

void ExpressionVisitor::visitMethodCallParams(MiniJavaParser::MethodCallContext* ctx, ASTMethodCall* methodCall)
{
	cout << "ExpressionVisitor::visitMethodCallParams()" << endl;

	try
	{
		string methodId = methodCall->getId();
		MethodInfo* methodInfo;

		if (methodCall->superCall())
		{
			ClassInfo* classInfo = getClass(tmpClassId);

			if (classInfo->inheritedClassId == "None")
			{
				throw MiniJavaCompilerException("The class '" + tmpClassId + "' does not inherit from any other class");
			}
			else
			{
				methodInfo = getMethod(tmpClassId, methodId, true);
			}
		}
		else if (methodCall->thisCall())
		{
			methodInfo = getMethod(tmpClassId, methodId, false);
		}
		else if (methodCall->getParentExpression())
		{
			string callVarType = visitExpression(tmpExpCtx, methodCall->getParentExpression());
			methodInfo = getMethod(callVarType, methodId, true);
		}
		else
		{
			methodInfo = getMethod(tmpClassId, methodId, true);
		}

		if (!ctx->expList() && methodInfo->paramInfoMap.empty())
		{
			return;
		}
		else if (!ctx->expList() && methodInfo->paramInfoMap.empty())
		{
			throw MiniJavaCompilerException("Incorrect number of parameters in method call '" + methodInfo->id + "'");
		}

		vector<ASTExpression*>* callParamList = methodCall->getParams()->getExpressionList();
		
		if (methodInfo->paramInfoMap.size() != callParamList->size())
		{
			throw MiniJavaCompilerException("Incorrect number of parameters in method call '" + methodInfo->id + "'");
		}
		else
		{
			for (int i = 0; i < callParamList->size(); i++)
			{
				string paramType = visitExpression(tmpExpCtx, callParamList->at(i));

				if (paramType != methodInfo->paramInfoMap.at(methodInfo->paramIndexMap.at(i))->type)
				{
					throw MiniJavaCompilerException("Parameter with incorrect type in method '" + methodInfo->id + "'");
				}
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

void ExpressionVisitor::visitStatement(MiniJavaParser::StatementContext* ctx, ASTStatement* stmt)
{
	cout << "ExpressionVisitor::visitStatement()" << endl;

	try
	{
		switch (stmt->getStatementType())
		{
			case MiniJavaStmtType::IF:
			{
				ASTIf* ifStmt = MiniJavaStmtTypeCasting::castToIf(stmt);
				string expType = visitExpression(ctx->expression().at(0), ifStmt->getExpression());

				if (expType != "boolean")
				{
					throw MiniJavaCompilerException("The 'if' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a boolean expression");
				}

				visitStatement(ctx->statement().at(0), ifStmt->getStatement());
				break;
			}
			case MiniJavaStmtType::IFELSE:
			{
				ASTIfElse* ifStmt = MiniJavaStmtTypeCasting::castToIfElse(stmt);
				string expType = visitExpression(ctx->expression().at(0), ifStmt->getExpression());

				if (expType != "boolean")
				{
					throw MiniJavaCompilerException("The 'if' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a boolean expression");
				}

				visitStatement(ctx->statement().at(0), ifStmt->getIfStatement());
				visitStatement(ctx->statement().at(1), ifStmt->getElseStatement());
				break;
			}
			case MiniJavaStmtType::WHILE:
			{
				ASTWhile* whileStmt = MiniJavaStmtTypeCasting::castToWhile(stmt);
				string expType = visitExpression(ctx->expression().at(0), whileStmt->getExpression());

				if (expType != "boolean")
				{
					throw MiniJavaCompilerException("The 'while' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a boolean expression");
				}

				visitStatement(ctx->statement().at(0), whileStmt->getStatement());
				break;
			}
			case MiniJavaStmtType::SOUT:
			{
				ASTSout* soutStmt = MiniJavaStmtTypeCasting::castToSout(stmt);
				string expType = visitExpression(ctx->expression().at(0), soutStmt->getExpression());

				if ((expType != "String") && (expType != "int"))
				{
					throw MiniJavaCompilerException("The 'System.out.println' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a String or Integer expression");
				}
				break;
			}
			case MiniJavaStmtType::ASSIGN:
			{
				ASTAssign* assignStmt = MiniJavaStmtTypeCasting::castToAssign(stmt);
				
				string expType = visitExpression(ctx->expression().at(0), assignStmt->getExpression());

				string varId = assignStmt->getId()->getId();
				string varType = getVariable(tmpClassId, tmpMethodId, varId, true)->type;

				if ((varType != expType) && !isSubType(varType, expType))
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaStmtType::ASSIGN_ARRAY:
			{
				ASTAssignArray* assignStmt = MiniJavaStmtTypeCasting::castToAssignArray(stmt);

				string indexExpType = visitExpression(ctx->expression().at(0), assignStmt->getArrayExpression());
				string expType = visitExpression(ctx->expression().at(0), assignStmt->getExpression());

				getVariable(tmpClassId, tmpMethodId, assignStmt->getId()->getId(), true);

				if (indexExpType != "int")
				{
					throw MiniJavaCompilerException("The index of vector in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a integer expression");
				}

				if (expType != "int")
				{
					throw MiniJavaCompilerException("The assigned expression does not have the same type as the variable");
				}
				break;
			}
			case MiniJavaStmtType::METHODCALL:
			{
				ASTMethodCall* callStmt = MiniJavaStmtTypeCasting::castToMethodCall(stmt);
				visitMethodCallParams(ctx->methodCall(), callStmt);
				break;
			}
			case MiniJavaStmtType::STMTLIST:
			{
				ASTStatementList* astStmtList = MiniJavaStmtTypeCasting::castToStmtList(stmt);
				vector<ASTStatement*>* stmtList = astStmtList->getStatementList();

				for (int i = 0; i < stmtList->size(); i++)
				{
					visitStatement(ctx->statement().at(i), stmtList->at(i));
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

string ExpressionVisitor::visitExpression(MiniJavaParser::ExpressionContext* ctx, ASTExpression* exp)
{
	cout << "ExpressionVisitor::visitExpression()" << endl;

	try
	{
		tmpExpCtx = ctx;

		switch (exp->getExpressionType())
		{
			case MiniJavaExpType::LiteralInteger:
			{
				return "int";
			}
			case MiniJavaExpType::LiteralBoolean:
			{
				return "boolean";
			}
			case MiniJavaExpType::LiteralString:
			{
				return "String";
			}
			case MiniJavaExpType::IdType:
			{
				ASTId* varExp = MiniJavaExpTypeCasting::castToId(exp);
				string varId = varExp->getId();

				return getVariable(tmpClassId, tmpMethodId, varId, true)->type;
			}
			case MiniJavaExpType::NewObject:
			{
				ASTNewObject* newObj = MiniJavaExpTypeCasting::castToNewObject(exp);
				return newObj->getId();
			}
			case MiniJavaExpType::NewIntegerArray:
			{
				return "int[]";
			}
			case MiniJavaExpType::Arithmetic:
			{
				ASTArithmetic* arithmetic = MiniJavaExpTypeCasting::castToArithmetic(exp);

				string firstExpType = visitExpression(tmpExpCtx, arithmetic->getFirstExpression());
				string secondExpType = visitExpression(tmpExpCtx, arithmetic->getSecondExpression());

				if (firstExpType != secondExpType)
				{
					throw MiniJavaCompilerException("Invalid types for arithmetic operation");
				}

				return "int";
			}
			case MiniJavaExpType::And:
			{
				return "boolean";
			}
			case MiniJavaExpType::Or:
			{
				return "boolean";
			}
			case MiniJavaExpType::Comp:
			{
				return "boolean";
			}
			case MiniJavaExpType::Negation:
			{
				return "boolean";
			}
			case MiniJavaExpType::Negative:
			{
				return "int";
			}
			case MiniJavaExpType::Length:
			{
				return "int";
			}
			case MiniJavaExpType::MethodCall:
			{
				ASTMethodCall* methodCall = MiniJavaExpTypeCasting::castToMethodCall(exp);

				visitMethodCallParams((MiniJavaParser::MethodCallContext*)ctx, methodCall);

				string methodId = methodCall->getId();
				string methodReturnType;

				if (methodCall->superCall())
				{
					ClassInfo* classInfo = getClass(tmpClassId);

					if (classInfo->inheritedClassId == "None")
					{
						throw MiniJavaCompilerException("The class '" + tmpClassId + "' does not inherit from any other class");
					}
					else
					{
						methodReturnType = getMethod(tmpClassId, methodId, true)->returnType;
					}
				}
				else if (methodCall->thisCall())
				{
					methodReturnType = getMethod(tmpClassId, methodId, false)->returnType;
				}
				else
				{
					if (methodCall->getParentExpression())
					{
						if (methodCall->getParentExpression()->getExpressionType() == MiniJavaExpType::NewObject)
						{
							ASTNewObject* newObj = MiniJavaExpTypeCasting::castToNewObject(methodCall->getParentExpression());
							methodReturnType = getMethod(newObj->getId(), methodId, true)->returnType;
						}
						else if (methodCall->getParentExpression()->getExpressionType() == MiniJavaExpType::IdType)
						{
							string varId = MiniJavaExpTypeCasting::castToId(methodCall->getParentExpression())->getId();
							string varClassType = getVariable(tmpClassId, tmpMethodId, varId, true)->type;

							methodReturnType = getMethod(varClassType, methodId, true)->returnType;
						}
						else if (methodCall->getParentExpression()->getExpressionType() == MiniJavaExpType::MethodCall)
						{
							string callReturnType = visitExpression(tmpExpCtx, methodCall->getParentExpression());
							methodReturnType = getMethod(callReturnType, methodId, true)->returnType;
						}
						else
						{
							return visitExpression(tmpExpCtx, methodCall->getParentExpression());
						}
					}
					else
					{
						methodReturnType = getMethod(tmpClassId, methodId, false)->returnType;
					}
				}

				return methodReturnType;
			}
			case MiniJavaExpType::AccessIntegerArray:
			{
				ASTAccessIntegerArray* accessArray = MiniJavaExpTypeCasting::castToExpressionArray(exp);

				string accessExpType = visitExpression(tmpExpCtx, accessArray->getArrayExpression());

				if (accessExpType != "int")
				{
					throw MiniJavaCompilerException("The index of vector in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a integer expression");
				}

				return "int";
			}
			case MiniJavaExpType::Super:
			{
				throw MiniJavaCompilerException("Use of 'super' not allowed");
			}
			case MiniJavaExpType::This:
			{
				return tmpClassId;
			}
		}
	}
	catch (MiniJavaCompilerException& ex)
	{
		if (!ctx)
		{
			throw ex;
		}
		else
		{
			if (ex.getLine() == 0)
			{
				ex.setLine(getErrorLine(ctx->getStart()));
				ex.setCollumn(getErrorCollumn(ctx->getStart()));
			}

			errorListener->addError(ex.getLine(), ex.getCollumn(), ex.what());
		}
	}

	return "None";
}
