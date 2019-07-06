#include "structure/code/AsmFileWriter.h"

AsmFileWriter::AsmFileWriter(AsmFile* asmFile)
{
	this->asmFile = asmFile;
}

AsmFileWriter::~AsmFileWriter()
{
	delete this->asmFile;
}

void AsmFileWriter::saveFile(string asmFilePath)
{
	ofstream asmFileStream(asmFilePath);

	if (!asmFileStream.is_open())
	{
		throw MiniJavaCompilerException("Could not create assembly file");
	}

	asmFileStream << "global " << asmFile->getGlobalFunctionLabel() << endl;

	vector<string>* externFunctionList = asmFile->getExternFunctions();

	if (!externFunctionList->empty())
	{
		string extFunctions = "";

		extFunctions.append(externFunctionList->at(0));

		for (int i = 1; i < externFunctionList->size(); i++)
		{
			extFunctions.append(", ").append(externFunctionList->at(i));
		}

		asmFileStream << endl << "extern " << extFunctions << endl;
	}

	vector<string>* dataSection = asmFile->getDataSection();

	if (!dataSection->empty())
	{
		asmFileStream << endl << "section .data" << endl;

		for(int i = 0; i < dataSection->size(); i++)
		{
			asmFileStream << "\t" << dataSection->at(i) << endl;
		}
	}

	vector<string>* bssSection = asmFile->getBssSection();

	if (!bssSection->empty())
	{
		asmFileStream << endl << "section .bss" << endl;

		for (int i = 0; i < bssSection->size(); i++)
		{
			asmFileStream << "\t" << bssSection->at(i) << endl;
		}
	}

	unordered_map<string, AsmFunction*>* textSection = asmFile->getTextSection();

	if (!textSection->empty())
	{
		asmFileStream << endl << "section .text" << endl;

		AsmFunction* tmpFunction;

		for (auto it = textSection->begin(); it != textSection->end(); it++)
		{
			tmpFunction = it->second;

			asmFileStream << "\t" << tmpFunction->getFunctionLabel() << ":" << endl;

			vector<string>* asmFunctionBody = tmpFunction->getFunctionBody();

			for (int i = 0; i < asmFunctionBody->size(); i++)
			{
				asmFileStream << "\t\t" << asmFunctionBody->at(i) << endl;
			}
		}
	}

	asmFileStream.close();
}