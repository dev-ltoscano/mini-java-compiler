#pragma once

#include "ASTExpression.h"

class ASTExpressionArray : public ASTExpression
{
	private:
		ASTExpression* mainExpression;
		ASTExpression* arrayExpression;
	public:
		ASTExpressionArray(ASTExpression* mainExpression, ASTExpression* arrayExpression)
		{
			this->mainExpression = mainExpression;
			this->arrayExpression = arrayExpression;
		}

		~ASTExpressionArray()
		{
			delete this->mainExpression;
			delete this->arrayExpression;
		}

		ASTExpression* getMainExpression()
		{
			return this->mainExpression;
		}

		ASTExpression* getArrayExpression()
		{
			return this->arrayExpression;
		}
};