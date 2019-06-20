#pragma once

#include <string>
#include "ASTExpression.h"

class ASTId : public ASTExpression
{
private:
	std::string value;
public:
	ASTId(std::string value)
	{
		this->value = value;
	}

	std::string getId()
	{
		return this->value;
	}
};