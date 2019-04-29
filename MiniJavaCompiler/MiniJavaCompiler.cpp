#include <iostream>
#include <string>

#include "scanner/MiniJavaScanner.h"

using namespace std;

int main()
{
	try
	{
		MiniJavaScanner scanner("../test/program.java");

		string token;

		while (!scanner.eof() && (token != "INVALID"))
		{
			token = scanner.nextToken();
			cout << token << " ";

			if (token == "OTHER")
				cout << endl;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
