/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "codegen/visitor/CodeGenVisitor.h"

#include <iostream>

using namespace std;

AsmFile* CodeGenVisitor::visitProgram()
{
	visitMainClass(astProgram->getMainClass());

	return asmFile;
}

void CodeGenVisitor::visitMainClass(ASTMainClass* mainClassDecl)
{
	cout << "CodeGenVisitor::visitMainClass()" << endl;

	tmpClassId = mainClassDecl->getId();
	tmpMethodId = mainClassDecl->getMainMethod()->getId();

	asmFile->setGlobalFunctionLabel(tmpMethodId);
	asmFile->addFunction(new AsmFunction(tmpMethodId));

	vector<ASTVar*>* varList = mainClassDecl->getMainMethod()->getMethodBody()->getVarList();

	for (int i = 0; i < varList->size(); i++)
	{
		visitVar(varList->at(i));
	}

	vector<ASTVarAndAtt*>* varAttList = mainClassDecl->getMainMethod()->getMethodBody()->getVarAndAttList();

	for (int i = 0; i < varAttList->size(); i++)
	{
		visitVarAndAtt(varAttList->at(i));
	}

	vector<ASTStatement*>* stmtList = mainClassDecl->getMainMethod()->getMethodBody()->getStatementList();

	for (int i = 0; i < stmtList->size(); i++)
	{
		visitStatement(stmtList->at(i));
	}

	AsmFunction* exitFunction = asmFile->getFunction(tmpMethodId);
	exitFunction->addBodyInstruction("mov rax, 60");
	exitFunction->addBodyInstruction("xor rdi, rdi");
	exitFunction->addBodyInstruction("syscall");
}

void CodeGenVisitor::visitClass(ASTClass* classDecl)
{
	cout << "CodeGenVisitor::visitClass()" << endl;
}

void CodeGenVisitor::visitVar(ASTVar* var)
{
	cout << "CodeGenVisitor::visitVar()" << endl;
	AsmCodeGen::addUninitializedVar(asmFile, var->getId(), var->getVarType()->getType());
}

void CodeGenVisitor::visitVarAndAtt(ASTVarAndAtt* varAndAtt)
{
	cout << "CodeGenVisitor::visitVarAndAtt()" << endl;
	
	string varId = varAndAtt->getId();
	AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);

	switch (varAndAtt->getAttExpression()->getExpressionType())
	{
		case MiniJavaExpType::LiteralInteger:
		{
			ASTLiteralInteger* litInt = MiniJavaExpTypeCasting::castToLiteralInteger(varAndAtt->getAttExpression());

			AsmCodeGen::addUninitializedVar(asmFile, varId, varAndAtt->getVarType()->getType());
			asmFunction->addBodyInstruction("mov qword [" + varId + "], " + to_string(litInt->getInteger()));
			break;
		}
		case MiniJavaExpType::LiteralString:
		{
			ASTLiteralString* litString = MiniJavaExpTypeCasting::castToLiteralString(varAndAtt->getAttExpression());

			AsmCodeGen::addConstantVar(asmFile, varId, litString->getString(), varAndAtt->getVarType()->getType());
			break;
		}
		case MiniJavaExpType::LiteralBoolean:
		{
			ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(varAndAtt->getAttExpression());

			AsmCodeGen::addUninitializedVar(asmFile, varAndAtt->getId(), varAndAtt->getVarType()->getType());
			asmFunction->addBodyInstruction("mov qword [" + varId + "], " + to_string(litBool->getBoolean()));
			break;
		}
		case MiniJavaExpType::IdType:
		{
			ASTId* idExp = MiniJavaExpTypeCasting::castToId(varAndAtt->getAttExpression());

			AsmCodeGen::addUninitializedVar(asmFile, varAndAtt->getId(), varAndAtt->getVarType()->getType());
			asmFunction->addBodyInstruction("mov qword rdi, [" + idExp->getId() + "]");
			asmFunction->addBodyInstruction("mov qword [" + varId + "], rdi");
			break;
		}
		case MiniJavaExpType::Arithmetic:
		{
			ASTArithmetic* arithmeticExp = MiniJavaExpTypeCasting::castToArithmetic(varAndAtt->getAttExpression());

			visitExpression(arithmeticExp);

			AsmCodeGen::addUninitializedVar(asmFile, varAndAtt->getId(), varAndAtt->getVarType()->getType());
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("mov qword [" + varId + "], rdi");
			asmFunction->addBodyInstruction("add rsp, 8");
			break;
		}
	}
}

