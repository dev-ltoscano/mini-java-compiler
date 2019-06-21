#pragma once

#include "ASTStatement.h"
#include "ASTExpression.h"

class ASTIfElse : public ASTStatement
{
private:
	ASTExpression* expression;
	ASTStatement* ifStatement;
	ASTStatement* elseStatement;
public:
	ASTIfElse(ASTExpression* expression, ASTStatement* ifStatement, ASTStatement* elseStatement) : ASTStatement(MiniJavaStmtType::IFELSE)
	{
		this->expression = expression;
		this->ifStatement = ifStatement;
		this->elseStatement = elseStatement;
	}

	~ASTIfElse()
	{
		delete this->expression;
		delete this->ifStatement;
		delete this->elseStatement;
	}

	ASTExpression* getExpression()
	{
		return this->expression;
	}

	ASTStatement* getIfStatement()
	{
		return this->ifStatement;
	}

	ASTStatement* getElseStatement()
	{
		return this->elseStatement;
	}
};