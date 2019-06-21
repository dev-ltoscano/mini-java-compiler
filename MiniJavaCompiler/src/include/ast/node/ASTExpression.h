#pragma once

#include "structure/info/MiniJavaExpType.h"

class ASTExpression
{
	private:
		MiniJavaExpType expressionType;
	public:
		ASTExpression(MiniJavaExpType expressionType)
		{
			this->expressionType = expressionType;
		}

		virtual ~ASTExpression() = default;

		MiniJavaExpType getExpressionType()
		{
			return this->expressionType;
		}
};