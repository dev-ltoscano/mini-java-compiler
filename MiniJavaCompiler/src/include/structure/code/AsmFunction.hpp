#pragma once

#include <string>
#include <vector>

class AsmFunction
{
	private:
		std::string functionLabel;
		std::vector<std::string> functionBody;
	public:
		AsmFunction(std::string functionLabel)
		{
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

		std::vector<std::string>* getFunctionBody()
		{
			return &this->functionBody;
		}
};