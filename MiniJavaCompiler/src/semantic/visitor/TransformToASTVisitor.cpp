/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "semantic/visitor/TransformToASTVisitor.h"

using namespace std;

ASTProgram* TransformToASTVisitor::visitProgram(MiniJavaParser::ProgContext* ctx)
{
	ASTProgram* program = new ASTProgram();

	ASTMainClass* mainClass = visitMainClass(ctx->mainClass());
	program->setMainClass(mainClass);

	vector<MiniJavaParser::ClassDeclContext*> classList = ctx->classDecl();

	for (MiniJavaParser::ClassDeclContext* classCtx : classList)
	{
		ASTClass* classDecl = visitClass(classCtx);
		program->addClass(classDecl);
	}

	return program;
}

ASTMainClass* TransformToASTVisitor::visitMainClass(MiniJavaParser::MainClassContext* ctx)
{
	string mainClassId = ctx->ID().at(0)->toString();

	ASTMethodParams* mainMethodParams = new ASTMethodParams();
	mainMethodParams->addParam(new ASTVar(ctx->ID().at(1)->toString(), new ASTVarType(MiniJavaType::STRING_ARRAY)));

	ASTMethodBody* methodBody = visitMethodBody(ctx->methodBody());

	return new ASTMainClass(mainClassId, new ASTMethod("main", new ASTMethodType(MiniJavaType::VOID), mainMethodParams, methodBody, nullptr));
}

ASTClass* TransformToASTVisitor::visitClass(MiniJavaParser::ClassDeclContext* ctx)
{
	string classId = ctx->ID().at(0)->toString();
	string inheritedClass = "None";

	if (ctx->EXTENDS())
	{
		inheritedClass = ctx->ID().at(1)->toString();
	}

	ASTClass* classNode = new ASTClass(classId, inheritedClass);

	vector<MiniJavaParser::VarDeclContext*> varList = ctx->varDecl();

	for (MiniJavaParser::VarDeclContext* varCtx : varList)
	{
		ASTVar* var = visitVar(varCtx);
		classNode->addVar(var);
	}

	vector<MiniJavaParser::VarDeclAndAttContext*> varAndAttList = ctx->varDeclAndAtt();

	for (MiniJavaParser::VarDeclAndAttContext* varCtx : varAndAttList)
	{
		ASTVarAndAtt* varAndAtt = visitVarAndAtt(varCtx);
		classNode->addVarAndAtt(varAndAtt);
	}

	vector<MiniJavaParser::MethodDeclContext*> methodList = ctx->methodDecl();

	for (MiniJavaParser::MethodDeclContext* methodCtx : methodList)
	{
		ASTMethod* method = visitMethod(methodCtx);
		classNode->addMethod(method);
	}

	return classNode;
}

ASTMethod* TransformToASTVisitor::visitMethod(MiniJavaParser::MethodDeclContext* ctx)
{
	ASTMethodType* methodReturnType = visitMethodType(ctx->methodType());
	ASTMethodParams* methodParams = visitMethodParams(ctx->methodParams());
	ASTMethodBody* methodBody = visitMethodBody(ctx->methodBody());
	ASTMethodReturn* methodReturn = visitMethodReturn(ctx->methodReturn());

	return new ASTMethod(ctx->ID()->toString(), methodReturnType, methodParams, methodBody, methodReturn);
}

ASTMethodType* TransformToASTVisitor::visitMethodType(MiniJavaParser::MethodTypeContext* ctx)
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
		return new ASTMethodType(MiniJavaType::ID, ctx->ID()->toString());
	}
}

ASTMethodParams* TransformToASTVisitor::visitMethodParams(MiniJavaParser::MethodParamsContext* ctx)
{
	ASTMethodParams* methodParams = new ASTMethodParams();

	if (ctx)
	{
		std::vector<antlr4::tree::TerminalNode*> varList = ctx->ID();

		for (int i = 0; i < varList.size(); i++)
		{
			std::string varId = varList.at(i)->toString();
			ASTVarType* varType = visitVarType(ctx->varType().at(i));

			methodParams->addParam(new ASTVar(varId, varType));
		}
	}

	return methodParams;
}

