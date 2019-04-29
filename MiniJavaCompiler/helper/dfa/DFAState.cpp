#include "DFAState.h"

DFAState::DFAState(string token, bool terminal)
{
	this->token = token;
	this->terminal = terminal;
}

string DFAState::getToken()
{
	return token;
}

bool DFAState::isTerminal()
{
	return terminal;
}

void DFAState::setNextState(char c, int state)
{
	nextStateMap.insert(pair<char, int>(c, state));
}

int DFAState::nextState(char c)
{
	int state;

	try
	{
		state = nextStateMap.at(c);
	}
	catch (out_of_range &ex)
	{
		state = -1;
	}

	return state;
}