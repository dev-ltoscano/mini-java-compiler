#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

#define DEFAULT_INPUT_BUFFER_SIZE	4096	// Tamanho padrão do buffer

using namespace std;

/*
*	Classe para uma leitura de arquivos bufferizada
*/
class BufferedInput
{
	private:
		// Stream para o arquivo de entrada
		fstream fileStream;
		// Tamanho do arquivo, total do arquivo lido, tamanho da última leitura
		unsigned int fileLength, totalReadFileLength, lastReadFileLength;
		// Tamanho do buffer, índice atual no buffer
		unsigned int bufferSize, currIndex;
		// Buffer de caracteres
		char* inputBuffer;
		// Linha e coluna atuais do arquivo
		unsigned int lineCount, columnCount;
		// Carrega um novo buffer
		void loadBuffer();
	public:
		// Construtor com o caminho para o arquivo e com o tamanho do buffer
		BufferedInput(string inputFilepath, unsigned int bufferSize);
		~BufferedInput();

		// Obtém o tamanho do arquivo
		unsigned int getFileLength();
		// Obtém o total do arquivo lido até o momento
		unsigned int getTotalReadFileLength();
		// Obtém se a leitura está no início do arquivo
		bool isBegin();
		// Obtém se a leitura está no fim do arquivo
		bool isEnd();
		// Obtém o caracter atual da leitura do arquivo
		char currentChar();
		// Obtém o caracter atual e avança na leitura do arquivo
		char nextChar();
		// Retrocede um caracter na leitura do arquivo
		void rollback();
		// Transforma o buffer em uma string
		string toString();
		// Obtém a linha atual do arquivo
		unsigned int getLineCount();
		// Obtém a coluna atual do arquivo
		unsigned int getColumnCount();
};