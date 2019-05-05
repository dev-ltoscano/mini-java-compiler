#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

#define DEFAULT_INPUT_BUFFER_SIZE	4096	// Tamanho padr�o do buffer

using namespace std;

/*
*	Classe para uma leitura de arquivos bufferizada
*/
class BufferedInput
{
	private:
		// Stream para o arquivo de entrada
		fstream fileStream;
		// Tamanho do arquivo, total do arquivo lido, tamanho da �ltima leitura
		unsigned int fileLength, totalReadFileLength, lastReadFileLength;
		// Tamanho do buffer, �ndice atual no buffer
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

		// Obt�m o tamanho do arquivo
		unsigned int getFileLength();
		// Obt�m o total do arquivo lido at� o momento
		unsigned int getTotalReadFileLength();
		// Obt�m se a leitura est� no in�cio do arquivo
		bool isBegin();
		// Obt�m se a leitura est� no fim do arquivo
		bool isEnd();
		// Obt�m o caracter atual da leitura do arquivo
		char currentChar();
		// Obt�m o caracter atual e avan�a na leitura do arquivo
		char nextChar();
		// Retrocede um caracter na leitura do arquivo
		void rollback();
		// Transforma o buffer em uma string
		string toString();
		// Obt�m a linha atual do arquivo
		unsigned int getLineCount();
		// Obt�m a coluna atual do arquivo
		unsigned int getColumnCount();
};