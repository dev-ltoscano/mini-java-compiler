#include "DFAState.h"

DFAState::DFAState(string name, bool terminal)
{
	this->name = name;
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

string DFAState::getName()
{
	return name;
}

void DFAState::addTransition(char c, string nextStateId)
{
	// Adiciona a transi��o no mapa de transi��es
	transitionMap.insert(pair<char, string>(c, nextStateId));
}

string DFAState::nextState(char c)
{
	string stateId;

	try
	{
		// Tenta obter a transi��o usando o caracter
		stateId = transitionMap.at(c);
	}
	catch (out_of_range)
	{
		// Caso n�o exista, retorna estado de erro
		stateId = "error";
	}

	return stateId;
}