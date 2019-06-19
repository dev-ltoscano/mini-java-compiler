#pragma once

#include <vector>

#include "ASTVar.h"
#include "ASTVarType.h"

class ASTMethodParams
{
	private:
		std::vector<ASTVar*> paramList;
	public:
		~ASTMethodParams()
		{
			for (int i = 0; i < paramList.size(); i++)
			{
				delete this->paramList.at(i);
			}

			this->paramList.clear();
		}

		void addParam(ASTVar* param)
		{
			this->paramList.push_back(param);
		}

		std::vector<ASTVar*>* getParamList()
		{
			return &paramList;
		}
};