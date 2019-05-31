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
		// Aut�mato que reconhece os tokens da linguagem Java
		DFA* tokenDFA;
	public:
		JavaToken();
		~JavaToken();

		// Obt�m o tipo do token
		string getTokenType(string stateId, string lexeme);

		// Obt�m o pr�ximo estado do aut�mato usando a transi��o
		string getNextState(string stateId, char transition);
		// Obt�m se o estado � terminal
		bool isTerminalState(string stateId);
};