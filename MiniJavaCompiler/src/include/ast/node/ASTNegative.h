#pragma once

#include "ASTExpression.h"

class ASTNegative : public ASTExpression
{
private:
	ASTExpression* expression;
public:
	ASTNegative(ASTExpression* expression)
	{
		this->expression = expression;
	}

	~ASTNegative()
	{
		delete this->expression;
	}

	ASTExpression* getExpression()
	{
		return this->expression;
	}
};