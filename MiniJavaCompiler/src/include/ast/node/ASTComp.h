#pragma once

#include "ASTExpression.h"
#include "structure/info/MiniJavaOp.h"

class ASTComp : public ASTExpression
{
	private:
		ASTExpression* firstExpression;
		ASTExpression* secondExpression;
		MiniJavaOp operation;
	public:
		ASTComp(ASTExpression* firstExpression, ASTExpression* secondExpression, MiniJavaOp operation)
		{
			this->firstExpression = firstExpression;
			this->secondExpression = secondExpression;
			this->operation = operation;
		}

		~ASTComp()
		{
			delete this->firstExpression;
			delete this->secondExpression;
		}

		ASTExpression* getFirstExpression()
		{
			return this->firstExpression;
		}

		ASTExpression* getSecondExpression()
		{
			return this->secondExpression;
		}

		MiniJavaOp getOperation()
		{
			return this->operation;
		}
};