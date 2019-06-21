#pragma once

#include <string>

#include "ASTExpression.h"
#include "ASTId.h"

class ASTNewObject : public ASTExpression
{
	private:
		ASTId* id;
	public:
		ASTNewObject(ASTId* id) : ASTExpression(MiniJavaExpType::NewObject)
		{
			this->id = id;
		}

		~ASTNewObject()
		{
			delete this->id;
		}

		std::string getId()
		{
			return this->id->getId();
		}
};