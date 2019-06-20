#pragma once

#include <string>
#include "ASTExpression.h"

class ASTLiteralString : public ASTExpression
{
	private:
		std::string value;
	public:
		ASTLiteralString(std::string value)
		{
			this->value = value;
		}

		std::string getString()
		{
			return this->value;
		}
};