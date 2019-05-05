#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

/*
*	Classe que representa o estado de um autômato
*/
class DFAState
{
	private:
		// Nome do estado
		string name;
		// Indica se o estado é terminal ou não
		bool terminal;
		// Mapa de transições do estado
		unordered_map<char, string> transitionMap;
	public:
		DFAState(string name, bool terminal);
		~DFAState();

		// Obtém o nome do estado
		string getName();
		// Obtém se o estado é terminal ou não
		bool isTerminal();
		// Adiciona transição para o próximo estado usando um caracter
		void addTransition(char c, string nextStateId);
		// Obtém o próximo estado usando a transição do caracter
		string nextState(char c);
};