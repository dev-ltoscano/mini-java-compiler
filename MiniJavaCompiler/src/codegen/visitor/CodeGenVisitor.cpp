/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "codegen/visitor/CodeGenVisitor.h"

#include <iostream>

using namespace std;

AsmFile* CodeGenVisitor::visitProgram()
{
	cout << "CodeGenVisitor::visitProgram()" << endl;

	visitMainClass(astProgram->getMainClass());

	vector<ASTClass*>* classList = astProgram->getClassList();

	for (int i = 0; i < classList->size(); i++)
	{
		visitClass(classList->at(i));
	}

	return asmFile;
}

void CodeGenVisitor::visitMainClass(ASTMainClass* mainClassDecl)
{
	cout << "CodeGenVisitor::visitMainClass()" << endl;

	tmpClassId = mainClassDecl->getId();
	tmpMethodId = mainClassDecl->getMainMethod()->getId();
	tmpFunction = tmpMethodId;

	asmFile->addFunction(new AsmFunction(tmpFunction));

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

	AsmFunction* exitFunction = asmFile->getFunction(tmpFunction);
	exitFunction->addBodyInstruction("mov rax, 60");
	exitFunction->addBodyInstruction("xor rdi, rdi");
	exitFunction->addBodyInstruction("syscall");
}

