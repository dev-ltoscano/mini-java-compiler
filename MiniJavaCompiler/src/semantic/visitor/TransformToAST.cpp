#include "semantic/visitor/TransformToAST.h"

using namespace std;

ASTProgram* TransformToAST::visitProgram(MiniJavaParser::ProgContext* ctx)
{
	cout << "TransformToAST::visitProgram()" << endl;

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

ASTMainClass* TransformToAST::visitMainClass(MiniJavaParser::MainClassContext* ctx)
{
	cout << "TransformToAST::visitMainClass()" << endl;

	string mainClassId = ctx->ID().at(0)->toString();

	ASTMethodParams* mainMethodParams = new ASTMethodParams();
	mainMethodParams->addParam(new ASTVar(ctx->ID().at(1)->toString(), new ASTVarType(MiniJavaType::STRING_ARRAY)));

	ASTMethodBody* methodBody = visitMethodBody(ctx->methodBody());

	return new ASTMainClass(mainClassId, new ASTMethod("main", new ASTMethodType(MiniJavaType::VOID), mainMethodParams, methodBody, nullptr));
}

ASTClass* TransformToAST::visitClass(MiniJavaParser::ClassDeclContext* ctx)
{
	cout << "TransformToAST::visitClass()" << endl;

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

ASTMethod* TransformToAST::visitMethod(MiniJavaParser::MethodDeclContext* ctx)
{
	cout << "TransformToAST::visitMethod()" << endl;

	ASTMethodType* methodReturnType = visitMethodType(ctx->methodType());
	ASTMethodParams* methodParams = visitMethodParams(ctx->methodParams());
	ASTMethodBody* methodBody = visitMethodBody(ctx->methodBody());
	ASTMethodReturn* methodReturn = visitMethodReturn(ctx->methodReturn());

	return new ASTMethod(ctx->ID()->toString(), methodReturnType, methodParams, methodBody, methodReturn);
}

ASTMethodType* TransformToAST::visitMethodType(MiniJavaParser::MethodTypeContext* ctx)
{
	cout << "TransformToAST::visitMethodType()" << endl;

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

ASTMethodParams* TransformToAST::visitMethodParams(MiniJavaParser::MethodParamsContext* ctx)
{
	cout << "TransformToAST::visitMethodParams()" << endl;

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

ASTMethodBody* TransformToAST::visitMethodBody(MiniJavaParser::MethodBodyContext* ctx)
{
	cout << "TransformToAST::visitMethodBody()" << endl;

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

ASTMethodReturn* TransformToAST::visitMethodReturn(MiniJavaParser::MethodReturnContext* ctx)
{
	cout << "TransformToAST::visitMethodReturn()" << endl;

	if (ctx)
	{
		return new ASTMethodReturn(visitExpression(ctx->expression()));
	}
	else
	{
		return new ASTMethodReturn(nullptr);
	}
}

ASTMethodCall* TransformToAST::visitMethodCall(MiniJavaParser::MethodCallContext* ctx)
{
	cout << "TransformToAST::visitMethodCall()" << endl;

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

ASTVar* TransformToAST::visitVar(MiniJavaParser::VarDeclContext* ctx)
{
	cout << "TransformToAST::visitVar()" << endl;

	return new ASTVar(ctx->ID()->toString(), visitVarType(ctx->varType()));
}

ASTVarAndAtt* TransformToAST::visitVarAndAtt(MiniJavaParser::VarDeclAndAttContext* ctx)
{
	cout << "TransformToAST::visitVarAndAtt()" << endl;

	return new ASTVarAndAtt(ctx->ID()->toString(), visitVarType(ctx->varType()), visitExpression(ctx->expression()));
}

ASTVarType* TransformToAST::visitVarType(MiniJavaParser::VarTypeContext* ctx)
{
	cout << "TransformToAST::visitVarType()" << endl;

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

ASTStatement* TransformToAST::visitStatement(MiniJavaParser::StatementContext* ctx)
{
	cout << "TransformToAST::visitStatement()" << endl;

	if (ctx->IF() && !ctx->ELSE())
	{
		cout << "visitStatement()::IF()" << endl;
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* ifStmt = visitStatement(ctx->statement().at(0));

		return new ASTIf(expression, ifStmt);
	}
	else if (ctx->IF() && ctx->ELSE())
	{
		cout << "visitStatement()::IFELSE()" << endl;
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* ifStmt = visitStatement(ctx->statement().at(0));
		ASTStatement* elseStmt = visitStatement(ctx->statement().at(1));

		return new ASTIfElse(expression, ifStmt, elseStmt);
	}
	else if (ctx->WHILE())
	{
		cout << "visitStatement()::WHILE()" << endl;
		ASTExpression* expression = visitExpression(ctx->expression().at(0));
		ASTStatement* stmt = visitStatement(ctx->statement().at(0));

		return new ASTWhile(expression, stmt);
	}
	else if (ctx->SOUT())
	{
		cout << "visitStatement()::SOUT()" << endl;
		return new ASTSout(dynamic_cast<ASTLiteralString*>(visitExpression(ctx->expression().at(0))));
	}
	else if (ctx->ASSIGN() && !(ctx->LSB() && ctx->RSB()))
	{
		cout << "visitStatement()::ASSIGN()" << endl;
		return new ASTAssign(new ASTId(ctx->ID()->toString()), visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->ASSIGN() && ctx->LSB() && ctx->RSB())
	{
		cout << "visitStatement()::ASSIGN_ARRAY()" << endl;
		return new ASTAssignArray(new ASTId(ctx->ID()->toString()), visitExpression(ctx->expression().at(0)), visitExpression(ctx->expression().at(1)));
	}
	else if (ctx->methodCall())
	{
		cout << "visitStatement()::METHODCALL()" << endl;
		return visitMethodCall(ctx->methodCall());
	}
	else if(ctx->LCB() && ctx->RCB())
	{
		cout << "visitStatement()::STMTList()" << endl;
		ASTStatementList* statementList = new ASTStatementList();

		vector<MiniJavaParser::StatementContext*> stmtList = ctx->statement();

		for (MiniJavaParser::StatementContext* stmtCtx : stmtList)
		{
			ASTStatement* stmt = visitStatement(stmtCtx);
			statementList->addStatement(stmt);
		}

		return statementList;
	}

	return new ASTStatement();
}

ASTExpression* TransformToAST::visitExpression(MiniJavaParser::ExpressionContext* ctx)
{
	cout << "TransformToAST::visitExpression()" << endl;

	if (ctx->LITBOOL())
	{
		cout << "visitExpression()::LITBOOL()" << endl;
		return new ASTLiteralBoolean((ctx->LITBOOL()->toString() == "true"));
	}
	else if (ctx->LITINT())
	{
		cout << "visitExpression()::LITINT()" << endl;
		return new ASTLiteralInteger(stoi(ctx->LITINT()->toString()));
	}
	else if (ctx->LITSTRING())
	{
		cout << "visitExpression()::LITSTRING()" << endl;
		return new ASTLiteralString(ctx->LITSTRING()->toString());
	}
	else if (ctx->ID() && !ctx->NEW())
	{
		cout << "visitExpression()::ID()" << endl;
		return new ASTId(ctx->ID()->toString());
	}
	else if (ctx->SUPER())
	{
		cout << "visitExpression()::SUPER()" << endl;
		return new ASTSuper();
	}
	else if (ctx->THIS())
	{
		cout << "visitExpression()::THIS()" << endl;
		return new ASTThis();
	}
	else if (ctx->LENGTH())
	{
		cout << "visitExpression()::LENGTH()" << endl;
		return new ASTLength(visitExpression(ctx->expression().at(0)));
	}
	else if (!ctx->DOT() && ctx->methodCall())
	{
		cout << "visitExpression()::METHODCALL1()" << endl;
		return visitMethodCall(ctx->methodCall());
	}
	else if (ctx->DOT() && ctx->methodCall())
	{
		cout << "visitExpression()::METHODCALL2()" << endl;

		ASTMethodCall* methodCall = visitMethodCall(ctx->methodCall());
		methodCall->setParentExpression(visitExpression(ctx->expression().at(0)));

		return methodCall;
	}
	else if (ctx->NEW() && ctx->LSB() && ctx->RSB())
	{
		cout << "visitExpression()::NEW_ARRAY()" << endl;
		return new ASTNewIntegerArray(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->NEW() && ctx->LP() && ctx->RP())
	{
		cout << "visitExpression()::NEW_OBJ()" << endl;
		return new ASTNewObject(new ASTId(ctx->ID()->toString()));
	}
	else if (ctx->SUM() || ctx->MINUS() || ctx->MULT() || ctx->DIV())
	{
		cout << "visitExpression()::ARITHMETIC()" << endl;

		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		if (ctx->SUM())
		{
			cout << "visitExpression()::SUM()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::SUM);
		}
		else if (ctx->MINUS())
		{
			cout << "visitExpression()::SUB()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::SUB);
		}
		else if (ctx->MULT())
		{
			cout << "visitExpression()::MULT()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::MULT);
		}
		else if (ctx->DIV())
		{
			cout << "visitExpression()::DIV()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::DIV);
		}
	}
	else if (ctx->COMP_OP())
	{
		cout << "visitExpression()::COMP_OP()" << endl;

		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		string op = ctx->COMP_OP()->toString();

		if (op == "<")
		{
			cout << "visitExpression()::LESS()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::LESS);
		}
		else if (op == ">")
		{
			cout << "visitExpression()::GREATER()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::GREATER);
		}
		else if (op == "<=")
		{
			cout << "visitExpression()::LEQUAL()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::LEQUAL);
		}
		else if (op == ">=")
		{
			cout << "visitExpression()::GEQUAL()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::GEQUAL);
		}
		else if (op == "==")
		{
			cout << "visitExpression()::EQUAL()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::EQUAL);
		}
		else if (op == "!=")
		{
			cout << "visitExpression()::NEQUAL()" << endl;
			return new ASTComp(firstExpression, secondExpression, MiniJavaOp::NEQUAL);
		}
	}
	else if (ctx->AND())
	{
		cout << "visitExpression()::AND()" << endl;
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		return new ASTAnd(firstExpression, secondExpression);
	}
	else if (ctx->OR())
	{
		cout << "visitExpression()::OR()" << endl;
		ASTExpression* firstExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* secondExpression = visitExpression(ctx->expression().at(1));

		return new ASTOr(firstExpression, secondExpression);
	}
	else if (ctx->NOT())
	{
		cout << "visitExpression()::NEGATION()" << endl;
		return new ASTNegation(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->MINUS())
	{
		cout << "visitExpression()::NEGATIVE()" << endl;
		return new ASTNegative(visitExpression(ctx->expression().at(0)));
	}
	else if (ctx->LSB() && ctx->RSB())
	{
		cout << "visitExpression()::EXPRESSION_ARRAY()" << endl;

		ASTExpression* mainExpression = visitExpression(ctx->expression().at(0));
		ASTExpression* arrayExpression = visitExpression(ctx->expression().at(0));

		return new ASTExpressionArray(mainExpression, arrayExpression);
	}
	else if (ctx->LP() && ctx->RP())
	{
		return visitExpression(ctx->expression().at(0));
	}

	return new ASTExpression();
}

ASTExpressionList* TransformToAST::visitExpList(MiniJavaParser::ExpListContext* ctx)
{
	cout << "TransformToAST::visitExpList()" << endl;

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