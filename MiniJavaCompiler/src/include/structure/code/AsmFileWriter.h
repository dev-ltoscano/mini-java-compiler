#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

#include "exception/MiniJavaCompilerException.h"
#include "structure/code/AsmFile.hpp"

class AsmFileWriter
{
	private:
		AsmFile* asmFile;
	public:
		AsmFileWriter(AsmFile* asmFile);
		~AsmFileWriter();

		void saveFile(std::string asmFilePath);
};