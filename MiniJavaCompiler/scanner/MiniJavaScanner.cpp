#include "MiniJavaScanner.h"

MiniJavaScanner::MiniJavaScanner(string srcPath)
{
	this->bufferedInput = new BufferedInput(srcPath, DEFAULT_INPUT_BUFFER_SIZE);

	this->states = new DFAState[31]
	{
		DFAState("0", false), //			0
		DFAState("ID", true), //			1
		DFAState("ID", true), //			2
		DFAState("ID", true), //			3
		DFAState("ID", true), //			4
		DFAState("ID", true), //			5
		DFAState("PUBLIC", true), //		6
		DFAState("ID", true), //			7
		DFAState("ID", true), //			8
		DFAState("ID", true), //			9
		DFAState("ID", true), //			10
		DFAState("CLASS", true), //			11
		DFAState("ID", true), //			12
		DFAState("ID", true), //			13
		DFAState("ID", true), //			14
		DFAState("ID", true), //			15
		DFAState("ID", true), //			16
		DFAState("STATIC", true), //		17
		DFAState("ID", true), //			18
		DFAState("ID", true), //			19
		DFAState("ID", true), //			20
		DFAState("VOID", true), //			21
		DFAState("ID", true), //			22
		DFAState("IF", true), //			23
		DFAState("ID", true), //			24
		DFAState("ID", true), //			25
		DFAState("ID", true), //			26
		DFAState("ELSE", true), //			27
		DFAState("ID", true), //			28
		DFAState("OTHER", true), //			29
		DFAState("SEP", true) //			30
	};

	this->states[0].setNextState('p', 1);
	this->states[1].setNextState('u', 2);
	this->states[2].setNextState('b', 3);
	this->states[3].setNextState('l', 4);
	this->states[4].setNextState('i', 5);
	this->states[5].setNextState('c', 6);

	this->states[0].setNextState('c', 7);
	this->states[7].setNextState('l', 8);
	this->states[8].setNextState('a', 9);
	this->states[9].setNextState('s', 10);
	this->states[10].setNextState('s', 11);

	this->states[0].setNextState('s', 12);
	this->states[12].setNextState('t', 13);
	this->states[13].setNextState('a', 14);
	this->states[14].setNextState('t', 15);
	this->states[15].setNextState('i', 16);
	this->states[16].setNextState('c', 17);

	this->states[0].setNextState('v', 18);
	this->states[18].setNextState('o', 19);
	this->states[19].setNextState('i', 20);
	this->states[20].setNextState('d', 21);

	this->states[0].setNextState('i', 22);
	this->states[22].setNextState('f', 23);

	this->states[0].setNextState('e', 24);
	this->states[24].setNextState('l', 25);
	this->states[25].setNextState('s', 26);
	this->states[26].setNextState('e', 27);

	string alpha_0 = "abcdefghijklmnopqrstuvwxyz";
	string alpha_1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < alpha_0.length(); i++)
	{
		this->states[28].setNextState(alpha_0[i], 28);
	}

	for (int i = 0; i < alpha_1.length(); i++)
	{
		this->states[28].setNextState(alpha_1[i], 28);
	}

	alpha_0 = "abdfghjklmnoqrtuwxyz";

	for (int i = 0; i < alpha_0.length(); i++)
	{
		this->states[0].setNextState(alpha_0[i], 28);
	}

	for (int i = 0; i < alpha_1.length(); i++)
	{
		this->states[0].setNextState(alpha_1[i], 28);
	}

	alpha_0 = "(){}[],.;";

	for (int i = 0; i < alpha_0.length(); i++)
	{
		this->states[0].setNextState(alpha_0[i], 30);
	}

	this->states[0].setNextState('\n', 29);
	
	this->currLexeme = "";
}

MiniJavaScanner::~MiniJavaScanner()
{
	delete this->bufferedInput;
	delete [] this->states;
}

bool MiniJavaScanner::eof()
{
	return bufferedInput->isEnd();
}

string MiniJavaScanner::getToken()
{
	return currLexeme;
}

string MiniJavaScanner::nextToken()
{
	string currToken = "";
	currLexeme = "";

	stateStack.clear();
	stateStack.push_front(-1);

	int state = 0;
	char currChar;
	bool again = true;

	try
	{
		do
		{
			stateStack.push_front(state);

			currChar = bufferedInput->nextChar();

			if (currChar == ' ')
				continue;

			currLexeme.push_back(currChar);
			state = states[state].nextState(currChar);

			if (state == -1)
				again = false;

		} while (again);
	}
	catch (...)
	{

	}

	do
	{
		state = stateStack.front();
		stateStack.pop_front();

		if (!currLexeme.empty())
			currLexeme.pop_back();

		if (!bufferedInput->isBegin())
			bufferedInput->rollback();
	} while ((state != -1) && (!states[state].isTerminal()));

	if ((state != -1) && states[state].isTerminal())
		currToken = states[state].getToken();
	else
		currToken = "INVALID";

	if (currToken == "ID")
		currToken.append("('" + currLexeme + "')");

	if (currToken == "SEP")
		currToken.append("('" + currLexeme + "')");
	
	return currToken;
}