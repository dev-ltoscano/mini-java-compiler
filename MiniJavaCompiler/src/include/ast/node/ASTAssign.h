#pragma once

#include "ASTStatement.h"
#include "ASTExpression.h"
#include "ASTId.h"

class ASTAssign : public ASTStatement
{
	private:
		ASTId* id;
		ASTExpression* expression;
	public:
		ASTAssign(ASTId* id, ASTExpression* expression) : ASTStatement(MiniJavaStmtType::ASSIGN)
		{
			this->id = id;
			this->expression = expression;
		}

		~ASTAssign()
		{
			delete this->id;
			delete this->expression;
		}

		ASTId* getId()
		{
			return this->id;
		}

		ASTExpression* getExpression()
		{
			return this->expression;
		}
};