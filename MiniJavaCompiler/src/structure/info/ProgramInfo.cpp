#include "structure/info/ProgramInfo.h"

using namespace std;

void ProgramInfo::addClass(ClassInfo* cls)
{
	if (classMap.find(cls->id) != classMap.end())
	{
		throw runtime_error("Class '" + cls->id + "' already defined");
	}

	classMap.insert(make_pair(cls->id, cls));
}

void ProgramInfo::addClassVar(string classId, VarInfo* var)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw runtime_error("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->varInfoMap.find(var->id) != classMap.at(classId)->varInfoMap.end())
	{
		throw runtime_error("Variable '" + var->id + "' already defined in class '" + classId + "'");
	}

	classMap.at(classId)->varInfoMap.insert(make_pair(var->id, var));
}

void ProgramInfo::addClassMethod(string classId, MethodInfo* method)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw runtime_error("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(method->id) != classMap.at(classId)->methodInfoMap.end())
	{
		throw runtime_error("Method '" + method->id + "' already defined in class '" + classId + "'");
	}

	classMap.at(classId)->methodInfoMap.insert(make_pair(method->id, method));
}

void ProgramInfo::addClassMethodParam(std::string classId, std::string methodId, VarInfo* param)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw runtime_error("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(methodId) == classMap.at(classId)->methodInfoMap.end())
	{
		throw runtime_error("Method '" + methodId + "' not defined in class '" + classId + "'");
	}

	if (classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.find(param->id) != classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.end())
	{
		throw runtime_error("The parameter '" + param->id + "' already defined in method '" + methodId + "' in class '" + classId + "'");
	}

	classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.insert(make_pair(param->id, param));
	classMap.at(classId)->methodInfoMap.at(methodId)->paramIndexMap.push_back(param->id);
}

void ProgramInfo::addClassMethodVar(std::string classId, std::string methodId, VarInfo* var)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw runtime_error("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(methodId) == classMap.at(classId)->methodInfoMap.end())
	{
		throw runtime_error("Method '" + methodId + "' not defined in class '" + classId + "'");
	}

	if (classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.find(var->id) != classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.end())
	{
		throw runtime_error("The variable '" + var->id + "' already defined in '" + methodId + "' in class '" + classId + "'");
	}

	classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.insert(make_pair(var->id, var));
}

ClassInfo* ProgramInfo::getClass(std::string classId)
{
	return classMap.at(classId);
}

VarInfo* ProgramInfo::getClassVar(std::string classId, std::string varId)
{
	return classMap.at(classId)->varInfoMap.at(varId);
}

MethodInfo* ProgramInfo::getClassMethod(std::string classId, std::string methodId)
{
	return classMap.at(classId)->methodInfoMap.at(methodId);
}

VarInfo* ProgramInfo::getClassMethodParam(std::string classId, std::string methodId, std::string paramId)
{
	return classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.at(paramId);
}

VarInfo* ProgramInfo::getClassMethodVar(std::string classId, std::string methodId, std::string varId)
{
	return classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.at(varId);
}

unordered_map<std::string, ClassInfo*> ProgramInfo::getClassList()
{
	return classMap;
}

unordered_map<string, VarInfo*> ProgramInfo::getClassVarList(string classId)
{
	return classMap.at(classId)->varInfoMap;
}

unordered_map<string, MethodInfo*> ProgramInfo::getClassMethodList(string classId)
{
	return classMap.at(classId)->methodInfoMap;
}