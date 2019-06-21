#pragma once

#include <vector>
#include "ASTExpression.h"

class ASTExpressionList : public ASTExpression
{
private:
	std::vector<ASTExpression*> expressionList;
public:
	ASTExpressionList() : ASTExpression(MiniJavaExpType::ExpressionList) { }

	~ASTExpressionList()
	{
		for (int i = 0; i < expressionList.size(); i++)
		{
			delete expressionList.at(i);
		}

		expressionList.clear();
	}

	void addExpression(ASTExpression* exp)
	{
		this->expressionList.push_back(exp);
	}

	std::vector<ASTExpression*>* getExpressionList()
	{
		return &this->expressionList;
	}
};