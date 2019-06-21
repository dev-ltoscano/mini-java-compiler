#pragma once

#include "ASTExpression.h"

class ASTNewIntegerArray : public ASTExpression
{
	private:
		ASTExpression* expression;
	public:
		ASTNewIntegerArray(ASTExpression* expression)
		{
			this->expression;
		}

		~ASTNewIntegerArray()
		{
			delete this->expression;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}
};