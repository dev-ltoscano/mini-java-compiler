#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "DFAState.h"

using namespace std;

/*
*	Classe que representa um autômato
*/
class DFA
{
	private:
		// Mapa com os estados do autômato
		unordered_map<string, DFAState> stateList;
	public:
		~DFA();

		// Carrega as transições do autômato a partir de um arquivo
		void loadTransitionsFromFile(string filepath);

		// Adiciona um estado ao autômato
		void addState(string stateId, bool terminal);
		// Adiciona uma transição ao autômato
		void addTransition(string stateId, char transition, string nextStateId);

		// Obtém o próximo estado usando a transição de um caracter
		string nextState(string stateId, char transition);
		// Obtém se o estado é terminal
		bool isTerminalState(string stateId);
		// Processa uma entrada no autômato
		bool process(string input);
};