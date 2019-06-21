#pragma once

#include "ASTExpression.h"

class ASTNegation : public ASTExpression
{
	private:
		ASTExpression* expression;
	public:
		ASTNegation(ASTExpression* expression) : ASTExpression(MiniJavaExpType::Negation)
		{
			this->expression = expression;
		}

		~ASTNegation()
		{
			delete this->expression;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}
};