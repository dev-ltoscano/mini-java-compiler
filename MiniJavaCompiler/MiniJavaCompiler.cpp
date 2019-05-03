#include <iostream>
#include <string>

#include "scanner/MiniJavaScanner.h"
#include "helper/dfa/DFA.h"

#include "helper/input/BufferedInput.h"

using namespace std;

int main(int argc, char** argv)
{
	MiniJavaScanner *scanner = NULL;

	try
	{
		if (argc > 1)
		{
			scanner = new MiniJavaScanner(argv[1]);
		}
		else
		{
			scanner = new MiniJavaScanner("../test/test.txt");
		}

		string tokenType;

		while (!scanner->isEnd())
		{
			tokenType = scanner->nextToken();

			if((tokenType != "ESCAPE") && (tokenType != "INVALID"))
				cout << tokenType << endl;
		}

		list<string> invalidTokenList = scanner->getInvalidTokenList();

		if (invalidTokenList.size() > 0)
		{
			cout << endl << "Lexical errors:" << endl;

			for (auto it = invalidTokenList.begin(); it != invalidTokenList.end(); it++)
				cout << " " << *it << endl;
		}
	}
	catch (exception &ex)
	{
		cout << ">> ERROR: " << ex.what() << endl;
	}

	if(scanner != NULL)
		delete scanner;

	return 0;
}
