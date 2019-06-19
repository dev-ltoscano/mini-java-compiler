#pragma once

#include "structure/info/MiniJavaType.h"

class ASTVarType
{
private:
	std::string type;
	MiniJavaType varType;
public:
	ASTVarType(MiniJavaType varType)
	{
		this->type = "None";
		this->varType = varType;
	}

	ASTVarType(std::string type, MiniJavaType varType)
	{
		this->type = type;
		this->varType = varType;
	}

	std::string getType()
	{
		return this->type;
	}

	MiniJavaType getVarType()
	{
		return this->varType;
	}
};