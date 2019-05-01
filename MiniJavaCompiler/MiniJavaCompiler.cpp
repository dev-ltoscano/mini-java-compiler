#include <iostream>
#include <string>
#include <forward_list>

#include "scanner/MiniJavaScanner.h"

using namespace std;

int main()
{
	try
	{
		MiniJavaScanner *scanner = new MiniJavaScanner("../test/program.java");
		
		string token;

		while (!scanner->isEnd())
		{
			token = scanner->nextToken();

			if(token != "INVALID")
				cout << token << " ";
		}

		cout << endl << endl;

		forward_list<string> invalidTokenList = scanner->getInvalidTokenList();

		cout << "Lexical errors:" << endl;
		
		for (auto it = invalidTokenList.begin(); it != invalidTokenList.end(); it++)
			cout << " " << *it << endl;

		delete scanner;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
