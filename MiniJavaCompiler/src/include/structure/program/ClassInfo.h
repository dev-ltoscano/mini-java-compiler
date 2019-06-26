/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

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