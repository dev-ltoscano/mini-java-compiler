/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "exception/MiniJavaErrorListener.h"
#include "lexer/MiniJavaLexer.h"
#include "parser/MiniJavaParser.h"
#include "semantic/MiniJavaSemantic.h"
#include "codegen/MiniJavaCodeGen.h"

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

		MiniJavaParser::ProgContext *progCtx = miniJavaParser.prog();

		MiniJavaSemantic miniJavaSemantic;
		CodeStruct codeStruct = miniJavaSemantic.analyze(progCtx);

		if (lexerErrorListener.hasErrors())
		{
			cout << "Lexical errors:" << endl;
			lexerErrorListener.printErrorList();
		}
		
		if (parserErrorListener.hasErrors())
		{
			cout << "Syntactic errors:" << endl;
			parserErrorListener.printErrorList();
		}

		if (miniJavaSemantic.hasErrors())
		{
			cout << "Semantic errors:" << endl;
			miniJavaSemantic.printErrorList();
		}
		
		if(!lexerErrorListener.hasErrors() && !parserErrorListener.hasErrors() && !miniJavaSemantic.hasErrors())
		{
			//cout << "The program has no lexical, syntactic and semantic errors" << endl;

			MiniJavaCodeGen miniJavaCodeGen(&codeStruct);
			miniJavaCodeGen.generateCode();
		}

		srcFileStream.close();
	}
	catch (exception & ex)
	{
		cout << ">> ERROR: " << ex.what() << endl;
	}

	return 0;
}
