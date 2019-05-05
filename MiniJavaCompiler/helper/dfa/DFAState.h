#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

/*
*	Classe que representa o estado de um aut�mato
*/
class DFAState
{
	private:
		// Nome do estado
		string name;
		// Indica se o estado � terminal ou n�o
		bool terminal;
		// Mapa de transi��es do estado
		unordered_map<char, string> transitionMap;
	public:
		DFAState(string name, bool terminal);
		~DFAState();

		// Obt�m o nome do estado
		string getName();
		// Obt�m se o estado � terminal ou n�o
		bool isTerminal();
		// Adiciona transi��o para o pr�ximo estado usando um caracter
		void addTransition(char c, string nextStateId);
		// Obt�m o pr�ximo estado usando a transi��o do caracter
		string nextState(char c);
};