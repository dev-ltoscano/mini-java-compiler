grammar minijavaGrammar;

PROGRAM
    :    MAIN_DECLARATION {CLASS_DECLARATION}
    ;

MAIN_DECLARATION
    :   CLASS ID LCB PUBLIC STATIC VOID MAIN (STRING LSB RSB ID) LCB CMD RCB RCB
    ;

CLASS_DECLARATION
    :
    CLASS ID LCB EXTENDS ID RCB LCB {VAR_DECLARATION} {METHOD_DECLARATION} RCB
    ;

VAR_DECLARATION
    :   TYPE_DECLARATION ID SC
    ;

METHOD_DECLARATION
    :   PUBLIC TYPE_DECLARATION ID LP LCB PARAMS_DECLARATION RCB RP LCB {VAR_DECLARATION} {CMD} RETURN EXP SC RCB
    ;

PARAMS_DECLARATION
    :   TYPE_DECLARATION ID {, TYPE ID}
    ;

TYPE_DECLARATION
    :   INT LSB RSB
    |   TYPE
    |   INT
    |   ID
    ;
CMD:    LCB {CMD} RCB
    |   IF LP EXP RP CMD
    |   IF LP EXP RP CMD ELSE CMD
    |   WHILE LP EXP RP CMD
    |   SOUT LP EXP RP SC
    |   ID ASSIGN EXP
    |   ID RSB EXP RSB ASSIGN EXP SC
    ;

EXP
    :   EXP LOGICAL_OP EXP
    |   REXP
    ;

REXP
    :   REXP COMP_OP REXP
    |   AEXP
    ;

AEXP
    :   AEXP MATH_OP MEXP
    |   MEXP
    ;

MEXP
    :   MEXP MATH_OP SEXP
    |   SEXP
    ;

SEXP
    :   '!' SEXP
    |   BOOLEAN
    |   INTEGER
    |   NULL
    |   NEW INTEGER LSB EXP RSB
    |   PEXP DOT LENGTH
    |   PEXP LSB EXP RSB
    |   PEXP
    ;

PEXP
    :   ID
    |   THIS
    |   NEW ID LP RP
    |   LP EXP RP
    |   PEXP DOT ID
    |   PEXP DOT ID LP LSB EXP RSB RP
    ;

EXPS
    :   EXP LCB COMMA EXP RCB
    ;


PASS
    : ' '
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
    :   '+'
    |   '-'
    |   '*'
    |   '/'
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
    |   '!'
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
    |   ':'
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

