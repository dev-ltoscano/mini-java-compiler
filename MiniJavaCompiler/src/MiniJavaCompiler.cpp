#include <iostream>
#include <fstream>
#include <stdexcept>

#include "scanner/MiniJavaLexer.h"
#include "parser/MiniJavaParser.h"
#include "error/MiniJavaErrorListener.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::dfa;
using namespace antlr4::tree;

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cout << "USAGE: mjavac <path_to_src_file>" << endl;
		return 0;
	}

	try
	{
		ifstream srcFileStream(argv[1]);

		if (!srcFileStream.is_open())
		{
			throw runtime_error("Could not open file");
		}

		ANTLRInputStream antlrInputStream(srcFileStream);

		MiniJavaLexer miniJavaLexer(&antlrInputStream);
		MiniJavaErrorListener lexerErrorListener;
		miniJavaLexer.removeErrorListeners();
		miniJavaLexer.addErrorListener(&lexerErrorListener);

		CommonTokenStream tokens(&miniJavaLexer);

		MiniJavaParser miniJavaParser(&tokens);
		MiniJavaErrorListener parserErrorListener;
		miniJavaParser.removeErrorListeners();
		miniJavaParser.addErrorListener(&parserErrorListener);

		miniJavaParser.prog();

		cout << endl;

		if (lexerErrorListener.hasErrors())
		{
			cout << "Lexical errors:" << endl;
			lexerErrorListener.printErrorList();
			cout << endl;
		}
		
		if (parserErrorListener.hasErrors())
		{
			cout << "Syntactic errors:" << endl;
			parserErrorListener.printErrorList();
			cout << endl;
		}

		if(!lexerErrorListener.hasErrors() && !parserErrorListener.hasErrors())
		{
			cout << "The program has no lexical and syntactic errors" << endl;
		}

		srcFileStream.close();
	}
	catch (exception & ex)
	{
		cout << ">> ERROR: " << ex.what() << endl;
	}

	return 0;
}
