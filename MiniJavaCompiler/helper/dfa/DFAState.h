#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class DFAState
{
	private:
		string token;
		bool terminal;
		unordered_map<char, int> nextStateMap;
	public:
		DFAState(string token, bool terminal);

		string getToken();
		bool isTerminal();

		void setNextState(char c, int state);
		int nextState(char c);
};