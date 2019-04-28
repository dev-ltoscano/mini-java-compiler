#pragma once

#include <string>

using namespace std;

class MiniJavaScanner
{
	private:
		string currToken;
	public:
		MiniJavaScanner();

		string getToken();
		string nextToken();
};