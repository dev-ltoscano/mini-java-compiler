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

	return new ASTMainClass(mainClassId, new ASTMethod(mainClassId, new ASTMethodType(MiniJavaType::VOID), mainMethodParams, methodBody, nullptr));
}

ASTClass* TransformToAST::visitClass(MiniJavaParser::ClassDeclContext* ctx)
{
	cout << "TransformToAST::visitClass()" << endl;

	string classId = ctx->ID().at(0)->toString();
	ASTClass* classNode = new ASTClass(classId);

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

	return new ASTMethodReturn(visitExpression(ctx->expression()));
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

	return new ASTExpression();
}