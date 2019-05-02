#include "MiniJavaScanner.h"

MiniJavaScanner::MiniJavaScanner(string srcPath)
{
	this->bufferedInput = new BufferedInput(srcPath, 4096);
	this->currToken = "";
}

MiniJavaScanner::~MiniJavaScanner()
{
	this->invalidTokenList.clear();
	delete this->bufferedInput;
}

bool MiniJavaScanner::isEnd()
{
	return bufferedInput->isEnd();
}

string MiniJavaScanner::getToken()
{
	return currToken;
}

string MiniJavaScanner::nextToken()
{
	currToken = "";

	string lexeme = "";
	string invalidLexeme = "";
	char currChar;
	
	forward_list<string> stateStack;
	stateStack.push_front("-1");
	string stateId = "<q0>";

	do
	{
		currChar = bufferedInput->nextChar();
		lexeme.push_back(currChar);

		if ((lexeme == "//") || (lexeme == "/*"))
		{
			string endComment;

			if (lexeme == "//")
			{
				endComment = "\n";
			}
			else
			{
				endComment = "*/";
			}

			lexeme = "";

			do
			{
				if (lexeme.size() >= endComment.size())
				{
					lexeme[0] = lexeme[1];
					lexeme.pop_back();
				}

				currChar = bufferedInput->nextChar();
				lexeme.push_back(currChar);
			} while (lexeme != endComment);

			lexeme = "";
			stateStack.clear();
			stateStack.push_front("-1");
			stateId = "<q0>";
			continue;
		}

		stateStack.push_front(stateId);
		stateId = javaTokens.getNextState(stateId, currChar);
	} while (stateId != "-1");

	if (lexeme.size() > 1)
		bufferedInput->rollback();

	invalidLexeme.push_back(lexeme.back());
	lexeme.pop_back();

	stateId = stateStack.front();
	
	if (javaTokens.isTerminalState(stateId))
	{
		currToken = javaTokens.getTokenType(lexeme);

		if ((currToken == "ACCESS_MODIFIER") || (currToken == "TYPE") ||  (currToken == "MATH_OP") 
			|| (currToken == "COMP_OP") || (currToken == "LOGICAL_OP") || (currToken == "BITWISE_OP")
			|| (currToken == "COND_OP") || (currToken == "BOOLEAN")
			|| (currToken == "ID") || (currToken == "INTEGER"))
			currToken.append("('" + lexeme + "')");
	}
	else
	{
		currToken = "INVALID";

		invalidLexeme.append(" (L" + to_string(bufferedInput->getLineCount()) + ":" + "C" + to_string(bufferedInput->getColumnCount()) + ")");
		invalidTokenList.push_front(invalidLexeme);
	}
	
	return currToken;
}

list<string> MiniJavaScanner::getInvalidTokenList()
{
	return invalidTokenList;
}