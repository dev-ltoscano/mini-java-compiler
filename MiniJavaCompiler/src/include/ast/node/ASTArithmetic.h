#pragma once

#include "ASTExpression.h"
#include "structure/info/MiniJavaOp.h"

class ASTArithmetic : public ASTExpression
{
private:
	ASTExpression* firstExpression;
	ASTExpression* secondExpression;
	MiniJavaOp operation;
public:
	ASTArithmetic(ASTExpression* firstExpression, ASTExpression* secondExpression, MiniJavaOp operation)
		: ASTExpression(MiniJavaExpType::Arithmetic)
	{
		this->firstExpression = firstExpression;
		this->secondExpression = secondExpression;
		this->operation = operation;
	}

	~ASTArithmetic()
	{
		delete this->firstExpression;
		delete this->secondExpression;
	}

	ASTExpression* getFirstExpression()
	{
		return this->firstExpression;
	}

	ASTExpression* getSecondExpression()
	{
		return this->secondExpression;
	}

	MiniJavaOp getOperation()
	{
		return this->operation;
	}
};