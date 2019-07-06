/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

#include <string>

#include "exception/MiniJavaErrorListener.h"
#include "exception/MiniJavaCompilerException.h"

#include "ast/node/ASTProgram.h"
#include "structure/program/ProgramInfo.h"

class ASTBaseVisitor
{
	protected:
		MiniJavaErrorListener* errorListener;
		ASTProgram* astProgram;
		ProgramInfo* programInfo;

		std::string tmpClassId;
		std::string tmpMethodId;
	public:
		ASTBaseVisitor(ASTProgram* astProgram)
			: ASTBaseVisitor(nullptr, astProgram) { }

		ASTBaseVisitor(ASTProgram* astProgram, ProgramInfo* programInfo)
			: ASTBaseVisitor(nullptr, astProgram, programInfo) { }

		ASTBaseVisitor(MiniJavaErrorListener* errorListener, ASTProgram* astProgram)
		{
			this->errorListener = errorListener;
			this->astProgram = astProgram;
			this->programInfo = new ProgramInfo();
		}

		ASTBaseVisitor(MiniJavaErrorListener* errorListener, ASTProgram* astProgram, ProgramInfo* programInfo)
		{
			this->errorListener = errorListener;
			this->astProgram = astProgram;
			this->programInfo = programInfo;
		}

		MiniJavaError getError(ParserRuleContext* ctx, std::string msg)
		{
			antlr4::Token* firstToken = ctx->getStart();

			size_t errorLine = firstToken->getLine();
			size_t errorCollumn = firstToken->getCharPositionInLine();

			return MiniJavaError(errorLine, errorCollumn, msg);
		}

		size_t getErrorLine(antlr4::Token* token)
		{
			return token->getLine();
		}

		size_t getErrorCollumn(antlr4::Token* token)
		{
			return token->getCharPositionInLine() + 1;
		}

		ClassInfo* getClass(string classId)
		{
			try
			{
				return programInfo->getClass(classId);
			}
			catch (exception& ex)
			{
				throw MiniJavaCompilerException("The class '" + classId + "' was not declared");
			}
		}

		VarInfo* getVariable(string classId, string methodId, string varId, bool searchInSuperClass)
		{
			try
			{
				return programInfo->getClassMethodVar(classId, methodId, varId);
			}
			catch (exception& ex)
			{
				try
				{
					return programInfo->getClassMethodParam(classId, methodId, varId);
				}
				catch (exception& ex)
				{
					try
					{
						return programInfo->getClassVar(classId, varId);
					}
					catch (exception& ex)
					{
						if (searchInSuperClass)
						{
							ClassInfo* classInfo;

							try
							{
								classInfo = programInfo->getClass(classId);
							}
							catch (exception& ex)
							{
								throw MiniJavaCompilerException("The type '" + classId + "' is not a class type");
							}
							
							if (classInfo->inheritedClassId == "None")
							{
								throw MiniJavaCompilerException("The variable '" + varId + "' was not declared");
							}
							else
							{
								while (classInfo->inheritedClassId != "None")
								{
									classInfo = programInfo->getClass(classInfo->inheritedClassId);

									try
									{
										return programInfo->getClassVar(classInfo->id, varId);
									}
									catch (exception& ex)
									{

									}
								}

								throw MiniJavaCompilerException("The variable '" + varId + "' was not declared");
							}
						}
						else
						{
							throw MiniJavaCompilerException("The variable '" + varId + "' was not declared");
						}
					}
				}
			}
		}

		MethodInfo* getMethod(string classId, string methodId, bool searchInSuperClass)
		{
			try
			{
				return programInfo->getClassMethod(classId, methodId);
			}
			catch (exception& ex)
			{
				if (searchInSuperClass)
				{
					ClassInfo* classInfo;

					try
					{
						classInfo = programInfo->getClass(classId);
					}
					catch (exception& ex)
					{
						throw MiniJavaCompilerException("The type '" + classId + "' is not a class type");
					}
					
					if (classInfo->inheritedClassId == "None")
					{
						throw MiniJavaCompilerException("Class '" + classId + "' does not have method '" + methodId + "' and does not inherit from any superclass");
					}
					else
					{
						while (classInfo->inheritedClassId != "None")
						{
							classInfo = programInfo->getClass(classInfo->inheritedClassId);

							try
							{
								return programInfo->getClassMethod(classInfo->id, methodId);
							}
							catch (exception& ex)
							{

							}
						}

						throw MiniJavaCompilerException("Method '" + methodId + "' does not belong to class '" + classId + "' and its superclass");
					}
				}
				else
				{
					throw MiniJavaCompilerException("Method '" + methodId + "' not found in class '" + classId + "'");
				}
			}
		}
};