#pragma once

#include "ASTStatement.h"
#include "ASTExpression.h"

class ASTIf : public ASTStatement
{
	private:
		ASTExpression* expression;
		ASTStatement* statement;
	public:
		ASTIf(ASTExpression* expression, ASTStatement* statement) : ASTStatement(MiniJavaStmtType::IF)
		{
			this->expression = expression;
			this->statement = statement;
		}

		~ASTIf()
		{
			delete this->expression;
			delete this->statement;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}

		ASTStatement* getStatement()
		{
			return this->statement;
		}
};