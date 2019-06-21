#pragma once

#include <vector>
#include "ASTStatement.h"

class ASTStatementList : public ASTStatement
{
	private:
		std::vector<ASTStatement*> statementList;
	public:
		ASTStatementList() : ASTStatement(MiniJavaStmtType::STMTLIST) { }

		~ASTStatementList()
		{
			for (int i = 0; i < statementList.size(); i++)
			{
				delete statementList.at(i);
			}

			statementList.clear();
		}

		void addStatement(ASTStatement* stmt)
		{
			this->statementList.push_back(stmt);
		}

		std::vector<ASTStatement*>* getStatementList()
		{
			return &this->statementList;
		}
};