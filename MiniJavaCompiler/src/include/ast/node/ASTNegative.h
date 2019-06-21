#pragma once

#include "ASTExpression.h"

class ASTNegative : public ASTExpression
{
private:
	ASTExpression* expression;
public:
	ASTNegative(ASTExpression* expression) : ASTExpression(MiniJavaExpType::Negative)
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