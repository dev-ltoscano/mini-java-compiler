#pragma once

#include "ast/node/ASTProgram.h"
#include "structure/program/ProgramInfo.h"

struct CodeStruct
{
	ASTProgram* astProgram;
	ProgramInfo* programInfo;

	CodeStruct(ASTProgram* astProgram, ProgramInfo* programInfo)
	{
		this->astProgram = astProgram;
		this->programInfo = programInfo;
	}
};