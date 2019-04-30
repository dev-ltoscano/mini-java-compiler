#pragma once

#include <string>
#include <vector>
#include "DFAState.h"

using namespace std;

class DFA
{
	private:
		vector<DFAState> stateList;
	public:
		~DFA();

		void addState(string token, bool terminal);
		
		void addTransition(int stateId, char transition, int nextStateId);
		void addTransition(int stateId, string transition, int nextStateId);
};