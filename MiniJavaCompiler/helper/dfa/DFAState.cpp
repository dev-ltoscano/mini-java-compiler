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

void DFAState::setNextState(char c, string state)
{
	transitionMap.insert(pair<char, string>(c, state));
}

string DFAState::nextState(char c)
{
	string state;

	try
	{
		state = transitionMap.at(c);
	}
	catch (out_of_range)
	{
		state = "-1";
	}

	return state;
}