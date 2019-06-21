#pragma once

#include "ASTExpression.h"

class ASTLength : public ASTExpression
{
	private:
		ASTExpression* expression;
	public:
		ASTLength(ASTExpression* expression) : ASTExpression(MiniJavaExpType::Length)
		{
			this->expression = expression;
		}

		~ASTLength()
		{
			delete this->expression;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}
};