/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "VarInfo.h"

struct MethodInfo
{
	std::string id;
	std::string returnType;
	std::vector<std::string> paramIndexMap;
	std::unordered_map<std::string, VarInfo*> paramInfoMap;
	std::unordered_map<std::string, VarInfo*> varInfoMap;
};