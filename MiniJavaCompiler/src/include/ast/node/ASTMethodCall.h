#pragma once

#include <string>

#include "ASTStatement.h"
#include "ASTExpression.h"
#include "ASTExpressionList.h"
#include "ASTSuper.h"
#include "ASTThis.h"
#include "ASTId.h"

class ASTMethodCall : public ASTStatement, public ASTExpression
{
	private:
		ASTSuper* superPtr;
		ASTThis* thisPtr;
		ASTExpression* parentExpression;
		ASTId* id;
		ASTExpressionList* params;
	public:
		ASTMethodCall(ASTSuper* superPtr, ASTThis* thisPtr, ASTId* id, ASTExpressionList* params)
		{
			this->superPtr = superPtr;
			this->thisPtr = thisPtr;
			this->parentExpression = nullptr;
			this->id = id;
			this->params = params;
		}

		~ASTMethodCall()
		{
			delete this->superPtr;
			delete this->thisPtr;
			delete this->parentExpression;
			delete this->id;
		}

		bool superCall()
		{
			return (superPtr != nullptr);
		}

		bool thisCall()
		{
			return (thisPtr != nullptr);
		}

		ASTExpression* getParentExpression()
		{
			return this->parentExpression;
		}

		void setParentExpression(ASTExpression* parentExpression)
		{
			this->parentExpression = parentExpression;
		}

		std::string getId()
		{
			return id->getId();
		}

		ASTExpressionList* getParams()
		{
			return this->params;
		}
};