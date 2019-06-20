#pragma once

#include "ASTExpression.h"

class ASTMethodReturn
{
	private:
		ASTExpression* returnExpression;
	public:
		ASTMethodReturn(ASTExpression* returnExpression)
		{
			this->returnExpression = returnExpression;
		}

		~ASTMethodReturn()
		{
			delete this->returnExpression;
		}

		ASTExpression* getReturnExpression()
		{
			return this->returnExpression;
		}
};