#pragma once

#include "ASTExpression.h"

class ASTThis : public ASTExpression
{
	public:
		ASTThis() : ASTExpression(MiniJavaExpType::This) { }
};