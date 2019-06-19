#pragma once

#include "ASTMethod.h"

class ASTMainClass
{
	private:
		ASTMethod* mainMethod;
	public:
		ASTMainClass(ASTMethod* mainMethod)
		{
			this->mainMethod = mainMethod;
		}

		ASTMethod* getMainMethod()
		{
			return this->mainMethod;
		}
};