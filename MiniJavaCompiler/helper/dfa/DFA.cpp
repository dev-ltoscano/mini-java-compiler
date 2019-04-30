#include "DFA.h"

DFA::~DFA()
{
	this->stateList.clear();
}

void DFA::addState(string token, bool terminal)
{
	stateList.push_back(DFAState(token, terminal));
}

void DFA::addTransition(int stateId, char transition, int nextStateId)
{
	this->states[stateId].setNextState(transition, nextStateId);
}

void DFA::addTransition(int stateId, string transition, int nextStateId)
{
	for (int i = 0; i < transition.length(); i++)
	{
		this->states[stateId].setNextState(transition[i], nextStateId);
	}
}