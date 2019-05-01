#pragma once

#include <string>
#include <forward_list>
#include <algorithm>
#include <regex>
#include <list>

#include "../helper/input/BufferedInput.h"
#include "../helper/dfa/DFA.h"

using namespace std;

struct TokenRegex
{
	string token;
	string regex;

	TokenRegex(string token, string regex)
	{
		this->token = token;
		this->regex = regex;
	}
};

class MiniJavaScanner
{
	private:
		BufferedInput *bufferedInput;

		DFA *states;
		forward_list<string> stateStack;

		string currToken;
		forward_list<string> invalidTokenList;
		list<TokenRegex> tokenRegexList;
	public:
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		bool isEnd();

		string getToken();
		string nextToken();

		forward_list<string> getInvalidTokenList();

};