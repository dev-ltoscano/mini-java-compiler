#pragma once

#include <string>
#include <vector>

#include "ASTVar.h"
#include "ASTVarAndAtt.h"
#include "ASTMethod.h"

class ASTClass
{
	private:
		std::string id;
		std::string inheritedClass;
		std::vector<ASTVar*> varList;
		std::vector<ASTVarAndAtt*> varAttList;
		std::vector<ASTMethod*> methodList;
	public:
		ASTClass(std::string id, std::string inheritedClass)
		{
			this->id = id;
			this->inheritedClass = inheritedClass;
		}

		~ASTClass()
		{
			for (int i = 0; i < varList.size(); i++)
			{
				delete varList.at(i);
			}

			for (int i = 0; i < varAttList.size(); i++)
			{
				delete varAttList.at(i);
			}

			for (int i = 0; i < methodList.size(); i++)
			{
				delete methodList.at(i);
			}

			varList.clear();
			varAttList.clear();
			methodList.clear();
		}

		std::string getId()
		{
			return this->id;
		}

		std::string getInheritedClass()
		{
			return this->inheritedClass;
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

		void addMethod(ASTMethod* method)
		{
			this->methodList.push_back(method);
		}

		std::vector<ASTMethod*>* getMethodList()
		{
			return &this->methodList;
		}
};