#pragma once

#include <string>
#include "ASTVarType.h"

class ASTVar
{
	private:
		std::string id;
		ASTVarType* varType;
	public:
		ASTVar(std::string id, ASTVarType* varType)
		{
			this->id = id;
			this->varType = varType;
		}

		~ASTVar()
		{
			delete this->varType;
		}

		std::string getId()
		{
			return this->id;
		}

		ASTVarType* getVarType()
		{
			return this->varType;
		}
};