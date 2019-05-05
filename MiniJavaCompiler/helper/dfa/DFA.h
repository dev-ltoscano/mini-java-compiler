#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "DFAState.h"

using namespace std;

class DFA
{
	private:
		unordered_map<string, DFAState> stateList;
	public:
		~DFA();

		void loadTransitionsFromFile(string filepath);

		void addState(string stateId, bool terminal);
		void addTransition(string stateId, char transition, string nextStateId);

		string nextState(string stateId, char transition);
		bool isTerminalState(string stateId);

		bool process(string input);
};