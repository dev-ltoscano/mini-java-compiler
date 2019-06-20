#pragma once

#include "ASTExpression.h"

class ASTLiteralBoolean : public ASTExpression
{
private:
	bool value;
public:
	ASTLiteralBoolean(bool value)
	{
		this->value = value;
	}

	bool getBoolean()
	{
		return this->value;
	}
};