/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/
#pragma once

#include <iostream>
#include "antlr4/antlr4-runtime.h"

using namespace std;
using namespace antlr4;

struct MiniJavaError
{
	size_t line;
	size_t positionInLine;
	string msg;

	MiniJavaError(size_t line, size_t collumn, string msg)
	{
		this->line = line;
		this->positionInLine = collumn;
		this->msg = msg;
	}
};

class MiniJavaErrorListener : public BaseErrorListener
{
	private:
		vector<MiniJavaError*> errorList;
	public:
		void addError(size_t line, size_t collumn, string msg)
		{
			errorList.push_back(new MiniJavaError(line, collumn, msg));
		}

		void addError(MiniJavaError* error)
		{
			errorList.push_back(error);
		}

		void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override
		{
			addError(line, charPositionInLine, msg);
		}

		bool hasErrors()
		{
			return (errorList.size() > 0);
		}

		void printErrorList()
		{
			MiniJavaError* tmpError;

			for(unsigned int i = 0; i < errorList.size(); i++)
			{
				tmpError = errorList.at(i);
				cout << "(L" << tmpError->line << ":C" << tmpError->positionInLine << ") - " << tmpError->msg << endl;
			}
		}
};