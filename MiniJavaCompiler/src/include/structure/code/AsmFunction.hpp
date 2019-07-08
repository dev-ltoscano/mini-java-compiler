#pragma once

#include <string>
#include <vector>
#include <iostream>

class AsmFunction
{
	private:
		std::string functionLabel;
		std::vector<std::string> functionBody;
	public:
		AsmFunction(std::string functionLabel)
		{
			if ((functionLabel != "main") && (functionLabel.at(0) != '_'))
			{
				functionLabel = "_" + functionLabel;
			}

			this->functionLabel = functionLabel;
		}

		std::string getFunctionLabel()
		{
			return this->functionLabel;
		}

		void addBodyInstruction(std::string instruction)
		{
			this->functionBody.push_back(instruction);
		}

		void removeLastBodyInstruction()
		{
			this->functionBody.pop_back();
		}

		std::vector<std::string>* getFunctionBody()
		{
			return &this->functionBody;
		}
};