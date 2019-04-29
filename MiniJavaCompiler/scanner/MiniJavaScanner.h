#pragma once

#include <string>
#include <forward_list>
#include <algorithm>

#include "../helper/input/BufferedInput.h"
#include "../helper/dfa/DFAState.h"

using namespace std;

class MiniJavaScanner
{
	private:
		BufferedInput *bufferedInput;

		DFAState* states;
		forward_list<int> stateStack;

		string currLexeme;
	public:
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		bool eof();

		string getToken();
		string nextToken();
};