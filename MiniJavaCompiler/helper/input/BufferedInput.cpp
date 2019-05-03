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

	if (fileLength == 0)
	{
		throw runtime_error("The file is empty");
	}

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
	if (totalReadFileLength == 0)
	{
		throw runtime_error("The reading has reached the beginning of the file");
	}

	if ((currIndex <= 0) && ((totalReadFileLength - (2 * bufferSize)) > fileLength))
	{
		totalReadFileLength = 0;
		return;
	}

	if (currIndex <= 0)
	{
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
		fileStream.seekg(totalReadFileLength, ios_base::beg);
		loadBuffer();

		currIndex = (lastReadFileLength - 1);
	}
	else
	{
		currIndex--;
	}

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