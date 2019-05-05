#pragma once

#include <string>

#include "../dfa/DFA.h"

using namespace std;

/*
*	Classe com os tokens da linguagem Java
*/
class JavaToken
{
	private:
		// Autômato que reconhece os tokens da linguagem Java
		DFA* tokenDFA;
	public:
		JavaToken();
		~JavaToken();

		// Obtém o tipo do token
		string getTokenType(string stateId, string lexeme);

		// Obtém o próximo estado do autômato usando a transição
		string getNextState(string stateId, char transition);
		// Obtém se o estado é terminal
		bool isTerminalState(string stateId);
};