#pragma once

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

		unsigned int lineCount, columnCount;
		
		void loadBuffer();
	public:
		BufferedInput(string inputFilepath, unsigned int bufferSize);
		~BufferedInput();

		unsigned int getFileLength();
		unsigned int getTotalReadFileLength();

		bool isBegin();
		bool isEnd();

		char currentChar();
		char nextChar();
		void rollback();

		string toString();

		unsigned int getLineCount();
		unsigned int getColumnCount();
};