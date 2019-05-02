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
		list<JavaTokenType> tokenTypeList;
		DFA* tokenDFA;
	public:
		JavaToken();
		~JavaToken();

		string getTokenType(string lexeme);

		string getNextState(string stateId, char transition);
		bool isTerminalState(string stateId);
};