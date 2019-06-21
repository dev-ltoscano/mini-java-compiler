#pragma once

#include "ASTExpression.h"

class ASTLiteralInteger : public ASTExpression
{
private:
	int value;
public:
	ASTLiteralInteger(int value) : ASTExpression(MiniJavaExpType::LiteralInteger)
	{
		this->value = value;
	}

	int getInteger()
	{
		return this->value;
	}
};