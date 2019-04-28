#include "MiniJavaScanner.h"

MiniJavaScanner::MiniJavaScanner()
{
	this->currToken = "";
}

string MiniJavaScanner::getToken()
{
	return currToken;
}

string MiniJavaScanner::nextToken()
{
	return currToken;
}