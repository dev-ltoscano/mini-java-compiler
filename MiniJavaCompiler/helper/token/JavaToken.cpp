#include "JavaToken.h"

JavaToken::JavaToken()
{
	this->tokenDFA = new DFA();
	this->tokenDFA->loadTransitions("automaton.txt");

	this->tokenTypeList.push_back(JavaTokenType("PACKAGE", "package"));
	this->tokenTypeList.push_back(JavaTokenType("IMPORT", "import"));
	this->tokenTypeList.push_back(JavaTokenType("CLASS", "class"));
	this->tokenTypeList.push_back(JavaTokenType("INTERFACE", "interface"));
	this->tokenTypeList.push_back(JavaTokenType("EXTENDS", "extends"));
	this->tokenTypeList.push_back(JavaTokenType("IMPLEMENTS", "implements"));
	this->tokenTypeList.push_back(JavaTokenType("THIS", "this"));
	this->tokenTypeList.push_back(JavaTokenType("SUPER", "super"));
	this->tokenTypeList.push_back(JavaTokenType("NEW", "new"));
	this->tokenTypeList.push_back(JavaTokenType("NULL", "null"));
	this->tokenTypeList.push_back(JavaTokenType("RETURN", "return"));
	this->tokenTypeList.push_back(JavaTokenType("ACCESS_MODIFIER", "public|private|protected|static|final|abstract|const|synchronized|volatile|transient"));
	this->tokenTypeList.push_back(JavaTokenType("TYPE", "int|long|short|float|double|char|String|boolean|byte|enum|void"));
	this->tokenTypeList.push_back(JavaTokenType("INSTANCEOF", "instanceof"));
	this->tokenTypeList.push_back(JavaTokenType("ASSIGN", "\\="));
	this->tokenTypeList.push_back(JavaTokenType("MATH_OP", "\\+|\\-|\\*|\\/|\\%"));
	this->tokenTypeList.push_back(JavaTokenType("COMP_OP", "\\<|\\>|\\<\\=|\\>\\=|\\=\\=|\\!\\="));
	this->tokenTypeList.push_back(JavaTokenType("LOGICAL_OP", "\\&\\&|\\|\\||\\!"));
	this->tokenTypeList.push_back(JavaTokenType("INC_OP", "\\+\\+"));
	this->tokenTypeList.push_back(JavaTokenType("DEC_OP", "\\-\\-"));
	this->tokenTypeList.push_back(JavaTokenType("BITWISE_OP", "\\<\\<|\\>\\>|\\^"));
	this->tokenTypeList.push_back(JavaTokenType("COND_OP", "\\?|\\:"));
	this->tokenTypeList.push_back(JavaTokenType("IF", "if"));
	this->tokenTypeList.push_back(JavaTokenType("ELSE", "else"));
	this->tokenTypeList.push_back(JavaTokenType("SWITCH", "switch"));
	this->tokenTypeList.push_back(JavaTokenType("CASE", "case"));
	this->tokenTypeList.push_back(JavaTokenType("DEFAULT", "default"));
	this->tokenTypeList.push_back(JavaTokenType("ASSERT", "assert"));
	this->tokenTypeList.push_back(JavaTokenType("FOR", "for"));
	this->tokenTypeList.push_back(JavaTokenType("WHILE", "while"));
	this->tokenTypeList.push_back(JavaTokenType("DO", "do"));
	this->tokenTypeList.push_back(JavaTokenType("GOTO", "GOTO"));
	this->tokenTypeList.push_back(JavaTokenType("CONTINUE", "continue"));
	this->tokenTypeList.push_back(JavaTokenType("BREAK", "break"));
	this->tokenTypeList.push_back(JavaTokenType("TRY", "try"));
	this->tokenTypeList.push_back(JavaTokenType("CATCH", "catch"));
	this->tokenTypeList.push_back(JavaTokenType("FINALLY", "finally"));
	this->tokenTypeList.push_back(JavaTokenType("THROWS", "throws"));
	this->tokenTypeList.push_back(JavaTokenType("THROW", "throw"));
	this->tokenTypeList.push_back(JavaTokenType("NATIVE", "native"));
	this->tokenTypeList.push_back(JavaTokenType("STRICTFP", "strictfp"));
	this->tokenTypeList.push_back(JavaTokenType("COMMA", "\\,"));
	this->tokenTypeList.push_back(JavaTokenType("DOT", "\\."));
	this->tokenTypeList.push_back(JavaTokenType("SC", "\\;"));
	this->tokenTypeList.push_back(JavaTokenType("LCB", "\\{"));
	this->tokenTypeList.push_back(JavaTokenType("RCB", "\\}"));
	this->tokenTypeList.push_back(JavaTokenType("LP", "\\("));
	this->tokenTypeList.push_back(JavaTokenType("RP", "\\)"));
	this->tokenTypeList.push_back(JavaTokenType("LSB", "\\["));
	this->tokenTypeList.push_back(JavaTokenType("RSB", "\\]"));
	this->tokenTypeList.push_back(JavaTokenType("MAIN", "main"));
	this->tokenTypeList.push_back(JavaTokenType("SOUT", "System.out.println"));
	this->tokenTypeList.push_back(JavaTokenType("LENGTH", "length"));
	this->tokenTypeList.push_back(JavaTokenType("BOOLEAN", "true|false"));
	this->tokenTypeList.push_back(JavaTokenType("ID", "([a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])*"));
	this->tokenTypeList.push_back(JavaTokenType("INTEGER", "([0-9])([0-9])*"));
}

JavaToken::~JavaToken()
{
	this->tokenTypeList.clear();
}

DFAState* JavaToken::getTokenDFAState(string stateId)
{
	return this->tokenDFA->getState(stateId);
}

string JavaToken::getTokenType(string lexeme)
{
	for (auto it = tokenTypeList.begin(); it != tokenTypeList.end(); it++)
	{
		if (regex_match(lexeme, regex(it->regex)))
		{
			return it->type;
		}
	}

	return "INVALID";
}