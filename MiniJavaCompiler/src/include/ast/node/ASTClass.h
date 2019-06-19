#pragma once

#include <string>
#include <vector>

#include "ASTVar.h"
#include "ASTMethod.h"

class ASTClass
{
	private:
		std::string id;
		std::vector<ASTVar*> varList;
		std::vector<ASTMethod*> methodList;
	public:
		ASTClass(std::string id)
		{
			this->id = id;
		}

		void addVar(ASTVar* var)
		{
			this->varList.push_back(var);
		}

		std::vector<ASTVar*>* getVarList()
		{
			return &this->varList;
		}

		void addMethod(ASTMethod* method)
		{
			this->methodList.push_back(method);
		}

		std::vector<ASTMethod*>* getMethodList()
		{
			return &this->methodList;
		}
};