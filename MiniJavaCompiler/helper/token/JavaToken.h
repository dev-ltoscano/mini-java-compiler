#pragma once

#include <string>

#include "../dfa/DFA.h"

using namespace std;

class JavaToken
{
	private:
		DFA* tokenDFA;
	public:
		JavaToken();
		~JavaToken();

		string getTokenType(string stateId, string lexeme);

		string getNextState(string stateId, char transition);
		bool isTerminalState(string stateId);
};