#pragma once

#include "antlr4-runtime.h"

class  MiniJavaLexer : public antlr4::Lexer {
public:
  enum {
    PACKAGE = 1, IMPORT = 2, CLASS = 3, INTERFACE = 4, EXTENDS = 5, IMPLEMENTS = 6, 
    SUPER = 7, THIS = 8, NULLABLE = 9, NEW = 10, RETURN = 11, INSTANCEOF = 12, 
    PUBLIC = 13, ACCESS_MODIFIER = 14, STATIC = 15, MODIFIER = 16, ENUM = 17, 
    VOID = 18, INT = 19, STRING = 20, BOOLEAN = 21, TYPE = 22, ASSIGN = 23, 
    SUM = 24, MINUS = 25, MULT = 26, DIV = 27, MOD = 28, POW = 29, COMP_OP = 30, 
    AND = 31, OR = 32, NOT = 33, TERNARY_OP = 34, INCREMENT_OP = 35, DECREMENT_OP = 36, 
    BITWISE_OP = 37, ASSERT = 38, IF = 39, ELSE = 40, SWITCH = 41, CASE = 42, 
    DEFAULT = 43, FOR = 44, WHILE = 45, DO = 46, GOTO = 47, CONTINUE = 48, 
    BREAK = 49, TRY = 50, CATCH = 51, FINALLY = 52, THROWS = 53, THROW = 54, 
    NATIVE = 55, STRICTFP = 56, MAIN = 57, LENGTH = 58, SOUT = 59, COMMA = 60, 
    DOT = 61, SC = 62, LP = 63, RP = 64, LCB = 65, RCB = 66, LSB = 67, RSB = 68, 
    LITBOOL = 69, LITINT = 70, LITSTRING = 71, ID = 72, MULTILINE_COMMENT = 73, 
    LINE_COMMENT = 74, WHITESPACE = 75
  };

  MiniJavaLexer(antlr4::CharStream *input);
  ~MiniJavaLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

