#pragma once

#include <string>
#include <forward_list>
#include <list>

#include "../helper/input/BufferedInput.h"
#include "../helper/token/JavaToken.h"

using namespace std;

class MiniJavaScanner
{
	private:
		BufferedInput *bufferedInput;

		JavaToken javaTokens;
		string currToken;
		list<string> invalidTokenList;
	public:
		MiniJavaScanner(string srcPath);
		~MiniJavaScanner();

		bool isEnd();

		string getToken();
		string nextToken();
		list<string> getInvalidTokenList();
};