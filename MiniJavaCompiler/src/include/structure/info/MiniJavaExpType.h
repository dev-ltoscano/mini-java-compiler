/*
*	Jefferson do Nascimento Amar� (201765125C)
*	Luis Augusto Toscano Guimar�es (201365165AC)
*/

#pragma once

enum MiniJavaExpType
{ 
	LiteralInteger, LiteralBoolean, LiteralString, IdType, 
	NewObject, NewIntegerArray, Arithmetic, And, Or, Comp,
	Negation, Negative, Length, MethodCall,
	AccessIntegerArray, ExpressionList, Super, This
};