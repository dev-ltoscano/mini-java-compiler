#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#define DEFAULT_INPUT_BUFFER_SIZE	4096

using namespace std;

class BufferedInput
{
	private:
		fstream fileStream;
		unsigned int fileLength, totalReadFileLength, lastReadFileLength;

		unsigned int bufferSize, currIndex;
		char* inputBuffer;
		
		void readBuffer();
	public:
		BufferedInput(string inputFilepath, unsigned int bufferSize);
		~BufferedInput();

		unsigned int getFileLength();
		unsigned int getTotalReadFileLength();
		unsigned int getLastReadFileLength();

		char currentChar();
		char nextChar();
		void rollback();

		string toString();
};