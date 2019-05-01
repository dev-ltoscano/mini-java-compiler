#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "DFAState.h"

using namespace std;

class DFA
{
	private:
		unordered_map<string, DFAState> stateList;
	public:
		DFA();
		~DFA();

		void loadTransitions(string filepath);
		void addState(string token, bool terminal);
		void addTransition(string stateId, char transition, string nextStateId);
		DFAState* getState(string stateId);
};