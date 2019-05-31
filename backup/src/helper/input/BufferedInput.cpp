#include "BufferedInput.h"

void BufferedInput::loadBuffer()
{
	//	Verifica se todo o arquivo já foi lido
	if (totalReadFileLength == fileLength)
	{
		throw runtime_error("The reading has reached the end of the file");
	}

	// Retorna o índica ao início do buffer
	currIndex = 0;
	// Faz a leitura de um novo buffer
	fileStream.read(inputBuffer, bufferSize);
	// Obtém a quantidade de caracteres lidos
	lastReadFileLength = fileStream.gcount();
	// Incrementa o total do arquivo lido
	totalReadFileLength += lastReadFileLength;
}

BufferedInput::BufferedInput(string inputFilepath, unsigned int bufferSize)
{
	// Abre um stream do arquivo de entrada
	this->fileStream.open(inputFilepath.c_str(), fstream::in | fstream::binary);

	// Verifica se o arquivo não foi aberto
	if (!fileStream.is_open())
	{
		throw runtime_error("Could not open file");
	}

	// Obtém o tamanho do arquivo
	this->fileStream.seekg(0, fileStream.end);
	this->fileLength = fileStream.tellg();
	// Retorna a leitura para o início do arquivo
	this->fileStream.seekg(0, fileStream.beg);

	// Verifica se o arquivo é vazio
	if (fileLength == 0)
	{
		throw runtime_error("The file is empty");
	}

	// Inicializa variáveis
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
	// Desaloca a memória do buffer
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

	// Verifica se é necessário carregar um novo buffer
	if (!isEnd() && (currIndex >= bufferSize))
	{
		loadBuffer();
	}

	// Obtém o caracter atual e incrementa a posição do índice
	char c = inputBuffer[currIndex++];

	// Altera as variáveis de linha e coluna do arquivo
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
	// Verifica se a leitura chegou ao início do arquivo
	if (totalReadFileLength == 0)
	{
		throw runtime_error("The reading has reached the beginning of the file");
	}

	// Verifica se o buffer atual é o primeiro buffer do arquivo, se sim, retorna
	if ((currIndex <= 0) && ((totalReadFileLength - (2 * bufferSize)) > fileLength))
	{
		totalReadFileLength = 0;
		return;
	}

	// Verifica se o índice do buffer passou do limite inferior do buffer
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
		// Posiciona o stream na posição para leitura do novo buffer
		fileStream.seekg(totalReadFileLength, ios_base::beg);
		// Faz a leitura do buffer anterior
		loadBuffer();
		// Altera a posição do índice do buffer
		currIndex = (lastReadFileLength - 1);
	}
	else
	{
		// Se não, somente altera a posição do índice do buffer
		currIndex--;
	}

	// Altera as variáveis de linha e coluna do arquivo
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