void CodeGenVisitor::visitMethod(ASTMethod* methodDecl)
{
	cout << "CodeGenVisitor::visitMethod()" << endl;
}

void CodeGenVisitor::visitMethodReturn(ASTMethodReturn* methodReturnDecl)
{
	cout << "CodeGenVisitor::visitMethodReturn()" << endl;
}

void CodeGenVisitor::visitMethodCallParams(ASTMethodCall* methodCall)
{
	cout << "CodeGenVisitor::visitMethodCallParams()" << endl;
}

void CodeGenVisitor::visitStatement(ASTStatement* stmt)
{
	cout << "CodeGenVisitor::visitStatement()" << endl;
	AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);

	switch (stmt->getStatementType())
	{
		case MiniJavaStmtType::IF:
		{
			cout << "CodeGenVisitor::visitStatement::IF()" << endl;
			ASTIf* ifStmt = MiniJavaStmtTypeCasting::castToIf(stmt);

			switch (ifStmt->getExpression()->getExpressionType())
			{
				case MiniJavaExpType::LiteralBoolean:
				{
					ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(ifStmt->getExpression());

					if (litBool->getBoolean())
					{
						visitStatement(ifStmt->getStatement());
					}
					break;
				}
				case MiniJavaExpType::IdType:
				{
					ASTId* idExp = MiniJavaExpTypeCasting::castToId(ifStmt->getExpression());
					string varId = idExp->getId();

					string jmpIfLabel = tmpMethodId + "_if_" + to_string(tmpId++);
					string jmpContLabel = tmpMethodId + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);
					asmFunction->addBodyInstruction("cmp [" + varId + "], 1");
					asmFunction->addBodyInstruction("je " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpMethodId = jmpIfLabel;

					visitStatement(ifStmt->getStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					tmpMethodId = jmpContLabel;

					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					break;
				}
			}
			break;
		}
		case MiniJavaStmtType::IFELSE:
		{
			cout << "CodeGenVisitor::visitStatement::IFELSE()" << endl;
			ASTIfElse* ifElseStmt = MiniJavaStmtTypeCasting::castToIfElse(stmt);

			switch (ifElseStmt->getExpression()->getExpressionType())
			{
				case MiniJavaExpType::LiteralBoolean:
				{
					ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(ifElseStmt->getExpression());

					if (litBool->getBoolean())
					{
						visitStatement(ifElseStmt->getIfStatement());
					}
					else
					{
						visitStatement(ifElseStmt->getElseStatement());
					}
					break;
				}
				case MiniJavaExpType::IdType:
				{
					ASTId* idExp = MiniJavaExpTypeCasting::castToId(ifElseStmt->getExpression());
					string varId = idExp->getId();

					string jmpIfLabel = tmpMethodId + "_if_" + to_string(tmpId++);
					string jmpElseLabel = tmpMethodId + "_else_" + to_string(tmpId++);
					string jmpContLabel = tmpMethodId + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);
					asmFunction->addBodyInstruction("cmp [" + varId + "], 1");
					asmFunction->addBodyInstruction("je " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpMethodId = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpMethodId = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpMethodId = jmpContLabel;

					break;
				}
				case MiniJavaExpType::And:
				{
					ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(ifElseStmt->getExpression());

					string jmpIfLabel = tmpMethodId + "_if_" + to_string(tmpId++);
					string jmpElseLabel = tmpMethodId + "_else_" + to_string(tmpId++);
					string jmpContLabel = tmpMethodId + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(andExp);

					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpMethodId = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpMethodId = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpMethodId = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Or:
				{
					ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(ifElseStmt->getExpression());

					string jmpIfLabel = tmpMethodId + "_if_" + to_string(tmpId++);
					string jmpElseLabel = tmpMethodId + "_else_" + to_string(tmpId++);
					string jmpContLabel = tmpMethodId + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(andExp);

					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpMethodId = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpMethodId = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpMethodId = jmpContLabel;
					break;
				}
			}

			break;
		}
		case MiniJavaStmtType::WHILE:
		{
			cout << "CodeGenVisitor::visitStatement::WHILE()" << endl;
			break;
		}
		case MiniJavaStmtType::SOUT:
		{
			cout << "CodeGenVisitor::visitStatement::SOUT()" << endl;
			asmFile->addExternFunction("printf");
			
			ASTSout* soutStmt = MiniJavaStmtTypeCasting::castToSout(stmt);

			switch (soutStmt->getExpression()->getExpressionType())
			{
				case MiniJavaExpType::LiteralString:
				{
					ASTLiteralString* litString = MiniJavaExpTypeCasting::castToLiteralString(soutStmt->getExpression());

					asmFile->addData("msg_" + to_string(tmpId) + ": db " + litString->getString() + ", 0");
					AsmCodeGen::soutString(asmFunction, tmpId++);
					break;
				}
				case MiniJavaExpType::LiteralInteger:
				{
					ASTLiteralInteger* litInteger = MiniJavaExpTypeCasting::castToLiteralInteger(soutStmt->getExpression());
					AsmCodeGen::soutInteger(asmFunction, litInteger->getInteger());
					break;
				}
				case MiniJavaExpType::IdType:
				{
					ASTId* varId = MiniJavaExpTypeCasting::castToId(soutStmt->getExpression());

					VarInfo* varInfo = getVariable(tmpClassId, tmpMethodId, varId->getId(), true);
					AsmCodeGen::soutVar(asmFunction, varId->getId(), varInfo->type);
					break;
				}
			}
			break;
		}
		case MiniJavaStmtType::ASSIGN:
		{
			cout << "CodeGenVisitor::visitStatement::ASSIGN()" << endl;
			ASTAssign* assignStmt = MiniJavaStmtTypeCasting::castToAssign(stmt);

			string varId = assignStmt->getId()->getId();

			switch (assignStmt->getExpression()->getExpressionType())
			{
				case MiniJavaExpType::LiteralInteger:
				{
					ASTLiteralInteger* litInt = MiniJavaExpTypeCasting::castToLiteralInteger(assignStmt->getExpression());
					asmFunction->addBodyInstruction("mov qword [" + varId + "], " + to_string(litInt->getInteger()));
					break;
				}
				case MiniJavaExpType::LiteralString:
				{
					ASTLiteralString* litString = MiniJavaExpTypeCasting::castToLiteralString(assignStmt->getExpression());
					AsmCodeGen::addConstantVar(asmFile, varId, litString->getString(), MiniJavaType::STRING);
					break;
				}
				case MiniJavaExpType::LiteralBoolean:
				{
					ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(assignStmt->getExpression());
					asmFunction->addBodyInstruction("mov qword [" + varId + "], " + to_string(litBool->getBoolean()));
					break;
				}
				case MiniJavaExpType::IdType:
				{
					ASTId* idExp = MiniJavaExpTypeCasting::castToId(assignStmt->getExpression());
					asmFunction->addBodyInstruction("mov qword rdi, [" + idExp->getId() + "]");
					asmFunction->addBodyInstruction("mov qword [" + varId + "], rdi");
					break;
				}
				case MiniJavaExpType::Arithmetic:
				{
					ASTArithmetic* arithmeticExp = MiniJavaExpTypeCasting::castToArithmetic(assignStmt->getExpression());

					visitExpression(arithmeticExp);

					asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
					asmFunction->addBodyInstruction("mov qword [" + varId + "], rdi");
					asmFunction->addBodyInstruction("add rsp, 8");
					break;
				}
			}
			break;
		}
		case MiniJavaStmtType::ASSIGN_ARRAY:
		{
			cout << "CodeGenVisitor::visitStatement::ASSIGN_ARRAY()" << endl;
			break;
		}
		case MiniJavaStmtType::METHODCALL:
		{
			cout << "CodeGenVisitor::visitStatement::METHODCALL()" << endl;
			break;
		}
		case MiniJavaStmtType::STMTLIST:
		{
			cout << "CodeGenVisitor::visitStatement::STMTLIST()" << endl;

			vector<ASTStatement*>* stmtList = MiniJavaStmtTypeCasting::castToStmtList(stmt)->getStatementList();

			for (int i = 0; i < stmtList->size(); i++)
			{
				visitStatement(stmtList->at(i));
			}
			break;
		}
		default:
			cout << "CodeGenVisitor::visitStatement::default()" << endl;
			break;
	}
}

void CodeGenVisitor::visitExpression(ASTExpression* exp)
{
	cout << "CodeGenVisitor::visitExpression()" << endl;

	switch (exp->getExpressionType())
	{
		case MiniJavaExpType::LiteralInteger:
		{
			cout << "CodeGenVisitor::visitExpression::LiteralInteger()" << endl;

			ASTLiteralInteger* litInt = MiniJavaExpTypeCasting::castToLiteralInteger(exp);

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword [rsp], " + to_string(litInt->getInteger()));
			break;
		}
		case MiniJavaExpType::LiteralString:
		{
			cout << "CodeGenVisitor::visitExpression::LiteralString()" << endl;
			break;
		}
		case MiniJavaExpType::LiteralBoolean:
		{
			cout << "CodeGenVisitor::visitExpression::LiteralBoolean()" << endl;

			ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(exp);

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			asmFunction->addBodyInstruction("sub rsp, 8");

			if (litBool->getBoolean())
			{
				asmFunction->addBodyInstruction("mov qword [rsp], 1");
			}
			else
			{
				asmFunction->addBodyInstruction("mov qword [rsp], 0");
			}
			
			break;
		}
		case MiniJavaExpType::IdType:
		{
			cout << "CodeGenVisitor::visitExpression::IdType()" << endl;

			ASTId* idVar = MiniJavaExpTypeCasting::castToId(exp);

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword rdi, [" + idVar->getId() + "]");
			asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			break;
		}
		case MiniJavaExpType::Arithmetic:
		{
			cout << "CodeGenVisitor::visitExpression::Arithmetic()" << endl;

			ASTArithmetic* arithmetic = MiniJavaExpTypeCasting::castToArithmetic(exp);
			
			visitExpression(arithmetic->getFirstExpression());
			visitExpression(arithmetic->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			
			if (arithmetic->getOperation() == MiniJavaOp::DIV)
			{
				asmFunction->addBodyInstruction("xor edx, edx");
				asmFunction->addBodyInstruction("mov ecx, [rsp]");
				asmFunction->addBodyInstruction("add rsp, 8");
				asmFunction->addBodyInstruction("mov eax, [rsp]");
			}
			else
			{
				asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
				asmFunction->addBodyInstruction("add rsp, 8");
				asmFunction->addBodyInstruction("mov rdi, [rsp]");
			}

			switch (arithmetic->getOperation())
			{
				case MiniJavaOp::SUM:
				{
					asmFunction->addBodyInstruction("add rdi, rsi");
					break;
				}
				case MiniJavaOp::SUB:
				{
					asmFunction->addBodyInstruction("sub rdi, rsi");
					break;
				}
				case MiniJavaOp::MULT:
				{
					asmFunction->addBodyInstruction("imul rdi, rsi");
					break;
				}
				case MiniJavaOp::DIV:
				{
					asmFunction->addBodyInstruction("div ecx");
					break;
				}
			}

			if (arithmetic->getOperation() == MiniJavaOp::DIV)
			{
				asmFunction->addBodyInstruction("mov [rsp], eax");
			}
			else
			{
				asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			}
			break;
		}
		case MiniJavaExpType::And:
		{
			ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(exp);
			
			visitExpression(andExp->getFirstExpression());
			visitExpression(andExp->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("and rdi, rsi");
			break;
		}
		case MiniJavaExpType::Or:
		{
			ASTOr* orExp = MiniJavaExpTypeCasting::castToOr(exp);

			visitExpression(orExp->getFirstExpression());
			visitExpression(orExp->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpMethodId);
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("or rdi, rsi");
			break;
		}
	}
}