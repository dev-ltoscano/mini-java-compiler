#pragma once

enum MiniJavaExpType
{ 
	LiteralInteger, LiteralBoolean, LiteralString, IdType, 
	NewObject, NewIntegerArray, And, Or, Comp,
	Negation, Negative, Length, MethodCall,
	AccessIntegerArray, ExpressionList, Super, This
};