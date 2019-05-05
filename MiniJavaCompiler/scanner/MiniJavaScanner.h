#pragma once

#include <string>
#include <forward_list>
#include <list>

#include "../helper/input/BufferedInput.h"
#include "../helper/token/JavaToken.h"

using namespace std;

/*
*	Classe que representa um analisador léxico para a linguagem Minijava
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
		// Lista de tokens inválidos
		list<string> invalidTokenList;
	public:
		// Construtor com o caminho para o arquivo de código-fonte na linguagem Minijava
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		// Obtém se chegou ao final do arquivo
		bool isEnd();

		// Obtém o token atual
		string getToken();
		// Obtém o token atual e avança na leitura do arquivo
		string nextToken();
		// Obtém a lista de tokens inválidos
		list<string> getInvalidTokenList();
};