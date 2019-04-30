#include <iostream>
#include <string>
#include <forward_list>

#include "scanner/MiniJavaScanner.h"

using namespace std;

int main()
{
	try
	{
		MiniJavaScanner scanner("../test/program.java");

		string token;

		while (!scanner.isEnd())
		{
			token = scanner.nextToken();
			
			if (token == "NL")
				cout << token << endl;
			else
			{
				cout << token << " ";
			}
		}

		cout << endl << endl;

		cout << "Invalid tokens:" << endl;
		forward_list<string> invalidTokenList = scanner.getInvalidTokenList();

		for (auto it = invalidTokenList.begin(); it != invalidTokenList.end(); it++)
			cout << " " << *it << endl;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
