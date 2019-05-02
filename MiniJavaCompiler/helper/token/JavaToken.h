#pragma once

#include <string>
#include <list>
#include <regex>

#include "../dfa/DFA.h"

using namespace std;

struct JavaTokenType
{
	string type;
	string regex;

	JavaTokenType(string type, string regex)
	{
		this->type = type;
		this->regex = regex;
	}
};

class JavaToken
{
	private:
		DFA *tokenDFA;
		list<JavaTokenType> tokenTypeList;
	public:
		JavaToken();
		~JavaToken();

		DFAState* getTokenDFAState(string stateId);
		string getTokenType(string lexeme);
};