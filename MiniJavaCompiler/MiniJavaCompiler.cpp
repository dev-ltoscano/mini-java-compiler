#include <iostream>
#include <exception>
#include <string>
#include <list>

#include "scanner/MiniJavaScanner.h"

using namespace std;

/*
*	Compilador para a linguagem Minijava
*/
int main(int argc, char** argv)
{
	MiniJavaScanner *scanner = NULL;

	try
	{
		if (argc > 1)
		{
			// Inicializa o analisador léxico passando o caminho do arquivo do parâmetro
			scanner = new MiniJavaScanner(argv[1]);
		}
		else
		{
			// Inicializa o analisador léxico passando o caminho do arquivo do arquivo padrão de testes
			scanner = new MiniJavaScanner("../test/test.txt");
		}

		string tokenType;

		// Repete até o fim do arquivo
		while (!scanner->isEnd())
		{
			// Obtém o próximo token
			tokenType = scanner->nextToken();

			// Imprime o token
			if(tokenType != "INVALID")
				cout << tokenType << endl;
		}

		// Obtém a lista de tokens inválidos
		list<string> invalidTokenList = scanner->getInvalidTokenList();

		// Verifica se a lista de tokens inválidos não é vazia
		if (invalidTokenList.size() > 0)
		{
			// Caso não seja, imprime os erros
			cout << endl << "Lexical errors:" << endl;

			for (auto it = invalidTokenList.begin(); it != invalidTokenList.end(); it++)
				cout << " " << *it << endl;
		}
	}
	catch (exception &ex)
	{
		cout << ">> ERROR: " << ex.what() << endl;
	}

	// Desaloca a memória do analisador léxico
	if(scanner != NULL)
		delete scanner;

	return 0;
}
