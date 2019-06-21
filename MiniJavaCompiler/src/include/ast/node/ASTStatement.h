#pragma once

#include "structure/info/MiniJavaStmtType.h"

class ASTStatement
{
	private:
		MiniJavaStmtType stmtType;
	public:
		ASTStatement(MiniJavaStmtType stmtType)
		{
			this->stmtType = stmtType;
		}

		virtual ~ASTStatement() = default;

		MiniJavaStmtType getStatementType()
		{
			return this->stmtType;
		}
};