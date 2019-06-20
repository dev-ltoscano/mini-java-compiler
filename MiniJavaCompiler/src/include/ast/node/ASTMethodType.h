#pragma once

#include <string>
#include "structure/info/MiniJavaType.h"

class ASTMethodType
{
	private:
		MiniJavaType methodType;
		std::string methodIdType;
	public:
		ASTMethodType(MiniJavaType methodType)
		{
			this->methodType = methodType;
			this->methodIdType = "Unknown";
		}

		ASTMethodType(MiniJavaType methodType, std::string methodIdType)
		{
			this->methodType = methodType;
			this->methodIdType = methodIdType;
		}

		MiniJavaType getType()
		{
			return this->methodType;
		}

		std::string getIDType()
		{
			return this->methodIdType;
		}
};