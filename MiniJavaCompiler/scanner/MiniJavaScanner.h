#pragma once

#include <string>
#include <forward_list>
#include <list>

#include "../helper/input/BufferedInput.h"
#include "../helper/token/JavaToken.h"

using namespace std;

/*
*	Classe que representa um analisador l�xico para a linguagem Minijava
*/
class MiniJavaScanner
{
	private:
		// Entrada bufferizada
		BufferedInput *bufferedInput;
		// Tokens da linguagem Java
		JavaToken javaTokens;
		// Token atual
		string currToken;
		// Lista de tokens inv�lidos
		list<string> invalidTokenList;
	public:
		// Construtor com o caminho para o arquivo de c�digo-fonte na linguagem Minijava
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		// Obt�m se chegou ao final do arquivo
		bool isEnd();

		// Obt�m o token atual
		string getToken();
		// Obt�m o token atual e avan�a na leitura do arquivo
		string nextToken();
		// Obt�m a lista de tokens inv�lidos
		list<string> getInvalidTokenList();
};