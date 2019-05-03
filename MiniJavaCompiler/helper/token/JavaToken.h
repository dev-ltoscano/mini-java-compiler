#pragma once

#include <string>
#include <list>
#include <regex>

#include "../dfa/DFA.h"

using namespace std;

struct JavaTokenType
{
	string type;
	regex reg;

	JavaTokenType(string type, string reg)
	{
		this->type = type;
		this->reg = regex(reg);
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