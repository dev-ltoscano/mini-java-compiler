#pragma once

#include "MiniJavaExpType.h"

#include "ast/node/ASTExpressionList.h"
#include "ast/node/ASTLiteralBoolean.h"
#include "ast/node/ASTLiteralInteger.h"
#include "ast/node/ASTLiteralString.h"
#include "ast/node/ASTId.h"
#include "ast/node/ASTSuper.h"
#include "ast/node/ASTThis.h"
#include "ast/node/ASTMethodCall.h"
#include "ast/node/ASTNewObject.h"
#include "ast/node/ASTNewIntegerArray.h"
#include "ast/node/ASTAnd.h"
#include "ast/node/ASTOr.h"
#include "ast/node/ASTComp.h"
#include "ast/node/ASTNegation.h"
#include "ast/node/ASTNegative.h"
#include "ast/node/ASTAccessIntegerArray.h"
#include "ast/node/ASTLength.h"
#include "ast/node/ASTArithmetic.h"

class MiniJavaExpTypeCasting
{
public:
	static ASTLiteralInteger* castToLiteralInteger(ASTExpression* expression)
	{
		return dynamic_cast<ASTLiteralInteger*>(expression);
	}

	static ASTLiteralBoolean* castToLiteralBoolean(ASTExpression* expression)
	{
		return dynamic_cast<ASTLiteralBoolean*>(expression);
	}

	static ASTLiteralString* castToLiteralString(ASTExpression* expression)
	{
		return dynamic_cast<ASTLiteralString*>(expression);
	}

	static ASTId* castToId(ASTExpression* expression)
	{
		return dynamic_cast<ASTId*>(expression);
	}

	static ASTNewObject* castToNewObject(ASTExpression* expression)
	{
		return dynamic_cast<ASTNewObject*>(expression);
	}

	static ASTNewIntegerArray* castToNewIntegerArray(ASTExpression* expression)
	{
		return dynamic_cast<ASTNewIntegerArray*>(expression);
	}

	static ASTArithmetic* castToArithmetic(ASTExpression* expression)
	{
		return dynamic_cast<ASTArithmetic*>(expression);
	}

	static ASTAnd* castToAnd(ASTExpression* expression)
	{
		return dynamic_cast<ASTAnd*>(expression);
	}

	static ASTOr* castToOr(ASTExpression* expression)
	{
		return dynamic_cast<ASTOr*>(expression);
	}

	static ASTComp* castToComp(ASTExpression* expression)
	{
		return dynamic_cast<ASTComp*>(expression);
	}

	static ASTNegation* castToNegation(ASTExpression* expression)
	{
		return dynamic_cast<ASTNegation*>(expression);
	}

	static ASTNegative* castToNegative(ASTExpression* expression)
	{
		return dynamic_cast<ASTNegative*>(expression);
	}

	static ASTLength* castToLength(ASTExpression* expression)
	{
		return dynamic_cast<ASTLength*>(expression);
	}

	static ASTMethodCall* castToMethodCall(ASTExpression* expression)
	{
		return dynamic_cast<ASTMethodCall*>(expression);
	}

	static ASTAccessIntegerArray* castToExpressionArray(ASTExpression* expression)
	{
		return dynamic_cast<ASTAccessIntegerArray*>(expression);
	}

	static ASTExpressionList* castToExpressionList(ASTExpression* expression)
	{
		return dynamic_cast<ASTExpressionList*>(expression);
	}

	static ASTSuper* castToSuper(ASTExpression* expression)
	{
		return dynamic_cast<ASTSuper*>(expression);
	}

	static ASTThis* castToThis(ASTExpression* expression)
	{
		return dynamic_cast<ASTThis*>(expression);
	}
};