#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class DFAState
{
	private:
		string name;
		bool terminal;
		unordered_map<char, string> transitionMap;
	public:
		DFAState(string name, bool terminal);
		~DFAState();

		string getName();
		bool isTerminal();
		void setNextState(char c, string state);
		string nextState(char c);
};