ASTMethodBody* TransformToASTVisitor::visitMethodBody(MiniJavaParser::MethodBodyContext* ctx)
{
	ASTMethodBody* methodBody = new ASTMethodBody();

	vector<MiniJavaParser::VarDeclContext*> varList = ctx->varDecl();

	for (MiniJavaParser::VarDeclContext* varCtx : varList)
	{
		ASTVar* var = visitVar(varCtx);
		methodBody->addVar(var);
	}

	vector<MiniJavaParser::VarDeclAndAttContext*> varAndAttList = ctx->varDeclAndAtt();

	for (MiniJavaParser::VarDeclAndAttContext* varCtx : varAndAttList)
	{
		ASTVarAndAtt* varAndAtt = visitVarAndAtt(varCtx);
		methodBody->addVarAndAtt(varAndAtt);
	}

	vector<MiniJavaParser::StatementContext*> stmtList = ctx->statement();

	for (MiniJavaParser::StatementContext* stmtCtx : stmtList)
	{
		ASTStatement* stmt = visitStatement(stmtCtx);
		methodBody->addStatement(stmt);
	}

	return methodBody;
}

ASTMethodReturn* TransformToASTVisitor::visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx)
{
	if (ctx)
	{
		return new ASTMethodReturn(visitExpression(ctx->expression()));
	}
	else
	{
		return new ASTMethodReturn(nullptr);
	}
}

ASTMethodCall* TransformToASTVisitor::visitMethodCall(MiniJavaParser::MethodCallContext* ctx)
{
	ASTSuper* superPtr = nullptr;
	ASTThis* thisPtr = nullptr;
	
	if (ctx->SUPER())
	{
		superPtr = new ASTSuper();
	}
	else if (ctx->THIS())
	{
		thisPtr = new ASTThis();
	}

	ASTId* id = nullptr;

	if (ctx->ID().size() == 1)
	{
		id = new ASTId(ctx->ID().at(0)->toString());
	}
	else
	{
		id = new ASTId(ctx->ID().at(1)->toString());
	}

	ASTExpressionList* params = visitExpList(ctx->expList());

	return new ASTMethodCall(superPtr, thisPtr, id, params);
}

ASTVar* TransformToASTVisitor::visitVar(MiniJavaParser::VarDeclContext* ctx)
{
	return new ASTVar(ctx->ID()->toString(), visitVarType(ctx->varType()));
}

ASTVarAndAtt* TransformToASTVisitor::visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx)
{
	return new ASTVarAndAtt(ctx->ID()->toString(), visitVarType(ctx->varType()), visitExpression(ctx->expression()));
}

ASTVarType* TransformToASTVisitor::visitVarType(MiniJavaParser::VarTypeContext* ctx)
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
		return new ASTVarType(MiniJavaType::ID, ctx->ID()->toString());
	}
}

