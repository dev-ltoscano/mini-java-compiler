#include "semantic/visitor/ExpressionChecker.h"

using namespace std;
using namespace antlrcpp;

Any ExpressionChecker::visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx)
{
	cout << "ExpressionChecker::visitVarDeclAndAtt" << endl;

	try
	{
		string varId = ctx->ID()->toString();
		VarInfo* varInfo = getVariable(ctx, tmpClassId, tmpMethodId, varId);

		Any assignType = visitExpression(ctx->expression());

		if ((varInfo->type != assignType.as<string>()) && !isSubType(varInfo->type, assignType.as<string>()))
		{
            MiniJavaError error = getError(ctx, "The assigned expression does not have the same type as the variable");
			throw MiniJavaCompilerException(&error);
		}

		return varInfo->type;
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		
	}

	return Any(string("None"));
}

Any ExpressionChecker::visitMethodCall(MiniJavaParser::MethodCallContext* ctx)
{
	cout << "ExpressionChecker::visitMethodCall" << endl;
	return visitMethodCall(tmpClassId, ctx);
}

Any ExpressionChecker::visitMethodCall(string classId, MiniJavaParser::MethodCallContext* ctx)
{
	cout << "ExpressionChecker::visitMethodCall" << endl;
	try
	{
		MethodInfo* methodInfo;

		if (ctx->ID().size() == 2)
		{
			VarInfo* varInfo = getVariable(ctx, classId, tmpMethodId, ctx->ID().at(0)->toString());
			methodInfo = getMethod(ctx, varInfo->type, ctx->ID().at(1)->toString());
		}
		else
		{
			methodInfo = getMethod(ctx, classId, ctx->ID().at(0)->toString());
		}

		if (ctx->expList() && (methodInfo->paramInfoMap.size() == 0))
		{
            MiniJavaError error = getError(ctx, "Method '" + methodInfo->id + "' has no parameters");
			throw MiniJavaCompilerException(&error);
		}
		else if (methodInfo->paramInfoMap.size() > 0)
		{
			if (!ctx->expList() || (ctx->expList()->expression().size() != methodInfo->paramInfoMap.size()))
			{
                MiniJavaError error = getError(ctx, "Incorrect number of parameters in method call '" + methodInfo->id + "'");
                throw MiniJavaCompilerException(&error);
			}
			else if (ctx->expList() && (ctx->expList()->expression().size() == methodInfo->paramInfoMap.size()))
			{
				vector<MiniJavaParser::ExpressionContext*> expContextList = ctx->expList()->expression();

				for (int i = 0; i < expContextList.size(); i++)
				{
					Any expressionType = visitExpression(expContextList.at(i));

					string paramKey = methodInfo->paramIndexMap.at(i);
					string paramType = methodInfo->paramInfoMap.at(paramKey)->type;

					if ((paramType != expressionType.as<string>()) && !isSubType(paramType, expressionType.as<string>()))
					{
                        MiniJavaError error = getError(ctx, "Parameter with incorrect type in method '" + methodInfo->id + "'");
                        throw MiniJavaCompilerException(&error);
					}
				}
			}
		}

		return Any(methodInfo->returnType);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{

	}

	return Any(string("None"));
}

Any ExpressionChecker::visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx)
{
	cout << "ExpressionChecker::visitMethodReturn" << endl;

	try
	{
		Any returnType = visitExpression(ctx->expression());
		MethodInfo* methodInfo = getMethod(ctx, tmpClassId, tmpMethodId);

		if ((methodInfo->returnType != returnType.as<string>()) && !isSubType(methodInfo->returnType, returnType.as<string>()))
		{
            MiniJavaError error = getError(ctx, "The return of method '" + tmpMethodId + "' in classe '" + tmpClassId + "' has incorrect type");
            throw MiniJavaCompilerException(&error);
		}
		
		return returnType;
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{

	}

	return Any(string("None"));
}

Any ExpressionChecker::visitStatement(MiniJavaParser::StatementContext* ctx)
{
	cout << "ExpressionChecker::visitStatement" << endl;

	try
	{
		if (ctx->methodCall())
		{
			return visitMethodCall(ctx->methodCall());
		}
		else if (ctx->IF())
		{
			Any expressionType = visitExpression(ctx->expression().at(0));
			
			if (expressionType.as <string>() != "boolean")
			{
                MiniJavaError error = getError(ctx, "The 'if' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a boolean expression");
                throw MiniJavaCompilerException(&error);
			}
		}
		else if (ctx->WHILE())
		{
			Any expressionType = visitExpression(ctx->expression().at(0));

			if (expressionType.as <string>() != "boolean")
			{
                MiniJavaError error = getError(ctx, "The 'while' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a boolean expression");
                throw MiniJavaCompilerException(&error);
			}
		}
		else if (ctx->SOUT())
		{
			Any expressionType = visitExpression(ctx->expression().at(0));

			if (expressionType.as <string>() != "String")
			{
                MiniJavaError error = getError(ctx, "The 'System.out.println' in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a String expression");
                throw MiniJavaCompilerException(&error);
			}
		}
		else if (ctx->ID() && ctx->LSB() && ctx->RSB())
		{
			Any expressionType = visitExpression(ctx->expression().at(0));

			if (expressionType.as <string>() != "int")
			{
                MiniJavaError error = getError(ctx, "The index of vector in method '" + tmpMethodId + "' in class '" + tmpClassId + "' must have a integer expression");
                throw MiniJavaCompilerException(&error);
			}
		}

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		
	}

	return Any(string("None"));
}

Any ExpressionChecker::visitExpression(MiniJavaParser::ExpressionContext* ctx)
{
	cout << "ExpressionChecker::visitExpression" << endl;

	try
	{
		if (ctx->expression().size() == 0)
		{
			if (ctx->NEW())
			{
				if (ctx->ID())
				{
					return Any(string(ctx->ID()->toString()));
				}
			}
			else if (ctx->methodCall())
			{
				return visitMethodCall(ctx->methodCall());
			}
			else if (ctx->SUPER())
			{
				cout << "SUPER" << endl;
			}
			else if (ctx->THIS())
			{
				return Any(tmpClassId);
			}
			else if (ctx->LITINT())
			{
				return Any(string("int"));
			}
			else if (ctx->LITSTRING())
			{
				return Any(string("String"));
			}
			else if (ctx->LITBOOL())
			{
				return Any(string("boolean"));
			}
			else if (ctx->ID())
			{
				return Any(string(getVariable(ctx, tmpClassId, tmpMethodId, ctx->ID()->toString())->type));
			}
		}
		else if (ctx->expression().size() == 1)
		{
			if (ctx->DOT())
			{
				if (ctx->LENGTH())
				{
					cout << "LENGTH!" << endl;
				}
				else
				{
					cout << ctx->expression().at(0) << endl;

					Any expType = visitExpression(ctx->expression().at(0));

					cout << "Aqui: " << expType.as<string>() << endl;
					cout << ctx->expression().at(0) << endl;
					cout << ctx->getText() << endl;

					return visitMethodCall(getClass(ctx, ctx->expression().at(0)->ID()->toString())->id, ctx->methodCall());
				}
			}
			else if (ctx->MINUS())
			{
				return Any(string("int"));
			}
			else if (ctx->NOT())
			{
				return Any(string("boolean"));
			}
			else if (ctx->NEW() && ctx->INT())
			{
				Any expressionType = visitExpression(ctx->expression().at(0));

				if (expressionType.as<string>() != "int")
				{
                    MiniJavaError error = getError(ctx, "The vector size must be an integer");
                    throw MiniJavaCompilerException(&error);
				}

				return Any(string("int[]"));
			}
		}
		else if (ctx->expression().size() == 2)
		{
			if (ctx->SUM() || ctx->MINUS() || ctx->MULT() || ctx->DIV())
			{
				Any expType0 = visit(ctx->expression().at(0));
				Any expType1 = visit(ctx->expression().at(1));

				if (expType0.as<string>() != expType1.as<string>())
				{
                    MiniJavaError error = getError(ctx, "Invalid types for arithmetic operation");
                    throw MiniJavaCompilerException(&error);
				}

				return expType0;
			}
		}

		return visitChildren(ctx);
	}
	catch (MiniJavaCompilerException& ex)
	{
		getErrorListener()->addError(ex.getLine(), ex.getCollumn(), ex.what());
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	return Any(string("None"));
}