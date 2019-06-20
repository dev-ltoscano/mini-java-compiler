#pragma once

#include "structure/info/MiniJavaType.h"

class ASTVarType
{
private:
	MiniJavaType varType;
	std::string varIdType;
public:
	ASTVarType(MiniJavaType varType)
	{
		this->varType = varType;
		this->varIdType = "Unknown";
	}

	ASTVarType(MiniJavaType varType, std::string varIdType)
	{
		this->varType = varType;
		this->varIdType = varIdType;
	}

	MiniJavaType getType()
	{
		return this->varType;
	}

	std::string getIDType()
	{
		return this->varIdType;
	}
};