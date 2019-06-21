#pragma once

#include "ASTExpression.h"

class ASTOr : public ASTExpression
{
private:
	ASTExpression* firstExpression;
	ASTExpression* secondExpression;
public:
	ASTOr(ASTExpression* firstExpression, ASTExpression* secondExpression)
	{
		this->firstExpression = firstExpression;
		this->secondExpression = secondExpression;
	}

	ASTExpression* getFirstExpression()
	{
		return this->firstExpression;
	}

	ASTExpression* getSecondExpression()
	{
		return this->secondExpression;
	}
};