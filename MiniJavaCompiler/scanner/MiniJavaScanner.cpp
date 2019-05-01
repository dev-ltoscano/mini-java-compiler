#include "MiniJavaScanner.h"

MiniJavaScanner::MiniJavaScanner(string srcPath)
{
	this->bufferedInput = new BufferedInput(srcPath, DEFAULT_INPUT_BUFFER_SIZE);

	this->states = new DFA();
	this->states->loadTransitions("transitions.txt");

	tokenRegexList.push_back(TokenRegex("CLASS", "class"));
	tokenRegexList.push_back(TokenRegex("PUBLIC", "public"));
	tokenRegexList.push_back(TokenRegex("STATIC", "static"));
	tokenRegexList.push_back(TokenRegex("VOID", "void"));
	tokenRegexList.push_back(TokenRegex("STRING", "String"));
	tokenRegexList.push_back(TokenRegex("INT", "int"));
	tokenRegexList.push_back(TokenRegex("NEW", "new"));
	tokenRegexList.push_back(TokenRegex("RETURN", "return"));
	tokenRegexList.push_back(TokenRegex("MAIN", "main"));
	tokenRegexList.push_back(TokenRegex("SOUT", "System.out.println"));
	tokenRegexList.push_back(TokenRegex("IF", "if"));
	tokenRegexList.push_back(TokenRegex("ELSE", "else"));
	tokenRegexList.push_back(TokenRegex("SUM", "\\+"));
	tokenRegexList.push_back(TokenRegex("SUB", "\\-"));
	tokenRegexList.push_back(TokenRegex("MULT", "\\*"));
	tokenRegexList.push_back(TokenRegex("ASSIGN", "\\="));
	tokenRegexList.push_back(TokenRegex("LESS", "\\<"));
	tokenRegexList.push_back(TokenRegex("LPAREN", "\\("));
	tokenRegexList.push_back(TokenRegex("RPAREN", "\\)"));
	tokenRegexList.push_back(TokenRegex("LCB", "\\{"));
	tokenRegexList.push_back(TokenRegex("RCB", "\\}"));
	tokenRegexList.push_back(TokenRegex("LSB", "\\["));
	tokenRegexList.push_back(TokenRegex("RSB", "\\]"));
	tokenRegexList.push_back(TokenRegex("COMMA", "\\,"));
	tokenRegexList.push_back(TokenRegex("DOT", "\\."));
	tokenRegexList.push_back(TokenRegex("SEMICOLON", "\\;"));
	tokenRegexList.push_back(TokenRegex("ID", "([a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])*"));
	tokenRegexList.push_back(TokenRegex("INTEGER", "([0-9])([0-9])*"));
	
	this->currToken = "";
}

MiniJavaScanner::~MiniJavaScanner()
{
	delete this->bufferedInput;
	delete this->states;
	tokenRegexList.clear();
}

bool MiniJavaScanner::isEnd()
{
	return bufferedInput->isEnd();
}

string MiniJavaScanner::getToken()
{
	return currToken;
}

string MiniJavaScanner::nextToken()
{
	currToken = "";

	string state = "<q0>";
	string lexeme = "";
	string invLexeme = "";
	char currChar;
	
	stateStack.clear();
	stateStack.push_front("-1");

	do
	{
		currChar = bufferedInput->nextChar();
		lexeme.push_back(currChar);

		if (states->getState(state)->isTerminal())
		{
			stateStack.clear();
		}

		stateStack.push_front(state);
		state = states->getState(state)->nextState(currChar);
	} while (state != "-1");

	while ((state != "-1") && !states->getState(state)->isTerminal());
	{
		if (!bufferedInput->isBegin() && (lexeme.size() > 1))
			bufferedInput->rollback();

		if (!lexeme.empty())
		{
			invLexeme.push_back(lexeme.back());
			lexeme.pop_back();
		}

		state = stateStack.front();
		stateStack.pop_front();
	}
	
	if ((state != "-1") && states->getState(state)->isTerminal())
	{
		for (auto it = tokenRegexList.begin(); it != tokenRegexList.end(); it++)
		{
			if (regex_match(lexeme, regex(it->regex)))
			{
				currToken = it->token;
				break;
			}
		}

		if (currToken == "ID")
			currToken.append("('" + lexeme + "')");
		else if (currToken == "INTEGER")
			currToken.append("('" + lexeme + "')");
	}
	else
	{

		if ((invLexeme != " ") && (invLexeme != "\n"))
		{
			invLexeme.append(" L" + to_string(bufferedInput->getLineCount()) + ":" + "C" + to_string(bufferedInput->getColumnCount()));
			invalidTokenList.push_front(invLexeme);
		}

		currToken = "INVALID";
	}
	
	return currToken;
}

forward_list<string> MiniJavaScanner::getInvalidTokenList()
{
	return invalidTokenList;
}