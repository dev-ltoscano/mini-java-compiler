#pragma once

#include <string>
#include <unordered_map>

#include "VarInfo.h"
#include "MethodInfo.h"

struct ClassInfo
{
	std::string id;
	std::string inheritedClassId;
	std::unordered_map<std::string, VarInfo*> varInfoMap;
	std::unordered_map<std::string, MethodInfo*> methodInfoMap;
};