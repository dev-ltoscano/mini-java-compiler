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

		void addState(string stateId, bool terminal);
		DFAState* getState(string stateId);

		void addTransition(string stateId, char transition, string nextStateId);
		
		bool process(string input);
};