#include "BufferedInput.h"

void BufferedInput::loadBuffer()
{
	if (totalReadFileLength == fileLength)
	{
		throw runtime_error("The reading has reached the end of the file");
	}

	currIndex = 0;
	fileStream.read(inputBuffer, bufferSize);

	lastReadFileLength = fileStream.gcount();
	totalReadFileLength += lastReadFileLength;
}

BufferedInput::BufferedInput(string inputFilepath, unsigned int bufferSize)
{
	this->fileStream.open(inputFilepath.c_str(), fstream::in | fstream::binary);

	if (!fileStream.is_open())
	{
		throw runtime_error("Could not open file");
	}

	this->fileStream.seekg(0, fileStream.end);
	this->fileLength = fileStream.tellg();
	this->fileStream.seekg(0, fileStream.beg);

	this->bufferSize = bufferSize;
	this->totalReadFileLength = 0;
	this->lastReadFileLength = 0;
	this->currIndex = 0;

	this->inputBuffer = new char[bufferSize];
	this->loadBuffer();

	this->lineCount = 1;
	this->columnCount = 1;
}

BufferedInput::~BufferedInput()
{
	this->fileStream.close();
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
	return (currIndex == 0);
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
	if (currIndex > lastReadFileLength)
	{
		throw runtime_error("The reading has reached the end of the file");
	}

	if (!isEnd() && (currIndex >= bufferSize))
	{
		loadBuffer();
	}

	char c = inputBuffer[currIndex++];

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
	if (currIndex > 0)
	{
		currIndex--;

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