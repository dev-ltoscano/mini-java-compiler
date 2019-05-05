#include "DFA.h"

DFA::~DFA()
{
	this->stateList.clear();
}

void DFA::loadTransitionsFromFile(string filepath)
{
	ifstream transitionStream;
	transitionStream.open(filepath.c_str());

	if (!transitionStream.is_open())
	{
		throw runtime_error("Could not load transitions file");
	}

	stateList.clear();

	addState("error", false);
	addState("<q0>", false);
	addState("<xS>", true);

	addTransition("<q0>", ' ', "<xS>");
	addTransition("<q0>", '\t', "<xS>");
	addTransition("<q0>", '\r', "<xS>");
	addTransition("<q0>", '\n', "<xS>");
	addTransition("<q0>", '\f', "<xS>");

	string tmpLine;
	istringstream lineStream;
	string stateId, nextStateId;
	char transition;

	while (getline(transitionStream, tmpLine))
	{
		lineStream.clear();
		lineStream.str(tmpLine);

		lineStream >> stateId >> transition >> nextStateId;

		addTransition(stateId, transition, nextStateId);
	}

	transitionStream.close();
}

void DFA::addState(string stateId, bool terminal)
{
	stateList.insert(pair<string, DFAState>(stateId, DFAState(stateId, terminal)));
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

string DFA::nextState(string stateId, char transition)
{
	return stateList.at(stateId).nextState(transition);
}

bool DFA::isTerminalState(string stateId)
{
	return stateList.at(stateId).isTerminal();
}

bool DFA::process(string input)
{
	string stateId = "<q0>";
	string lastStateId;
	
	int currCharId = 0;
	char currChar;
	
	do
	{
		currChar = input[currCharId++];

		lastStateId = stateId;
		stateId = stateList.at(stateId).nextState(currChar);
	} while ((currCharId < input.length()) && (stateId != "error"));

	return stateList.at(lastStateId).isTerminal();
}
