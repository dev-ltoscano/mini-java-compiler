#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "structure/code/AsmFunction.hpp"

class AsmFile
{
	private:
		std::vector<std::string> externFunctions;
		std::vector<std::string> dataSection;
		std::vector<std::string> bssSection;
		std::unordered_map<std::string, AsmFunction*> textSection;
	public:
		AsmFile()
		{
			this->dataSection.push_back("number_format: db '%d', 10, 0");
			this->dataSection.push_back("string_format: db '%s', 10, 0");
		}

		~AsmFile()
		{
			for (auto it = textSection.begin(); it != textSection.end(); it++)
			{
				delete it->second;
			}

			textSection.clear();
		}

		std::string getGlobalFunctionLabel()
		{
			return "main";
		}

		std::vector<std::string>* getExternFunctions()
		{
			return &this->externFunctions;
		}

		void addExternFunction(std::string extFunction)
		{
			if (std::find(externFunctions.begin(), externFunctions.end(), extFunction) == externFunctions.end())
			{
				externFunctions.push_back(extFunction);
			}
		}

		std::vector<std::string>* getDataSection()
		{
			return &this->dataSection;
		}

		void addData(std::string data)
		{
			dataSection.push_back(data);
		}

		std::vector<std::string>* getBssSection()
		{
			return &this->bssSection;
		}

		void addBss(std::string bss)
		{
			bssSection.push_back(bss);
		}

		std::unordered_map<std::string, AsmFunction*>* getTextSection()
		{
			return &this->textSection;
		}

		void addFunction(AsmFunction* asmFunction)
		{
			textSection.insert(pair<std::string, AsmFunction*>(asmFunction->getFunctionLabel(), asmFunction));
		}

		AsmFunction* getFunction(std::string functionLabel)
		{
			if ((functionLabel != "main") && (functionLabel.at(0) != '_'))
			{
				functionLabel = "_" + functionLabel;
			}

			return textSection.at(functionLabel);
		}
};