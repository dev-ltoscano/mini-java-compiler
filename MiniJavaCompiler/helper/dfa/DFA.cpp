#include "DFA.h"

DFA::DFA()
{
	addState("-1", false);
}

DFA::~DFA()
{
	this->stateList.clear();
}

void DFA::loadTransitions(string filepath)
{
	ifstream transitionFile;
	transitionFile.open(filepath.c_str());

	if (!transitionFile.is_open())
	{
		throw runtime_error("Could not load transitions file");
	}

	string tmpLine;
	istringstream lineStream;
	string stateId, nextStateId;
	char transition;

	while (getline(transitionFile, tmpLine))
	{
		lineStream.clear();
		lineStream.str(tmpLine);

		lineStream >> stateId >> transition >> nextStateId;

		addTransition(stateId, transition, nextStateId);
	}

	transitionFile.close();
}

void DFA::addState(string token, bool terminal)
{
	stateList.insert(pair<string, DFAState>(token, DFAState(token, terminal)));
}

void DFA::addTransition(string stateId, char transition, string nextStateId)
{
	if (stateList.find(stateId) == stateList.end())
	{
		addState(stateId, (stateId[1] == 'x'));
	}

	if (stateList.find(nextStateId) == stateList.end())
	{
		addState(nextStateId, (nextStateId[1] == 'x'));
	}

	stateList.at(stateId).setNextState(transition, nextStateId);
}

DFAState* DFA::getState(string stateId)
{
	return &stateList.at(stateId);
}