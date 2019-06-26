/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#pragma once

enum MiniJavaExpType
{ 
	LiteralInteger, LiteralBoolean, LiteralString, IdType, 
	NewObject, NewIntegerArray, Arithmetic, And, Or, Comp,
	Negation, Negative, Length, MethodCall,
	AccessIntegerArray, ExpressionList, Super, This
};