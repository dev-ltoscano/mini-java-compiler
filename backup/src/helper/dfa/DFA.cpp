#include "DFA.h"

DFA::~DFA()
{
	this->stateList.clear();
}

void DFA::loadTransitionsFromFile(string filepath)
{
	// Abre um stream para o arquivo
	ifstream transitionStream;
	transitionStream.open(filepath.c_str());

	// Verifica se o arquivo n�o foi aberto
	if (!transitionStream.is_open())
	{
		throw runtime_error("Could not load transitions file");
	}

	// Limpa os estados do aut�mato
	stateList.clear();

	// Adiciona os estados b�sicos
	addState("error", false);
	addState("<q0>", false);
	addState("<xS>", true);

	// Adiciona transi��es para caracteres de 'escape'
	addTransition("<q0>", ' ', "<xS>");
	addTransition("<q0>", '\t', "<xS>");
	addTransition("<q0>", '\r', "<xS>");
	addTransition("<q0>", '\n', "<xS>");
	addTransition("<q0>", '\f', "<xS>");

	string tmpLine;
	istringstream lineStream;
	string stateId, nextStateId;
	char transition;

	// L� o arquivo linha a linha
	while (getline(transitionStream, tmpLine))
	{
		lineStream.clear();
		lineStream.str(tmpLine);

		// L� de cada linha, o estado atual, o caracter de transi��o e o pr�ximo estado
		lineStream >> stateId >> transition >> nextStateId;

		// Adiciona a transi��o
		addTransition(stateId, transition, nextStateId);
	}

	// Fecha o stream do arquivo
	transitionStream.close();
}

void DFA::addState(string stateId, bool terminal)
{
	// Adiciona o estado no aut�mato
	stateList.insert(pair<string, DFAState>(stateId, DFAState(stateId, terminal)));
}

void DFA::addTransition(string stateId, char transition, string nextStateId)
{
	// Verifica se o primeiro estado existe no aut�mato
	if (stateList.find(stateId) == stateList.end())
	{
		// Caso n�o exista, adiciona o estado
		addState(stateId, (stateId[1] == 'x'));
	}

	// Verifica se o segundo estado existe no aut�mato
	if (stateList.find(nextStateId) == stateList.end())
	{
		// Caso n�o exista, adiciona o estado
		addState(nextStateId, (nextStateId[1] == 'x'));
	}

	// Adiciona a transi��o entre os dois estados
	stateList.at(stateId).addTransition(transition, nextStateId);
}

string DFA::nextState(string stateId, char transition)
{
	// Obt�m o pr�ximo estado a partir da transi��o
	return stateList.at(stateId).nextState(transition);
}

bool DFA::isTerminalState(string stateId)
{
	// Obt�m se o estado � terminal ou n�o
	return stateList.at(stateId).isTerminal();
}

bool DFA::process(string input)
{
	// Estado atual do aut�mato
	string stateId = "<q0>";
	
	int currCharId = 0;
	char currChar;
	
	// Repete at� que toda a entrada seja consumida
	// ou se chegue a um estado de erro
	do
	{
		// L� a entrada caracter por caracter
		currChar = input[currCharId++];
		// Obt�m o pr�ximo estado usando a transi��o
		stateId = stateList.at(stateId).nextState(currChar);
	} while ((currCharId < input.length()) && (stateId != "error"));

	// Retorna se a entrada foi aceita ou rejeitada pelo aut�mato
	return stateList.at(stateId).isTerminal();
}
