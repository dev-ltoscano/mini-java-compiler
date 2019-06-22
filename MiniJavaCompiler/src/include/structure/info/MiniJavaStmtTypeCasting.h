#pragma once

#include "ast/node/ASTStatement.h"
#include "ast/node/ASTStatementList.h"
#include "ast/node/ASTIf.h"
#include "ast/node/ASTIfElse.h"
#include "ast/node/ASTWhile.h"
#include "ast/node/ASTSout.h"
#include "ast/node/ASTAssign.h"
#include "ast/node/ASTAssignArray.h"
#include "ast/node/ASTMethodCall.h"

class MiniJavaStmtTypeCasting
{
public:
	static ASTIf* castToIf(ASTStatement* statement)
	{
		return dynamic_cast<ASTIf*>(statement);
	}

	static ASTIfElse* castToIfElse(ASTStatement* statement)
	{
		return dynamic_cast<ASTIfElse*>(statement);
	}

	static ASTWhile* castToWhile(ASTStatement* statement)
	{
		return dynamic_cast<ASTWhile*>(statement);
	}

	static ASTSout* castToSout(ASTStatement* statement)
	{
		return dynamic_cast<ASTSout*>(statement);
	}

	static ASTAssign* castToAssign(ASTStatement* statement)
	{
		return dynamic_cast<ASTAssign*>(statement);
	}

	static ASTAssignArray* castToAssignArray(ASTStatement* statement)
	{
		return dynamic_cast<ASTAssignArray*>(statement);
	}

	static ASTMethodCall* castToMethodCall(ASTStatement* statement)
	{
		return dynamic_cast<ASTMethodCall*>(statement);
	}

	static ASTStatementList* castToStmtList(ASTStatement* statement)
	{
		return dynamic_cast<ASTStatementList*>(statement);
	}
};