#pragma once

#include <iostream>
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

struct MiniJavaError
{
	size_t line;
	size_t positionInLine;
	string msg;
};

class MiniJavaErrorListener : public BaseErrorListener
{
	private:
		vector<MiniJavaError*> errorList;
	public:
		void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override
		{
			MiniJavaError *error = new MiniJavaError();

			error->line = line;
			error->positionInLine = charPositionInLine;
			error->msg = msg;

			errorList.push_back(error);
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