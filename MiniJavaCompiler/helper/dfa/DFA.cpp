#include "DFA.h"

DFA::DFA()
{
	this->stateList.insert(pair<string, DFAState>("-1", DFAState("-1", false)));
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

	stateList.clear();
	addState("-1", false);

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

void DFA::addState(string stateId, bool terminal)
{
	stateList.insert(pair<string, DFAState>(stateId, DFAState(stateId, terminal)));
}

DFAState* DFA::getState(string stateId)
{
	return &stateList.at(stateId);
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

bool DFA::process(string input)
{
	string stateId = "<q0>";
	string lastStateId;
	
	int currCharId = 0;
	char currChar;
	
	do
	{
		if (currCharId >= input.length())
		{
			stateId = "-1";
		}
		else
		{
			currChar = input[currCharId];
			currCharId++;

			lastStateId = stateId;
			stateId = stateList.at(stateId).nextState(currChar);
		}	
	} while (stateId != "-1");

	return stateList.at(lastStateId).isTerminal();
}
