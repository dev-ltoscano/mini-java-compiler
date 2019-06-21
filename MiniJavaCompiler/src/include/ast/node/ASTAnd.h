#pragma once

#include "ASTExpression.h"

class ASTAnd : public ASTExpression
{
	private:
		ASTExpression* firstExpression;
		ASTExpression* secondExpression;
	public:
		ASTAnd(ASTExpression* firstExpression, ASTExpression* secondExpression)
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