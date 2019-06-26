/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <string>
#include <unordered_map>

#include "exception/MiniJavaCompilerException.h"

#include "ClassInfo.h"
#include "VarInfo.h"
#include "MethodInfo.h"

class ProgramInfo
{
	private:
		ClassInfo* mainClass = nullptr;
		std::unordered_map<std::string, ClassInfo*> classMap;
	public:
		ClassInfo* getMainClass();
		void addMainClass(ClassInfo* mainClass);

		void addClass(ClassInfo* cls);
		void addClassVar(std::string classId, VarInfo* var);
		void addClassMethod(std::string classId, MethodInfo* method);
		void addClassMethodParam(std::string classId, std::string methodId, VarInfo* param);
		void addClassMethodVar(std::string classId, std::string methodId, VarInfo* var);

		ClassInfo* getClass(std::string classId);
		VarInfo* getClassVar(std::string classId, std::string varId);
		MethodInfo* getClassMethod(std::string classId, std::string methodId);
		VarInfo* getClassMethodParam(std::string classId, std::string methodId, std::string paramId);
		VarInfo* getClassMethodVar(std::string classId, std::string methodId, std::string varId);

		std::unordered_map<std::string, ClassInfo*> getClassList();
		std::unordered_map<std::string, VarInfo*> getClassVarList(std::string classId);
		std::unordered_map<std::string, MethodInfo*> getClassMethodList(std::string classId);
};