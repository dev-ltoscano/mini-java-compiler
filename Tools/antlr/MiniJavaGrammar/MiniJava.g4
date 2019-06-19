grammar MiniJava;

/* 
 *  PARSER RULES
 */

prog : mainClass classDecl*;

mainClass : CLASS ID LCB PUBLIC STATIC VOID MAIN LP STRING LSB RSB ID RP LCB methodBody RCB RCB;

classDecl : CLASS ID (EXTENDS ID)? LCB ((varDecl | varDeclAndAtt) | methodDecl)* RCB;

methodDecl : PUBLIC methodType ID LP methodParams? RP LCB methodBody methodReturn? RCB;

methodBody : ((varDecl | varDeclAndAtt) | statement)*;

methodReturn : RETURN expression SC;

methodCall : SUPER DOT ID LP expList? RP | THIS DOT ID LP expList? RP | ID LP expList? RP | ID DOT ID LP expList? RP;

methodParams : varType ID (COMMA varType ID)*;

methodType : VOID
    | INT LSB RSB 
    | INT 
    | BOOLEAN
    | STRING    
    | ID;
    
varType : INT LSB RSB 
    | INT 
    | BOOLEAN
    | STRING
    | ID;

varDecl : varType ID SC;

varDeclAndAtt : varType ID ASSIGN expression SC;

statement : LCB statement* RCB
    | IF LP expression RP statement
    | IF LP expression RP statement ELSE statement
    | WHILE LP expression RP statement
    | SOUT LP expression RP SC 
    | ID ASSIGN expression SC
    | ID LSB expression RSB ASSIGN expression SC
    | methodCall SC;

expression : expression LSB expression RSB
    | expression DOT LENGTH
    | expression DOT methodCall
    | LP expression RP
    | MINUS expression
    | NOT expression
    | NEW INT LSB expression RSB
    | NEW ID LP RP
    | methodCall
    | expression (MULT | DIV) expression
    | expression (SUM | MINUS) expression
    | expression COMP_OP expression
    | expression AND expression
    | expression OR expression
    | SUPER
    | THIS
    | LITINT
    | LITSTRING
    | LITBOOL
    | ID;

expList : expression (COMMA expression)*;

/* 
 *  LEXER RULES
 */

PACKAGE : 'package';
IMPORT : 'import';
CLASS : 'class';
INTERFACE : 'interface';
EXTENDS : 'extends';
IMPLEMENTS : 'implements';
SUPER : 'super';
THIS : 'this';
NULLABLE : 'null';
NEW : 'new';
RETURN : 'return';
INSTANCEOF : 'instanceof';
PUBLIC : 'public';
ACCESS_MODIFIER : ('private' | 'protected');
STATIC : 'static';
MODIFIER : ('final' | 'abstract' | 'const' | 'synchronized' | 'volatile' | 'transient');
ENUM : 'enum';
VOID : 'void';
INT : 'int';
STRING : 'String';
BOOLEAN : 'boolean';
TYPE : ('long' | 'short' | 'float' | 'double' | 'char' | 'byte');
ASSIGN : '=';
SUM : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
MOD : '%';
POW : '^';
COMP_OP : ('<' | '>' | '<=' | '>=' | '==' | '!=');
AND : '&&';
OR : '||';
NOT : '!';
TERNARY_OP : ('?' | ':');
INCREMENT_OP : '++';
DECREMENT_OP : '--';
BITWISE_OP : ('<<' | '>>');
ASSERT : 'assert';
IF : 'if';
ELSE : 'else';
SWITCH : 'switch';
CASE : 'case';
DEFAULT : 'default';
FOR : 'for';
WHILE : 'while';
DO : 'do';
GOTO : 'goto';
CONTINUE : 'continue';
BREAK : 'break';
TRY : 'try';
CATCH : 'catch';
FINALLY : 'finally';
THROWS : 'throws';
THROW : 'throw';
NATIVE : 'native';
STRICTFP : 'strictfp';
MAIN : 'main';
LENGTH : 'length';
SOUT : 'System.out.println';
COMMA : ',';
DOT : '.';
SC : ';';
LP : '(';
RP : ')';
LCB : '{';
RCB : '}';
LSB : '[';
RSB : ']';

LITBOOL : ('true' | 'false');
LITINT : [0-9][0-9]*;
LITSTRING : '"' .*? '"';
ID : [a-zA-Z][a-zA-Z0-9$_]*;

MULTILINE_COMMENT : '/*' .*? '*/' -> skip;
LINE_COMMENT : '//' .*? '\n' -> skip;
WHITESPACE : [ \t\r\n\f]+ -> skip;