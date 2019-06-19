#pragma once

#include "antlr4/antlr4-runtime.h"

#include "ast/node/ASTProgramNode.h"
#include "ast/node/ASTMainClassNode.h"

class ASTVisitor
{
	public:
		virtual antlrcpp::Any visitProg(ASTProgramNode* program) = 0;
		virtual antlrcpp::Any visitMainClass(ASTMainClassNode* mainClass) = 0;
};