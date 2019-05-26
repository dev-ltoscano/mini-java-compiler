grammar minijavaGrammar;

prog
:	mainClass classDeclaration* EOF
;

mainClass	
:	CLASS ID LCB PUBLIC STATIC VOID MAIN LP STRING LSB RSB ID RP LCB statement* RCB RCB;

classDeclaration	
:	CLASS ID ( EXTENDS ID )? LCB fieldDeclaration* methodDeclaration* RCB;

fieldDeclaration
:	varDeclaration ;

localDeclaration
:	varDeclaration ;

varDeclaration	
:	type ID SC;

methodDeclaration	
:	PUBLIC type ID LP parameterList? RP LCB methodBody RCB;

parameterList
:   parameter (COMMA parameter)*
;

parameter
:   type ID
;

methodBody
:	localDeclaration* statement* RETURN expression SC
;

type	
:	INT LSB RSB
|	BOOLEAN_TYPE
|	INT
|	ID
|   TYPES
;	

statement	
:	LCB statement* RCB
|	IF LP expression RP ifBlock ELSE elseBlock
|	WHILE LP expression RP whileBlock
|   FOR LP INT ID ASSIGN INTEGER SC ID COMP_OP INTEGER SC ID INC_OP RP forBlock
|	SOUT LP  expression RP SC
|	ID ASSIGN expression SC
|	ID LSB expression RSB ASSIGN expression SC
|   BREAK SC
;	

ifBlock
:	statement
;

elseBlock
:	statement
;

whileBlock
:	statement
;

forBlock
:   statement
;

expression
:   expression LSB expression RSB

|   expression DOT LENGTH

|   expression DOT ID LP ( expression ( COMMA expression )* )? RP

|   NOT expression

|   NEW INT LSB expression RSB

|   NEW ID LP RP

|   ID INC_OP

|   ID DEC_OP

|	expression MATH_OP expression

|   expression COMP_OP expression

|   INTEGER

|   BOOLEAN

|   ID

|   THIS

|   LP expression RP

;

LOGICAL_OP:'&&' | '||' | NOT;
COMP_OP:'<' | '>' | '<=' | '>=' | '==' | '!=';
INC_OP:'++';
DEC_OP:'--';
MATH_OP:'^' | '*' | '/' | '%' | '+' | '-' ;
NOT:'!';
LCB:'{';
RCB:'}';
LSB:'[';
RSB:']';
DOT:'.';
COMMA:',';
LENGTH:'length';
LP:'(';
RP:')';
RETURN: 'return';
ASSIGN: '=';
NEW:'new';
INT:'int';
THIS:'this';
SC:';';
SOUT:'System.out.println';
WHILE:'while';
FOR:'for';
IF:'if';
ELSE:'else';
BOOLEAN_TYPE:'boolean';
PUBLIC:'public';
CLASS:'class';
STATIC:'static';
VOID:'void';
MAIN:'main';
EXTENDS:'extends';
STRING:'String';
TYPES:'long' | 'short' | 'float' | 'double' | 'char' | 'byte' | 'enum' ;
INSTANCEOF: 'instanceof';
BREAK:'break';

BOOLEAN
:	'true'
|	'false'
;

ID
:	[a-zA-Z$_][a-zA-Z0-9$_]*
;

INTEGER
:	[0-9][0-9]*
;

fragment
Underscores
:	'_'+
;

WS
:   [ \r\t\n]+ -> skip
;   

MULTILINE_COMMENT
:  '/*' .*? '*/' -> skip
;
LINE_COMMENT
:  '//' .*? '\n' -> skip
;
