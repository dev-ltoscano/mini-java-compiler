#pragma once

#include <string>

#include "ASTStatement.h"
#include "ASTLiteralString.h"

class ASTSout : public ASTStatement
{
	private:
		ASTLiteralString* literalString;
	public:
		ASTSout(ASTLiteralString* literalString)
		{
			this->literalString = literalString;
		}

		~ASTSout()
		{
			delete this->literalString;
		}

		std::string getString()
		{
			return this->literalString->getString();
		}
};