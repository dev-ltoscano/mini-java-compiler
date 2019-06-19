#pragma once

#include <string>
#include "structure/info/MiniJavaType.h"

class ASTMethodType
{
	private:
		std::string type;
		MiniJavaType methodType;
	public:
		ASTMethodType(MiniJavaType methodType)
		{
			this->type = "None";
			this->methodType = methodType;
		}

		ASTMethodType(std::string type, MiniJavaType methodType)
		{
			this->type = type;
			this->methodType = methodType;
		}

		std::string getType()
		{
			return this->type;
		}

		MiniJavaType getMethodType()
		{
			return this->methodType;
		}
};