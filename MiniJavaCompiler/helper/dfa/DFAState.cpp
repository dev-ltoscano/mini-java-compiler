#include "DFAState.h"

DFAState::DFAState(string token, bool terminal)
{
	this->token = token;
	this->terminal = terminal;
}

DFAState::~DFAState()
{
	this->transitionMap.clear();
}

bool DFAState::isTerminal()
{
	return terminal;
}

string DFAState::getToken()
{
	return token;
}

void DFAState::setNextState(char c, int state)
{
	transitionMap.insert(pair<char, int>(c, state));
}

int DFAState::nextState(char c)
{
	int state;

	try
	{
		state = transitionMap.at(c);
	}
	catch (out_of_range &ex)
	{
		state = -1;
	}

	return state;
}