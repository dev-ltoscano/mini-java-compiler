#pragma once

#include "ASTExpression.h"

class ASTNewIntegerArray : public ASTExpression
{
	private:
		ASTExpression* expression;
	public:
		ASTNewIntegerArray(ASTExpression* expression) : ASTExpression(MiniJavaExpType::NewIntegerArray)
		{
			this->expression = expression;
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