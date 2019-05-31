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

	// Verifica se o arquivo não foi aberto
	if (!transitionStream.is_open())
	{
		throw runtime_error("Could not load transitions file");
	}

	// Limpa os estados do autômato
	stateList.clear();

	// Adiciona os estados básicos
	addState("error", false);
	addState("<q0>", false);
	addState("<xS>", true);

	// Adiciona transições para caracteres de 'escape'
	addTransition("<q0>", ' ', "<xS>");
	addTransition("<q0>", '\t', "<xS>");
	addTransition("<q0>", '\r', "<xS>");
	addTransition("<q0>", '\n', "<xS>");
	addTransition("<q0>", '\f', "<xS>");

	string tmpLine;
	istringstream lineStream;
	string stateId, nextStateId;
	char transition;

	// Lê o arquivo linha a linha
	while (getline(transitionStream, tmpLine))
	{
		lineStream.clear();
		lineStream.str(tmpLine);

		// Lê de cada linha, o estado atual, o caracter de transição e o próximo estado
		lineStream >> stateId >> transition >> nextStateId;

		// Adiciona a transição
		addTransition(stateId, transition, nextStateId);
	}

	// Fecha o stream do arquivo
	transitionStream.close();
}

void DFA::addState(string stateId, bool terminal)
{
	// Adiciona o estado no autômato
	stateList.insert(pair<string, DFAState>(stateId, DFAState(stateId, terminal)));
}

void DFA::addTransition(string stateId, char transition, string nextStateId)
{
	// Verifica se o primeiro estado existe no autômato
	if (stateList.find(stateId) == stateList.end())
	{
		// Caso não exista, adiciona o estado
		addState(stateId, (stateId[1] == 'x'));
	}

	// Verifica se o segundo estado existe no autômato
	if (stateList.find(nextStateId) == stateList.end())
	{
		// Caso não exista, adiciona o estado
		addState(nextStateId, (nextStateId[1] == 'x'));
	}

	// Adiciona a transição entre os dois estados
	stateList.at(stateId).addTransition(transition, nextStateId);
}

string DFA::nextState(string stateId, char transition)
{
	// Obtém o próximo estado a partir da transição
	return stateList.at(stateId).nextState(transition);
}

bool DFA::isTerminalState(string stateId)
{
	// Obtém se o estado é terminal ou não
	return stateList.at(stateId).isTerminal();
}

bool DFA::process(string input)
{
	// Estado atual do autômato
	string stateId = "<q0>";
	
	int currCharId = 0;
	char currChar;
	
	// Repete até que toda a entrada seja consumida
	// ou se chegue a um estado de erro
	do
	{
		// Lê a entrada caracter por caracter
		currChar = input[currCharId++];
		// Obtém o próximo estado usando a transição
		stateId = stateList.at(stateId).nextState(currChar);
	} while ((currCharId < input.length()) && (stateId != "error"));

	// Retorna se a entrada foi aceita ou rejeitada pelo autômato
	return stateList.at(stateId).isTerminal();
}
