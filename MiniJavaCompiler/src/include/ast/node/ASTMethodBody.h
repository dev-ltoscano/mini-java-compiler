#pragma once

#include <vector>

#include "ASTVar.h"
#include "ASTVarAndAtt.h"
#include "ASTStatement.h"

class ASTMethodBody
{
	private:
		std::vector<ASTVar*> varList;
		std::vector<ASTVarAndAtt*> varAttList;
		std::vector<ASTStatement*> statementList;
	public:
		~ASTMethodBody()
		{
			for (int i = 0; i < varList.size(); i++)
			{
				delete varList.at(i);
			}

			for (int i = 0; i < varAttList.size(); i++)
			{
				delete varAttList.at(i);
			}

			for (int i = 0; i < statementList.size(); i++)
			{
				delete statementList.at(i);
			}

			varList.clear();
			varAttList.clear();
			statementList.clear();
		}

		void addVar(ASTVar* var)
		{
			this->varList.push_back(var);
		}

		std::vector<ASTVar*>* getVarList()
		{
			return &this->varList;
		}

		void addVarAndAtt(ASTVarAndAtt* varAndAtt)
		{
			this->varAttList.push_back(varAndAtt);
		}

		std::vector<ASTVarAndAtt*>* getVarAndAttList()
		{
			return &this->varAttList;
		}

		void addStatement(ASTStatement* statement)
		{
			this->statementList.push_back(statement);
		}

		std::vector<ASTStatement*>* getStatementList()
		{
			return &this->statementList;
		}
};