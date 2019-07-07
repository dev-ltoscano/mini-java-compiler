#pragma once

#include <string>

#include "structure/code/AsmFunction.hpp"
#include "structure/info/MiniJavaOp.h"

class AsmCodeGen
{
	public:
		static void addUninitializedVar(AsmFile* asmFile, std::string varId, MiniJavaType varType)
		{
			switch (varType)
			{
				case MiniJavaType::INT:
				{
					asmFile->addBss(varId + ": resb 4");
					break;
				}
				case MiniJavaType::STRING:
				{
					asmFile->addBss(varId + ": resw 1");
					break;
				}
				case MiniJavaType::BOOLEAN:
				{
					asmFile->addBss(varId + ": resb 1");
					break;
				}
			}
		}

		static void addConstantVar(AsmFile* asmFile, std::string varId, std::string varValue, MiniJavaType varType)
		{
			switch (varType)
			{
				case MiniJavaType::STRING:
				{
					asmFile->addData(varId + ": db " + varValue + ", 0");
					break;
				}
			}
		}

		static void soutString(AsmFunction* asmFunction, int msgId)
		{
			asmFunction->addBodyInstruction("mov rdi, string_format");
			asmFunction->addBodyInstruction("mov rsi, msg_" + to_string(msgId));
			asmFunction->addBodyInstruction("xor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void soutInteger(AsmFunction* asmFunction, int value)
		{
			asmFunction->addBodyInstruction("mov rdi, number_format");
			asmFunction->addBodyInstruction("mov rsi, " + to_string(value));
			asmFunction->addBodyInstruction("xor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void soutVar(AsmFunction* asmFunction, std::string varId, std::string varType)
		{
			if (varType == "String")
			{
				asmFunction->addBodyInstruction("mov rdi, string_format");
				asmFunction->addBodyInstruction("mov rsi, " + varId);
			}
			else if((varType == "int") || varType == "boolean")
			{
				asmFunction->addBodyInstruction("mov rdi, number_format");
				asmFunction->addBodyInstruction("mov rsi, [" + varId + "]");
			}
			
			asmFunction->addBodyInstruction("xor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void attArithmeticIntegerOp(AsmFunction* asmFunction, std::string varId, MiniJavaOp operation, int firstVal, int secondVal)
		{
			int resExp = 0;

			switch (operation)
			{
				case MiniJavaOp::SUM:
				{
					resExp = firstVal + secondVal;
					break;
				}
				case MiniJavaOp::SUB:
				{
					resExp = firstVal - secondVal;
					break;
				}
				case MiniJavaOp::MULT:
				{
					resExp = firstVal * secondVal;
					break;
				}
				case MiniJavaOp::DIV:
				{
					resExp = firstVal / secondVal;
					break;
				}
			}

			asmFunction->addBodyInstruction("mov qword [" + varId + "], " + to_string(resExp));
		}

		static void attArithmeticTwoVarOp(AsmFunction* asmFunction, std::string varId, MiniJavaOp operation, std::string firstVarId, std::string secondVarId)
		{
			switch (operation)
			{
				case MiniJavaOp::SUM:
				{
					asmFunction->addBodyInstruction("mov rdi, [" + firstVarId + "]");
					asmFunction->addBodyInstruction("mov rsi, [" + secondVarId + "]");
					asmFunction->addBodyInstruction("add rdi, rsi");
					asmFunction->addBodyInstruction("mov [" + varId + "], rdi");
					break;
				}
				case MiniJavaOp::SUB:
				{
					asmFunction->addBodyInstruction("mov rdi, [" + firstVarId + "]");
					asmFunction->addBodyInstruction("mov rsi, [" + secondVarId + "]");
					asmFunction->addBodyInstruction("sub rdi, rsi");
					asmFunction->addBodyInstruction("mov [" + varId + "], rdi");
					break;
				}
				case MiniJavaOp::MULT:
				{
					asmFunction->addBodyInstruction("mov rdi, [" + firstVarId + "]");
					asmFunction->addBodyInstruction("mov rsi, [" + secondVarId + "]");
					asmFunction->addBodyInstruction("imul rdi, rsi");
					asmFunction->addBodyInstruction("mov [" + varId + "], rdi");
					break;
				}
				case MiniJavaOp::DIV:
				{
					asmFunction->addBodyInstruction("xor edx, edx");
					asmFunction->addBodyInstruction("mov eax, [" + firstVarId + "]");
					asmFunction->addBodyInstruction("mov ecx, [" + secondVarId + "]");
					asmFunction->addBodyInstruction("div ecx");
					asmFunction->addBodyInstruction("mov [" + varId + "], eax");
					break;
				}
			}
		}
};