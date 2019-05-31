#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "DFAState.h"

using namespace std;

/*
*	Classe que representa um aut�mato
*/
class DFA
{
	private:
		// Mapa com os estados do aut�mato
		unordered_map<string, DFAState> stateList;
	public:
		~DFA();

		// Carrega as transi��es do aut�mato a partir de um arquivo
		void loadTransitionsFromFile(string filepath);

		// Adiciona um estado ao aut�mato
		void addState(string stateId, bool terminal);
		// Adiciona uma transi��o ao aut�mato
		void addTransition(string stateId, char transition, string nextStateId);

		// Obt�m o pr�ximo estado usando a transi��o de um caracter
		string nextState(string stateId, char transition);
		// Obt�m se o estado � terminal
		bool isTerminalState(string stateId);
		// Processa uma entrada no aut�mato
		bool process(string input);
};