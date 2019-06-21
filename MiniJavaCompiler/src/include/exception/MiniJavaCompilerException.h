/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <stdexcept>
#include <string>

#include "MiniJavaErrorListener.h"

class MiniJavaCompilerException : public std::runtime_error
{
	private:
		size_t line = 0;
		size_t collumn = 0;
	public:
		MiniJavaCompilerException(std::string errorMsg) : std::runtime_error(errorMsg.c_str()) { }

		MiniJavaCompilerException(MiniJavaError *error) : std::runtime_error(error->msg.c_str())
		{
			this->line = error->line;
			this->collumn = error->positionInLine;
		}

		size_t getLine()
		{
			return this->line;
		}

		void setLine(size_t line)
		{
			this->line = line;
		}

		size_t getCollumn()
		{
			return this->collumn;
		}

		void setCollumn(size_t collumn)
		{
			this->collumn = collumn;
		}
};