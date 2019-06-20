#pragma once

#include <string>
#include <vector>

#include "ASTVarType.h"
#include "ASTExpression.h"

class ASTVarAndAtt
{
private:
	std::string id;
	ASTVarType* varType;
	ASTExpression* attExpression;
public:
	ASTVarAndAtt(std::string id, ASTVarType* varType, ASTExpression* attExpression)
	{
		this->id = id;
		this->varType = varType;
		this->attExpression = attExpression;
	}

	~ASTVarAndAtt()
	{
		delete this->varType;
		delete this->attExpression;
	}

	std::string getId()
	{
		return this->id;
	}

	ASTVarType* getVarType()
	{
		return this->varType;
	}

	ASTExpression* getAttExpression()
	{
		return this->attExpression;
	}
};