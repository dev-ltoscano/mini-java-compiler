#pragma once

#include <exception>
#include <string>

#include "MiniJavaErrorListener.h"

class MiniJavaCompilerException : public std::exception
{
	private:
		size_t line = 0;
		size_t collumn = 0;
	public:
		MiniJavaCompilerException(MiniJavaError *error) : std::exception(error->msg.c_str())
		{
			this->line = error->line;
			this->collumn = error->positionInLine;
		}

		size_t getLine()
		{
			return this->line;
		}

		size_t getCollumn()
		{
			return this->collumn;
		}
};