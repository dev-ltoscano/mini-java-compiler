#pragma once

#include <string>
#include "ASTMethod.h"

class ASTMainClass
{
	private:
		std::string id;
		ASTMethod* mainMethod;
	public:
		ASTMainClass(std::string id, ASTMethod* mainMethod)
		{
			this->id = id;
			this->mainMethod = mainMethod;
		}

		~ASTMainClass()
		{
			delete this->mainMethod;
		}

		std::string getId()
		{
			return this->id;
		}

		ASTMethod* getMainMethod()
		{
			return this->mainMethod;
		}
};