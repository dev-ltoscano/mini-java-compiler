#pragma once

#include <vector>

#include "ASTMainClass.h"
#include "ASTClass.h"

class ASTProgram
{
	private:
		ASTMainClass* mainClass;
		std::vector<ASTClass*> classList;
	public:
		ASTMainClass* getMainClass()
		{
			return this->mainClass;
		}

		void setMainClass(ASTMainClass* mainClass)
		{
			this->mainClass = mainClass;
		}

		void addClass(ASTClass* classDecl)
		{
			this->classList.push_back(classDecl);
		}

		std::vector<ASTClass*>* getClassList()
		{
			return &this->classList;
		}
};