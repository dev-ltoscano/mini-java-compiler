/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "structure/program/ProgramInfo.h"

using namespace std;

ClassInfo* ProgramInfo::getMainClass()
{
	return this->mainClass;
}

void ProgramInfo::addMainClass(ClassInfo* mainClass)
{
	this->mainClass = mainClass;
	classMap.insert(make_pair(mainClass->id, mainClass));
}

void ProgramInfo::addClass(ClassInfo* cls)
{
	if (cls->id == mainClass->id)
	{
		throw MiniJavaCompilerException("The main class '" + cls->id + "' already defined");
	}

	if (classMap.find(cls->id) != classMap.end())
	{
		throw MiniJavaCompilerException("Class '" + cls->id + "' already defined");
	}

	classMap.insert(make_pair(cls->id, cls));
}

void ProgramInfo::addClassVar(string classId, VarInfo* var)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw MiniJavaCompilerException("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->varInfoMap.find(var->id) != classMap.at(classId)->varInfoMap.end())
	{
		throw MiniJavaCompilerException("Variable '" + var->id + "' already defined in class '" + classId + "'");
	}

	if (classId == mainClass->id)
	{
		mainClass->varInfoMap.insert(make_pair(var->id, var));
	}
	else
	{
		classMap.at(classId)->varInfoMap.insert(make_pair(var->id, var));
	}
}

void ProgramInfo::addClassMethod(string classId, MethodInfo* method)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw MiniJavaCompilerException("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(method->id) != classMap.at(classId)->methodInfoMap.end())
	{
		throw MiniJavaCompilerException("Method '" + method->id + "' already defined in class '" + classId + "'");
	}

	if (classId == mainClass->id)
	{
		mainClass->methodInfoMap.insert(make_pair(method->id, method));
	}
	else
	{
		classMap.at(classId)->methodInfoMap.insert(make_pair(method->id, method));
	}
}

void ProgramInfo::addClassMethodParam(std::string classId, std::string methodId, VarInfo* param)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw MiniJavaCompilerException("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(methodId) == classMap.at(classId)->methodInfoMap.end())
	{
		throw MiniJavaCompilerException("Method '" + methodId + "' not defined in class '" + classId + "'");
	}

	if (classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.find(param->id) != classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.end())
	{
		throw MiniJavaCompilerException("The parameter '" + param->id + "' already defined in method '" + methodId + "' in class '" + classId + "'");
	}

	if (classId == mainClass->id)
	{
		mainClass->methodInfoMap.at(methodId)->paramInfoMap.insert(make_pair(param->id, param));
		mainClass->methodInfoMap.at(methodId)->paramIndexMap.push_back(param->id);
	}
	else
	{
		classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.insert(make_pair(param->id, param));
		classMap.at(classId)->methodInfoMap.at(methodId)->paramIndexMap.push_back(param->id);
	}
}

void ProgramInfo::addClassMethodVar(std::string classId, std::string methodId, VarInfo* var)
{
	if (classMap.find(classId) == classMap.end())
	{
		throw MiniJavaCompilerException("Class '" + classId + "' not defined");
	}

	if (classMap.at(classId)->methodInfoMap.find(methodId) == classMap.at(classId)->methodInfoMap.end())
	{
		throw MiniJavaCompilerException("Method '" + methodId + "' not defined in class '" + classId + "'");
	}

	if (classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.find(var->id) != classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.end())
	{
		throw MiniJavaCompilerException("The variable '" + var->id + "' already defined in '" + methodId + "' in class '" + classId + "'");
	}

	if (classId == mainClass->id)
	{
		mainClass->methodInfoMap.at(methodId)->varInfoMap.insert(make_pair(var->id, var));
	}
	else
	{
		classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.insert(make_pair(var->id, var));
	}
}

ClassInfo* ProgramInfo::getClass(std::string classId)
{
	if (classId == mainClass->id)
	{
		return mainClass;
	}
	else
	{
		return classMap.at(classId);
	}
}

VarInfo* ProgramInfo::getClassVar(std::string classId, std::string varId)
{
	if (classId == mainClass->id)
	{
		return mainClass->varInfoMap.at(varId);
	}
	else
	{
		return classMap.at(classId)->varInfoMap.at(varId);
	}
}

MethodInfo* ProgramInfo::getClassMethod(std::string classId, std::string methodId)
{
	if (classId == mainClass->id)
	{
		return mainClass->methodInfoMap.at(methodId);
	}
	else
	{
		return classMap.at(classId)->methodInfoMap.at(methodId);
	}
}

VarInfo* ProgramInfo::getClassMethodParam(std::string classId, std::string methodId, std::string paramId)
{
	if (classId == mainClass->id)
	{
		return mainClass->methodInfoMap.at(methodId)->paramInfoMap.at(paramId);
	}
	else
	{
		return classMap.at(classId)->methodInfoMap.at(methodId)->paramInfoMap.at(paramId);
	}
}

VarInfo* ProgramInfo::getClassMethodVar(std::string classId, std::string methodId, std::string varId)
{
	if (classId == mainClass->id)
	{
		return mainClass->methodInfoMap.at(methodId)->varInfoMap.at(varId);
	}
	else
	{
		return classMap.at(classId)->methodInfoMap.at(methodId)->varInfoMap.at(varId);
	}
}

unordered_map<std::string, ClassInfo*> ProgramInfo::getClassList()
{
	return classMap;
}

unordered_map<string, VarInfo*> ProgramInfo::getClassVarList(string classId)
{
	if (classId == mainClass->id)
	{
		return mainClass->varInfoMap;
	}
	else
	{
		return classMap.at(classId)->varInfoMap;
	}
}

unordered_map<string, MethodInfo*> ProgramInfo::getClassMethodList(string classId)
{
	if (classId == mainClass->id)
	{
		return mainClass->methodInfoMap;
	}
	else
	{
		return classMap.at(classId)->methodInfoMap;
	}
}