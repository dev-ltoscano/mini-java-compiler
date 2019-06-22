#pragma once

#include <string>

#include "ASTStatement.h"
#include "ASTExpression.h"

class ASTSout : public ASTStatement
{
	private:
		ASTExpression* expression;
	public:
		ASTSout(ASTExpression* expression) : ASTStatement(MiniJavaStmtType::SOUT)
		{
			this->expression = expression;
		}

		~ASTSout()
		{
			delete this->expression;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}
};