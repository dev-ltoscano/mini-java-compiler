#include <iostream>
#include <string>

#include "scanner/MiniJavaScanner.h"
#include "helper/dfa/DFA.h"

using namespace std;

int main()
{
	try
	{
		MiniJavaScanner *scanner = new MiniJavaScanner("../test/test.txt");
		
		string token;

		while (!scanner->isEnd())
		{
			token = scanner->nextToken();

			if(token != "INVALID")
				cout << token << endl;
		}

		list<string> invalidTokenList = scanner->getInvalidTokenList();

		if (invalidTokenList.size() > 0)
		{
			cout << endl << "Lexical errors:" << endl;

			for (auto it = invalidTokenList.begin(); it != invalidTokenList.end(); it++)
				cout << " " << *it << endl;
		}

		delete scanner;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
