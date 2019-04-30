#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class DFAState
{
	private:
		bool terminal;
		string token;
		unordered_map<char, int> transitionMap;
	public:
		DFAState(string token, bool terminal);
		~DFAState();

		bool isTerminal();
		string getToken();
		void setNextState(char c, int state);
		int nextState(char c);
};