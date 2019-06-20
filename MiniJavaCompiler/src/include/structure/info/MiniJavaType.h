#pragma once

enum MiniJavaType { VOID, INT_ARRAY, INT, BOOLEAN, STRING_ARRAY, STRING, ID };

inline const char* typeToString(MiniJavaType type)
{
	switch (type)
	{
		case VOID:
			return "void";
		case INT_ARRAY:
			return "int[]";
		case INT:
			return "int";
		case BOOLEAN:
			return "boolean";
		case STRING_ARRAY:
			return "String[]";
		case STRING:
			return "String";
		case ID:
			return "ID";
		default:
			return "Unknown";
	}
}