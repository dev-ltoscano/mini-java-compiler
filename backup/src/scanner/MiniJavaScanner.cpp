#include "MiniJavaScanner.h"

MiniJavaScanner::MiniJavaScanner(string srcPath)
{
	// Cria uma entrada bufferizada para o arquivo de código-fonte em Minijava
	this->bufferedInput = new BufferedInput(srcPath, DEFAULT_INPUT_BUFFER_SIZE);
	// Inicializa o token atual
	this->currToken = "";
}

MiniJavaScanner::~MiniJavaScanner()
{
	// Limpa a lista de tokens inválidos
	this->invalidTokenList.clear();
	// Desaloca a memória da entrada bufferizada
	delete this->bufferedInput;
}

bool MiniJavaScanner::isEnd()
{
	return bufferedInput->isEnd();
}

string MiniJavaScanner::getToken()
{
	return currToken;
}

string MiniJavaScanner::nextToken()
{
	// Limpa o token atual
	currToken = "";

	// Inicializa as variáveis para o lexema e para a parte inválida de um lexema
	string lexeme = "";
	string invalidLexeme = "";
	char currChar;
	
	// Inicializa a pilha de estados
	forward_list<string> stateStack;
	stateStack.push_front("error");
	string stateId = "<q0>";

	do
	{
		// Faz a leitura do caracter atual da entrada e avança
		currChar = bufferedInput->nextChar();
		// Concatena o caracter com o lexema atual
		lexeme.push_back(currChar);

		// Verifica se o lexema atual são os símbolos de início de comentário
		if ((lexeme == "//") || (lexeme == "/*"))
		{
			// Define o símbolo de terminação de comentário
			string endComment;

			if (lexeme == "//")
				endComment = "\n";
			else
				endComment = "*/";

			lexeme = "";

			// Ignora todos os caracteres até o final do comentário
			do
			{
				if (lexeme.size() >= endComment.size())
				{
					lexeme[0] = lexeme[1];
					lexeme.pop_back();
				}

				currChar = bufferedInput->nextChar();
				lexeme.push_back(currChar);
			} while (lexeme != endComment);

			// Reseta o estado das variáveis e continua o processo
			lexeme = "";
			invalidLexeme = "";
			stateStack.clear();
			stateStack.push_front("error");
			stateId = "<q0>";
			continue;
		}

		// Verifica se o estado atual é um estado terminal
		if (javaTokens.isTerminalState(stateId))
			stateStack.clear(); // Se sim, limpa a pilha de estados

		// Adiciona o estado atual na pilha de estados
		stateStack.push_front(stateId);
		// Obtém o próximo estado usando a transição do caracter
		stateId = javaTokens.getNextState(stateId, currChar);
	} while (stateId != "error");

	// Caso o lexema tenha tamanho maior do que 1, faz rollback
	if (lexeme.size() > 1)
		bufferedInput->rollback();

	// Ignora o último caracter do lexema
	invalidLexeme.push_back(lexeme.back());
	lexeme.pop_back();
	
	// Obtém o estado do topo da pilha
	stateId = stateStack.front();

	// Verifica se o estado é terminal
	if (javaTokens.isTerminalState(stateId))
	{
		// Caso seja, obtém o tipo do token do lexema
		currToken = javaTokens.getTokenType(stateId, lexeme);

		// Verifica o tipo do token e em alguns casos, adiciona o lexema como atributo do token
		if ((currToken == "ACCESS_MODIFIER") || (currToken == "TYPE") ||  (currToken == "MATH_OP") || (currToken == "LOGICAL_OP") 
			|| (currToken == "COMP_OP") || (currToken == "COND_OP") || (currToken == "BITWISE_OP")
			|| (currToken == "BOOLEAN") || (currToken == "ID") || (currToken == "INTEGER"))
			currToken.append("('" + lexeme + "')");
	}
	else
	{
		// Caso contrário, o token é inválido
		currToken = "INVALID";

		// Insere a linha e coluna do erro
		invalidLexeme.append(" (L" + to_string(bufferedInput->getLineCount()) + ":" + "C" + to_string(bufferedInput->getColumnCount()) + ")");
		// Adiciona o token inválido na lista
		invalidTokenList.push_back(invalidLexeme);
	}
	
	return currToken;
}

list<string> MiniJavaScanner::getInvalidTokenList()
{
	return invalidTokenList;
}