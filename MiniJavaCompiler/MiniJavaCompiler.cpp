#include <iostream>
#include <string>

#include "helper/input/BufferedInput.h"

using namespace std;

int main()
{
	try
	{
		BufferedInput bufferedInput("../test/test.txt", DEFAULT_INPUT_BUFFER_SIZE);

		cout << bufferedInput.getFileLength() << endl;
		cout << bufferedInput.getTotalReadFileLength() << endl;
		cout << bufferedInput.getLastReadFileLength() << endl << endl;
		cout << bufferedInput.toString() << endl << endl;

		try
		{
			while (true)
			{
				cout << bufferedInput.nextChar() << endl;
			}
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}

		cout << endl;

		try
		{
			while (true)
			{
				bufferedInput.rollback();
				cout << bufferedInput.currentChar() << endl;
			}
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
