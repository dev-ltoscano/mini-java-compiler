#include "BufferedInput.h"

void BufferedInput::readBuffer()
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

	// Get file size
	this->fileStream.seekg(0, fileStream.end);
	this->fileLength = fileStream.tellg();
	this->fileStream.seekg(0, fileStream.beg);

	this->bufferSize = bufferSize;
	this->totalReadFileLength = 0;
	this->lastReadFileLength = 0;
	this->currIndex = 0;

	this->inputBuffer = new char[bufferSize];
	this->readBuffer();
}

BufferedInput::~BufferedInput()
{
	delete this->inputBuffer;
	this->fileStream.close();
}

unsigned int BufferedInput::getFileLength()
{
	return fileLength;
}

unsigned int BufferedInput::getTotalReadFileLength()
{
	return totalReadFileLength;
}

unsigned int BufferedInput::getLastReadFileLength()
{
	return lastReadFileLength;
}

bool BufferedInput::isBegin()
{
	return (currIndex == 0);
}


bool BufferedInput::isEnd()
{
	return ((totalReadFileLength == fileLength) && (currIndex >= lastReadFileLength));
}

char BufferedInput::currentChar()
{
	return inputBuffer[currIndex];
}

char BufferedInput::nextChar()
{
	if (isEnd())
	{
		throw runtime_error("The reading has reached the last character");
	}

	if (currIndex >= bufferSize)
	{
		readBuffer();
	}

	return inputBuffer[currIndex++];
}

void BufferedInput::rollback()
{
	if (currIndex == 0)
	{
		throw runtime_error("The reading has reached the first character");
	}

	currIndex--;
}

string BufferedInput::toString()
{
	return string(inputBuffer, lastReadFileLength);
}