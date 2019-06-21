#pragma once

#include "ASTExpression.h"

class ASTSuper : public ASTExpression
{
	public:
		ASTSuper() : ASTExpression(MiniJavaExpType::Super) { }
};