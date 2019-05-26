grammar minijavaGrammar;

program
    :   (ClassDecl)+
    ;

ClassDecl
    :   CLASS <ID> (EXTENDS <ID>)? LCB (VarDecl)* (MethodDecl)* RCB
    ;

VarDecl
    :   Type ID SC
    |   STATIC Type ID SC
    ;

MethodDecl
    :   PUBLIC Type ID LP (Type ID (COMMA Type ID)*)? RP LCB (VarDecl)* (Statement)* RETURN Expression SC RCB
    ;

Type
    :   TYPE LSB RSB
    |   TYPE
    ;

Statement
    :   LCB (Statement)* RCB
    |   IF LP Expression RP Statement ELSE Statement
    |   IF LP Expression RP Statement
    |   WHILE LP Expression RP Statement
    |   SOUT LP Expression RP SC
    |   ID ASSIGN Expression SC
    |   BREAK
    |   CONTINUE
    |   ID LSB Expression RSB ASSIGN Expression SC
    |   SWITCH LP Expression RP LCB (CASE INTEGER DDOT (Statement)+)* DEFAULT DDOT (Statement)+ RCB
    ;

Expression
    :	Lexp Exp
    ;

Exp
	:	OPERATORS Expression
	|	LSB Expression RSB
	|	DOT LENGTH
	|	DOT ID LP (Expression (COMMA Expression)*)? RP
	;

Lexp
    :   INTEGER
    |   STRING
    |   NULL
    |   BOOLEAN
    |   ID
    |   THIS
    |   NEW Type LSB Expression RSB
    |   NEW ID LP RP
    |   NOT Expression
    |   LP Expression RP
    ;  

PACKAGE
    :   'package'
    ;

IMPORT
    :   'import'
    ;

CLASS
    :   'class'
    ;

INTERFACE
    :   'interface'
    ;

EXTENDS
    :   'extends'
    ;

IMPLEMENTS
    :   'implements'
    ;

THIS
    :   'this'
    ;

SUPER
    :   'super'
    ;

NEW
    :   'new'
    ;

NULL
    :   'null'
    ;

RETURN
    :   'return'
    ;

ACCESS_MODIFIER
    :   PUBLIC
    |   'private'
    |   'protected'
    |   STATIC
    |   'final'
    |   'abstract'
    |   'const'
    |   'synchronized'
    |   'volatile'
    |   'transient'
    ;

TYPE
    :   INT
    |   'long'
    |   'short'
    |   'float'
    |   'double'
    |   'char'
    |   'String'
    |   'boolean'
    |   'byte'
    |   'enum'
    |   'void '
    |   ID
    ;

INSTANCEOF
    :   'instanceof'
    ;

ASSIGN
    :   '='
    ;

MATH_OP
    :   ADD_OP
    |   MULT_OP
    |   '%'
    |   '^'
    ;

COMP_OP
    :   '< '
    |   '>'
    |   '<='
    |   '>='
    |   '=='
    |   '!='
    ;

LOGICAL_OP
    :   '&&'
    |   '||'
    |   NOT
    ;

INC_OP
    :   '++'
    ;

DEC_OP
    :   '--'
    ;

BITWISE_OP
    :   '<<'
    |   '>>'
    ;

COND_OP
    :   '?'
    |   DDOT
    ;

IF
    :   'if'
    ;

ELSE
    :   'else'
    ;

SWITCH
    :   'switch'
    ;

CASE
    :   'case'
    ;

DEFAULT
    :   'default'
    ;

ASSERT
    :   'assert'
    ;

FOR
    :   'for'
    ;

WHILE
    :   'while'
    ;

DO
    :   'do'
    ;

GOTO
    :   'goto'
    ;

CONTINUE
    :   'continue'
    ;

BREAK
    :   'break'
    ;

TRY
    :   'try'
    ;

CATCH
    :   'catch'
    ;

FINALLY
    :   'finally'
    ;

THROWS
    :   'throws'
    ;

THROW
    :   'throw'
    ;

NATIVE
    :   'native'
    ;

STRICTFP
    :   'strictfp'
    ;

COMMA
    :   ','
    ;

DOT
    :   '.'
    ;

DDOT
    :   ':'
    ;

SC
    :   ';'
    ;

LCB
    :   '{'
    ;

RCB
    :   '}'
    ;

LP
    :   '('
    ;
RP
    :   ')'
    ;

LSB
    :   '['
    ;

RSB
    :   ']'
    ;

MAIN
    :   'main'
    ;

SOUT
    :   'System.out.println'
    ;

LENGTH
    :   'length'
    ;

BOOLEAN
    :   'true'
    |   'false'
    ;

ID
    :   [a-zA-Z0-9$_]+
    ;

INTEGER
    :   [0-9]+
    ;

PUBLIC
    :   'public'
    ;

STATIC
    :   'static'
    ;

VOID
    :   'void'
    ;

STRING
    :   'string'
    ;

OPERATORS
    :   MATH_OP
    |   COMP_OP
    |   LOGICAL_OP
    |   INC_OP
    |   DEC_OP
    |   BITWISE_OP
    |   COND_OP
    ;

INT
    :   'int'
    ;

NOT
    :   '!'
    ;

ADD_OP
    :   '+'
    |   '-'
    ;

MULT_OP
    :   '*'
    |   '/'
    ;