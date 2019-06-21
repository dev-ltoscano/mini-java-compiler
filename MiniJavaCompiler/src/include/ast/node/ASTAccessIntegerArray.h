#pragma once

#include "ASTExpression.h"

class ASTAccessIntegerArray : public ASTExpression
{
	private:
		ASTExpression* mainExpression;
		ASTExpression* arrayExpression;
	public:
		ASTAccessIntegerArray(ASTExpression* mainExpression, ASTExpression* arrayExpression) : ASTExpression(MiniJavaExpType::AccessIntegerArray)
		{
			this->mainExpression = mainExpression;
			this->arrayExpression = arrayExpression;
		}

		~ASTAccessIntegerArray()
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