#pragma once

#include "ASTStatement.h"
#include "ASTExpression.h"

class ASTWhile : public ASTStatement
{
	private:
		ASTExpression* expression;
		ASTStatement* statement;
	public:
		ASTWhile(ASTExpression* expression, ASTStatement* statement) : ASTStatement(MiniJavaStmtType::WHILE)
		{
			this->expression = expression;
			this->statement = statement;
		}

		~ASTWhile()
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