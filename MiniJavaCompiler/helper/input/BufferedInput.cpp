#include "BufferedInput.h"

void BufferedInput::loadBuffer()
{
	//	Verifica se todo o arquivo j� foi lido
	if (totalReadFileLength == fileLength)
	{
		throw runtime_error("The reading has reached the end of the file");
	}

	// Retorna o �ndica ao in�cio do buffer
	currIndex = 0;
	// Faz a leitura de um novo buffer
	fileStream.read(inputBuffer, bufferSize);
	// Obt�m a quantidade de caracteres lidos
	lastReadFileLength = fileStream.gcount();
	// Incrementa o total do arquivo lido
	totalReadFileLength += lastReadFileLength;
}

BufferedInput::BufferedInput(string inputFilepath, unsigned int bufferSize)
{
	// Abre um stream do arquivo de entrada
	this->fileStream.open(inputFilepath.c_str(), fstream::in | fstream::binary);

	// Verifica se o arquivo n�o foi aberto
	if (!fileStream.is_open())
	{
		throw runtime_error("Could not open file");
	}

	// Obt�m o tamanho do arquivo
	this->fileStream.seekg(0, fileStream.end);
	this->fileLength = fileStream.tellg();
	// Retorna a leitura para o in�cio do arquivo
	this->fileStream.seekg(0, fileStream.beg);

	// Verifica se o arquivo � vazio
	if (fileLength == 0)
	{
		throw runtime_error("The file is empty");
	}

	// Inicializa vari�veis
	this->bufferSize = bufferSize;
	this->totalReadFileLength = 0;
	this->lastReadFileLength = 0;
	this->currIndex = 0;
	this->lineCount = 1;
	this->columnCount = 1;

	// Inicializa o buffer
	this->inputBuffer = new char[bufferSize];
	this->loadBuffer();
}

BufferedInput::~BufferedInput()
{
	// Fecha a stream do arquivo
	this->fileStream.close();
	// Desaloca a mem�ria do buffer
	delete[] this->inputBuffer;
}

unsigned int BufferedInput::getFileLength()
{
	return fileLength;
}

unsigned int BufferedInput::getTotalReadFileLength()
{
	return totalReadFileLength;
}

bool BufferedInput::isBegin()
{
	return ((totalReadFileLength == 0) && (currIndex == 0));
}


bool BufferedInput::isEnd()
{
	return ((totalReadFileLength == fileLength) && (currIndex == lastReadFileLength));
}

char BufferedInput::currentChar()
{
	return inputBuffer[currIndex];
}

char BufferedInput::nextChar()
{
	// Verifica se a leitura chegou ao final do arquivo
	if (currIndex > lastReadFileLength)
	{
		throw runtime_error("The reading has reached the end of the file");
	}

	// Verifica se � necess�rio carregar um novo buffer
	if (!isEnd() && (currIndex >= bufferSize))
	{
		loadBuffer();
	}

	// Obt�m o caracter atual e incrementa a posi��o do �ndice
	char c = inputBuffer[currIndex++];

	// Altera as vari�veis de linha e coluna do arquivo
	if (c == '\n')
	{
		lineCount++;
		columnCount = 0;
	}
	else
	{
		columnCount++;
	}
	
	return c;
}

void BufferedInput::rollback()
{
	// Verifica se a leitura chegou ao in�cio do arquivo
	if (totalReadFileLength == 0)
	{
		throw runtime_error("The reading has reached the beginning of the file");
	}

	// Verifica se o buffer atual � o primeiro buffer do arquivo, se sim, retorna
	if ((currIndex <= 0) && ((totalReadFileLength - (2 * bufferSize)) > fileLength))
	{
		totalReadFileLength = 0;
		return;
	}

	// Verifica se o �ndice do buffer passou do limite inferior do buffer
	if (currIndex <= 0)
	{
		// Se sim, calcula o tamanho do buffer anterior
		if (lastReadFileLength < bufferSize)
		{
			totalReadFileLength -= (bufferSize + lastReadFileLength);
		}
		else
		{
			totalReadFileLength -= (2 * bufferSize);

			if (totalReadFileLength > fileLength)
			{
				totalReadFileLength = 0;
			}
		}
		
		fileStream.clear();
		// Posiciona o stream na posi��o para leitura do novo buffer
		fileStream.seekg(totalReadFileLength, ios_base::beg);
		// Faz a leitura do buffer anterior
		loadBuffer();
		// Altera a posi��o do �ndice do buffer
		currIndex = (lastReadFileLength - 1);
	}
	else
	{
		// Se n�o, somente altera a posi��o do �ndice do buffer
		currIndex--;
	}

	// Altera as vari�veis de linha e coluna do arquivo
	if (inputBuffer[currIndex] == '\n')
	{
		lineCount--;
		columnCount--;
	}
	else
	{
		columnCount--;
	}
}

string BufferedInput::toString()
{
	return string(inputBuffer, lastReadFileLength);
}

unsigned int BufferedInput::getLineCount()
{
	return lineCount;
}

unsigned int BufferedInput::getColumnCount()
{
	return columnCount;
}