ASTStatement* TransformToASTVisitor::visitStatement(MiniJavaParser::StatementContext* ctx)
{
	if (ctx->IF() && !ctx->ELSE())
	{
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* ifStmt = visitStatement(ctx->statement().at(0));

		return new ASTIf(expression, ifStmt);
	}
	else if (ctx->IF() && ctx->ELSE())
	{
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* ifStmt = visitStatement(ctx->statement().at(0));
		ASTStatement* elseStmt = visitStatement(ctx->statement().at(1));

		return new ASTIfElse(expression, ifStmt, elseStmt);
	}
	else if (ctx->WHILE())
	{
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* stmt = visitStatement(ctx->statement().at(0));

		return new ASTWhile(expression, stmt);
	}
	else if (ctx->SOUT())
	{
		return new ASTSout(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->ASSIGN() && !(ctx->LSB() && ctx->RSB()))
	{
		return new ASTAssign(new ASTId(ctx->ID()->toString()), visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->ASSIGN() && ctx->LSB() && ctx->RSB())
	{
		return new ASTAssignArray(new ASTId(ctx->ID()->toString()), visitExpression(ctx->expression().at(0)), visitExpression(ctx->expression().at(1)));
	}
	else if (ctx->methodCall())
	{
		if (ctx->methodCall()->SUPER() && ctx->methodCall()->DOT())
		{
			ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
			methodCall->setParentExpression(new ASTSuper());

			return methodCall;
		}
		else if (ctx->methodCall()->THIS() && ctx->methodCall()->DOT())
		{
			ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
			methodCall->setParentExpression(new ASTThis());

			return methodCall;
		}
		else if ((ctx->methodCall()->ID().size() == 2) && ctx->methodCall()->DOT())
		{
			ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
			methodCall->setParentExpression(new ASTId(ctx->methodCall()->ID().at(0)->toString()));

			return methodCall;
		}
		else
		{
			return visitMethodCall(ctx->methodCall());
		}
	}
	else if(ctx->LCB() && ctx->RCB())
	{
		ASTStatementList* statementList = new ASTStatementList();

		vector<MiniJavaParser::StatementContext*> stmtList = ctx->statement();

		for (MiniJavaParser::StatementContext* stmtCtx : stmtList)
		{
			ASTStatement* stmt = visitStatement(stmtCtx);
			statementList->addStatement(stmt);
		}

		return statementList;
	}
	else
	{
		throw runtime_error("Unknown statement");
	}
}

ASTExpression* TransformToASTVisitor::visitExpression(MiniJavaParser::ExpressionContext* ctx)
{
	if (ctx->LITBOOL())
	{
		return new ASTLiteralBoolean((ctx->LITBOOL()->toString() == "true"));
	}
	else if (ctx->LITINT())
	{
		return new ASTLiteralInteger(stoi(ctx->LITINT()->toString()));
	}
	else if (ctx->LITSTRING())
	{
		return new ASTLiteralString(ctx->LITSTRING()->toString());
	}
	else if (ctx->ID() && !ctx->NEW())
	{
		return new ASTId(ctx->ID()->toString());
	}
	else if (ctx->SUPER())
	{
		return new ASTSuper();
	}
	else if (ctx->THIS())
	{
		return new ASTThis();
	}
	else if (ctx->LENGTH())
	{
		return new ASTLength(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->DOT() && ctx->methodCall())
	{
		ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
		methodCall->setParentExpression(visitExpression(ctx->expression().at(0)));

		return methodCall;
	}
	else if (!ctx->DOT() && ctx->methodCall() && ctx->methodCall()->ID().size() == 2)
	{
		ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
		methodCall->setParentExpression(new ASTId(ctx->methodCall()->ID().at(0)->toString()));

		return methodCall;
	}
	else if (!ctx->DOT() && ctx->methodCall())
	{
		return visitMethodCall(ctx->methodCall());
	}
	else if (ctx->NEW() && ctx->LSB() && ctx->RSB())
	{
		return new ASTNewIntegerArray(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->NEW() && ctx->LP() && ctx->RP())
	{
		return new ASTNewObject(new ASTId(ctx->ID()->toString()));
	}
	else if (ctx->MINUS() && (ctx->expression().size() == 1))
	{
		return new ASTNegative(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->SUM() || ctx->MINUS() || ctx->MULT() || ctx->DIV())
	{
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		if (ctx->SUM())
		{
			return new ASTArithmetic(firstExpression, secondExpression, MiniJavaOp::SUM);
		}
		else if (ctx->MINUS())
		{
			return new ASTArithmetic(firstExpression, secondExpression, MiniJavaOp::SUB);
		}
		else if (ctx->MULT())
		{
			return new ASTArithmetic(firstExpression, secondExpression, MiniJavaOp::MULT);
		}
		else if (ctx->DIV())
		{
			return new ASTArithmetic(firstExpression, secondExpression, MiniJavaOp::DIV);
		}
	}
	else if (ctx->COMP_OP())
	{
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		string op = ctx->COMP_OP()->toString();

		if (op == "<")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::LESS);
		}
		else if (op == ">")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::GREATER);
		}
		else if (op == "<=")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::LEQUAL);
		}
		else if (op == ">=")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::GEQUAL);
		}
		else if (op == "==")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::EQUAL);
		}
		else if (op == "!=")
		{
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::NEQUAL);
		}
	}
	else if (ctx->AND())
	{
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		return new ASTAnd(firstExpression, secondExpression);
	}
	else if (ctx->OR())
	{
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		return new ASTOr(firstExpression, secondExpression);
	}
	else if (ctx->NOT())
	{
		return new ASTNegation(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->LSB() && ctx->RSB())
	{
		ASTExpression* mainExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* arrayExpression = visitExpression(ctx->expression().at(1));

		return new ASTAccessIntegerArray(mainExpression, arrayExpression);
	}
	else if (ctx->LP() && ctx->RP())
	{
		return visitExpression(ctx->expression().at(0));
	}
	else
	{
		throw runtime_error("Unknown expression");
	}
}

ASTExpressionList* TransformToASTVisitor::visitExpList(MiniJavaParser::ExpListContext* ctx)
{
	ASTExpressionList* expressionList = new ASTExpressionList();

	if (ctx)
	{
		vector<MiniJavaParser::ExpressionContext*> expList = ctx->expression();

		for (MiniJavaParser::ExpressionContext* expCtx : expList)
		{
			expressionList->addExpression(visitExpression(expCtx));
		}
	}

	return expressionList;
}