#pragma once

#include "ASTStatement.h"
#include "ASTExpression.h"
#include "ASTId.h"

class ASTAssignArray : public ASTStatement
{
private:
	ASTId* id;
	ASTExpression* arrayExpression;
	ASTExpression* expression;
public:
	ASTAssignArray(ASTId* id, ASTExpression* arrayExpression, ASTExpression* expression) : ASTStatement(MiniJavaStmtType::ASSIGN_ARRAY)
	{
		this->id = id;
		this->arrayExpression = arrayExpression;
		this->expression = expression;
	}

	~ASTAssignArray()
	{
		delete this->id;
		delete this->arrayExpression;
		delete this->expression;
	}

	ASTId* getId()
	{
		return this->id;
	}

	ASTExpression* getArrayExpression()
	{
		return this->arrayExpression;
	}

	ASTExpression* getExpression()
	{
		return this->expression;
	}
};