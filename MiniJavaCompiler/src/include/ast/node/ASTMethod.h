#pragma once

#include <string>

#include "ASTMethodType.h"
#include "ASTMethodReturn.h"
#include "ASTMethodParams.h"
#include "ASTMethodBody.h"

class ASTMethod
{
	private:
		std::string id;
		ASTMethodType* methodReturnType;
		ASTMethodParams* methodParams;
		ASTMethodBody* methodBody;
		ASTMethodReturn* methodReturn;
	public:
		ASTMethod(std::string id, ASTMethodType* methodReturnType, ASTMethodParams* methodParams, ASTMethodBody* methodBody, ASTMethodReturn* methodReturn)
		{
			this->id = id;
			this->methodReturnType = methodReturnType;
			this->methodParams = methodParams;
			this->methodBody = methodBody;
			this->methodReturn = methodReturn;
		}

		~ASTMethod()
		{
			delete this->methodReturnType;
			delete this->methodReturn;
			delete this->methodParams;
			delete this->methodBody;
		}

		std::string getId()
		{
			return this->id;
		}

		ASTMethodType* getMethodReturnType()
		{
			return this->methodReturnType;
		}

		ASTMethodReturn* getMethodReturn()
		{
			return this->methodReturn;
		}

		ASTMethodParams* getMethodParams()
		{
			return this->methodParams;
		}

		ASTMethodBody* getMethodBody()
		{
			return this->methodBody;
		}
};