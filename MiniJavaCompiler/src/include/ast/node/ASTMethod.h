#pragma once

#include <string>
#include "ASTMethodType.h"
#include "ASTMethodParams.h"

class ASTMethod
{
	private:
		std::string id;
		ASTMethodType* returnType;
		ASTMethodParams* params;
	public:
		ASTMethod(std::string id, ASTMethodType* returnType)
			: ASTMethod(id, returnType, nullptr) { }

		ASTMethod(std::string id, ASTMethodType* returnType, ASTMethodParams* params)
		{
			this->id = id;
			this->returnType = returnType;
			this->params = params;
		}

		~ASTMethod()
		{
			delete this->returnType;
			delete this->params;
		}

		std::string getId()
		{
			return this->id;
		}

		ASTMethodType* getReturnType()
		{
			return this->returnType;
		}

		ASTMethodParams* getParams()
		{
			return this->params;
		}
};