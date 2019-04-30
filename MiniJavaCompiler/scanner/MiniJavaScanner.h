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

		DFAState *states;
		forward_list<int> stateStack;

		string currToken;
		forward_list<string> invalidTokenList;
	public:
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		bool isEnd();

		string getToken();
		string nextToken();

		forward_list<string> getInvalidTokenList();

};