void CodeGenVisitor::visitClass(ASTClass* classDecl)
{
	cout << "CodeGenVisitor::visitClass()" << endl;

	tmpClassId = classDecl->getId();
	tmpMethodId = "";
	tmpFunction = "";

	vector<ASTVar*>* varList = classDecl->getVarList();

	for (int i = 0; i < varList->size(); i++)
	{
		visitVar(varList->at(i));
	}

	vector<ASTVarAndAtt*>* varAttList = classDecl->getVarAndAttList();

	for (int i = 0; i < varAttList->size(); i++)
	{
		visitVarAndAtt(varAttList->at(i));
	}

	vector<ASTMethod*>* methodList = classDecl->getMethodList();

	for (int i = 0; i < methodList->size(); i++)
	{
		visitMethod(methodList->at(i));
	}
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
	AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);

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

	tmpMethodId = methodDecl->getId();
	tmpFunction = tmpMethodId;

	asmFile->addFunction(new AsmFunction(tmpFunction));

	vector<ASTVar*>* varList = methodDecl->getMethodBody()->getVarList();

	for (int i = 0; i < varList->size(); i++)
	{
		visitVar(varList->at(i));
	}

	vector<ASTVarAndAtt*>* varAttList = methodDecl->getMethodBody()->getVarAndAttList();

	for (int i = 0; i < varAttList->size(); i++)
	{
		visitVarAndAtt(varAttList->at(i));
	}

	vector<ASTStatement*>* stmtList = methodDecl->getMethodBody()->getStatementList();

	for (int i = 0; i < stmtList->size(); i++)
	{
		visitStatement(stmtList->at(i));
	}

	AsmFunction* exitFunction = asmFile->getFunction(tmpFunction);
	exitFunction->addBodyInstruction("ret");
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
	AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);

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

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);
					asmFunction->addBodyInstruction("cmp [" + varId + "], 1");
					asmFunction->addBodyInstruction("je " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifStmt->getStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					tmpFunction = jmpContLabel;

					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					break;
				}
				case MiniJavaExpType::And:
				{
					ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(ifStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(andExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();
					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifStmt->getStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Or:
				{
					ASTOr* orExp = MiniJavaExpTypeCasting::castToOr(ifStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(orExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();
					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifStmt->getStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Comp:
				{
					ASTComp* cmpExp = MiniJavaExpTypeCasting::castToComp(ifStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(cmpExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();

					switch (cmpExp->getOperation())
					{
						case MiniJavaOp::EQUAL:
						{
							asmFunction->addBodyInstruction("je " + jmpIfLabel);
							break;
						}
						case MiniJavaOp::NEQUAL:
						{
							asmFunction->addBodyInstruction("jne " + jmpIfLabel);
							break;
						}
						case MiniJavaOp::LESS:
						{
							asmFunction->addBodyInstruction("jl " + jmpIfLabel);
							break;
						}
						case MiniJavaOp::LEQUAL:
						{
							asmFunction->addBodyInstruction("jl " + jmpIfLabel);
							asmFunction->addBodyInstruction("je " + jmpIfLabel);
							break;
						}
						case MiniJavaOp::GREATER:
						{
							asmFunction->addBodyInstruction("jg " + jmpIfLabel);
							break;
						}
						case MiniJavaOp::GEQUAL:
						{
							asmFunction->addBodyInstruction("jg " + jmpIfLabel);
							asmFunction->addBodyInstruction("je " + jmpIfLabel);
							break;
						}
					}
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifStmt->getStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
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

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpElseLabel = "_" + tmpFunction + "_else_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);
					asmFunction->addBodyInstruction("cmp [" + varId + "], 1");
					asmFunction->addBodyInstruction("je " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpFunction = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;

					break;
				}
				case MiniJavaExpType::And:
				{
					ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(ifElseStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpElseLabel = "_" + tmpFunction + "_else_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(andExp);

					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpFunction = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Or:
				{
					ASTOr* orExp = MiniJavaExpTypeCasting::castToOr(ifElseStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpElseLabel = "_" + tmpFunction + "_else_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(orExp);

					asmFunction->addBodyInstruction("jnz " + jmpIfLabel);
					asmFunction->addBodyInstruction("jmp " + jmpElseLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpFunction = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Comp:
				{
					ASTComp* cmpExp = MiniJavaExpTypeCasting::castToComp(ifElseStmt->getExpression());

					string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
					string jmpElseLabel = "_" + tmpFunction + "_else_" + to_string(tmpId++);
					string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

					asmFunction->addBodyInstruction("sub rsp, 8");
					asmFunction->addBodyInstruction("mov qword [rsp], " + jmpContLabel);

					visitExpression(cmpExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();

					switch (cmpExp->getOperation())
					{
					case MiniJavaOp::EQUAL:
					{
						asmFunction->addBodyInstruction("je " + jmpIfLabel);
						break;
					}
					case MiniJavaOp::NEQUAL:
					{
						asmFunction->addBodyInstruction("jne " + jmpIfLabel);
						break;
					}
					case MiniJavaOp::LESS:
					{
						asmFunction->addBodyInstruction("jl " + jmpIfLabel);
						break;
					}
					case MiniJavaOp::LEQUAL:
					{
						asmFunction->addBodyInstruction("jl " + jmpIfLabel);
						asmFunction->addBodyInstruction("je " + jmpIfLabel);
						break;
					}
					case MiniJavaOp::GREATER:
					{
						asmFunction->addBodyInstruction("jg " + jmpIfLabel);
						break;
					}
					case MiniJavaOp::GEQUAL:
					{
						asmFunction->addBodyInstruction("jg " + jmpIfLabel);
						asmFunction->addBodyInstruction("je " + jmpIfLabel);
						break;
					}
					}
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(jmpIfLabel));
					tmpFunction = jmpIfLabel;

					visitStatement(ifElseStmt->getIfStatement());

					asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpElseLabel));
					tmpFunction = jmpElseLabel;

					visitStatement(ifElseStmt->getElseStatement());

					asmFile->getFunction(jmpElseLabel)->addBodyInstruction("jmp [rsp]");

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");
					tmpFunction = jmpContLabel;
					break;
				}
			}

			break;
		}
		case MiniJavaStmtType::WHILE:
		{
			cout << "CodeGenVisitor::visitStatement::WHILE()" << endl;

			ASTWhile* whileStmt = MiniJavaStmtTypeCasting::castToWhile(stmt);

			string whileLabel = "_" + tmpFunction + "_while_" + to_string(tmpId++);
			string whileBodyLabel = "_" + tmpFunction + "_while_body_" + to_string(tmpId++);
			string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

			switch (whileStmt->getExpression()->getExpressionType())
			{
				case MiniJavaExpType::LiteralBoolean:
				{
					ASTLiteralBoolean* litBool = MiniJavaExpTypeCasting::castToLiteralBoolean(whileStmt->getExpression());

					if (litBool->getBoolean())
					{
						asmFunction->addBodyInstruction("sub rsp, 8");
						asmFunction->addBodyInstruction("mov qword [rsp], " + whileLabel);
						asmFunction->addBodyInstruction("jmp " + whileLabel);

						asmFile->addFunction(new AsmFunction(whileLabel));
						asmFunction = asmFile->getFunction(whileLabel);
						tmpFunction = whileLabel;

						visitStatement(whileStmt->getStatement());
						asmFunction->addBodyInstruction("jmp " + whileLabel);
					}
					break;
				}
				case MiniJavaExpType::And:
				{
					ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(whileStmt->getExpression());

					asmFunction->addBodyInstruction("jmp " + whileLabel);

					asmFile->addFunction(new AsmFunction(whileLabel));
					asmFunction = asmFile->getFunction(whileLabel);
					tmpFunction = whileLabel;

					visitExpression(andExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();

					asmFunction->addBodyInstruction("jnz " + whileBodyLabel);
					asmFunction->addBodyInstruction("jmp " + jmpContLabel);

					asmFile->addFunction(new AsmFunction(whileBodyLabel));
					asmFunction = asmFile->getFunction(whileBodyLabel);
					tmpFunction = whileBodyLabel;

					visitStatement(whileStmt->getStatement());

					asmFunction->addBodyInstruction("jmp " + whileLabel);

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFunction = asmFile->getFunction(jmpContLabel);
					tmpFunction = jmpContLabel;
					break;
				}
				case MiniJavaExpType::Comp:
				{
					ASTComp* cmpExp = MiniJavaExpTypeCasting::castToComp(whileStmt->getExpression());
					
					asmFunction->addBodyInstruction("jmp " + whileLabel);

					asmFile->addFunction(new AsmFunction(whileLabel));
					asmFunction = asmFile->getFunction(whileLabel);
					tmpFunction = whileLabel;

					visitExpression(cmpExp);

					asmFunction->removeLastBodyInstruction();
					asmFunction->removeLastBodyInstruction();

					switch (cmpExp->getOperation())
					{
						case MiniJavaOp::EQUAL:
						{
							asmFunction->addBodyInstruction("je " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
						case MiniJavaOp::NEQUAL:
						{
							asmFunction->addBodyInstruction("jne " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
						case MiniJavaOp::LESS:
						{
							asmFunction->addBodyInstruction("jl " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
						case MiniJavaOp::LEQUAL:
						{
							asmFunction->addBodyInstruction("jl " + whileBodyLabel);
							asmFunction->addBodyInstruction("je " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
						case MiniJavaOp::GREATER:
						{
							asmFunction->addBodyInstruction("jg " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
						case MiniJavaOp::GEQUAL:
						{
							asmFunction->addBodyInstruction("jg " + whileBodyLabel);
							asmFunction->addBodyInstruction("je " + whileBodyLabel);
							asmFunction->addBodyInstruction("jmp " + jmpContLabel);

							asmFile->addFunction(new AsmFunction(whileBodyLabel));
							asmFunction = asmFile->getFunction(whileBodyLabel);
							tmpFunction = whileBodyLabel;

							visitStatement(whileStmt->getStatement());

							asmFunction->addBodyInstruction("jmp " + whileLabel);
							break;
						}
					}

					asmFile->addFunction(new AsmFunction(jmpContLabel));
					asmFunction = asmFile->getFunction(jmpContLabel);
					tmpFunction = jmpContLabel;
					break;
				}
			}
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
			ASTMethodCall* methodCall = MiniJavaStmtTypeCasting::castToMethodCall(stmt);

			methodCall->getParams();
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

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
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

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
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

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
			asmFunction->addBodyInstruction("mov qword rdi, [" + idVar->getId() + "]");
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			break;
		}
		case MiniJavaExpType::Arithmetic:
		{
			cout << "CodeGenVisitor::visitExpression::Arithmetic()" << endl;

			ASTArithmetic* arithmetic = MiniJavaExpTypeCasting::castToArithmetic(exp);
			
			visitExpression(arithmetic->getFirstExpression());
			visitExpression(arithmetic->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
			
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
			cout << "CodeGenVisitor::visitExpression::And()" << endl;

			ASTAnd* andExp = MiniJavaExpTypeCasting::castToAnd(exp);
			
			visitExpression(andExp->getFirstExpression());
			visitExpression(andExp->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("and rdi, rsi");
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			break;
		}
		case MiniJavaExpType::Or:
		{
			cout << "CodeGenVisitor::visitExpression::Or()" << endl;

			ASTOr* orExp = MiniJavaExpTypeCasting::castToOr(exp);

			visitExpression(orExp->getFirstExpression());
			visitExpression(orExp->getSecondExpression());

			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("or rdi, rsi");
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			break;
		}
		case MiniJavaExpType::Comp:
		{
			cout << "CodeGenVisitor::visitExpression::Comp()" << endl;

			ASTComp* cmpExp = MiniJavaExpTypeCasting::castToComp(exp);

			visitExpression(cmpExp->getSecondExpression());
			visitExpression(cmpExp->getFirstExpression());
			
			AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
			asmFunction->addBodyInstruction("mov qword rdi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("mov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("add rsp, 8");
			asmFunction->addBodyInstruction("cmp rdi, rsi");
			asmFunction->addBodyInstruction("sub rsp, 8");
			asmFunction->addBodyInstruction("mov qword [rsp], rdi");
			break;
		}
		case MiniJavaExpType::MethodCall:
		{
			cout << "CodeGenVisitor::visitExpression::MethodCall()" << endl;

			ASTMethodCall* methodCall = MiniJavaExpTypeCasting::castToMethodCall(exp);

			ASTExpressionList* methodCallParams = methodCall->getParams();

			methodCallParams->getExpressionList();

			break;
		}
		default:
		{
			cout << "CodeGenVisitor::visitExpression::default()" << endl;
		}
	}
}