/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/
#pragma once

#include "antlr4/antlr4-runtime.h"

class  MiniJavaParser : public antlr4::Parser {
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

  enum {
    RuleProg = 0, RuleMainClass = 1, RuleClassDecl = 2, RuleMethodDecl = 3, 
    RuleMethodBody = 4, RuleMethodReturn = 5, RuleMethodCall = 6, RuleMethodParams = 7, 
    RuleMethodType = 8, RuleVarType = 9, RuleVarDecl = 10, RuleVarDeclAndAtt = 11, 
    RuleStatement = 12, RuleExpression = 13, RuleExpList = 14
  };

  MiniJavaParser(antlr4::TokenStream *input);
  ~MiniJavaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class MainClassContext;
  class ClassDeclContext;
  class MethodDeclContext;
  class MethodBodyContext;
  class MethodReturnContext;
  class MethodCallContext;
  class MethodParamsContext;
  class MethodTypeContext;
  class VarTypeContext;
  class VarDeclContext;
  class VarDeclAndAttContext;
  class StatementContext;
  class ExpressionContext;
  class ExpListContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainClassContext *mainClass();
    std::vector<ClassDeclContext *> classDecl();
    ClassDeclContext* classDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  MainClassContext : public antlr4::ParserRuleContext {
  public:
    MainClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LCB();
    antlr4::tree::TerminalNode* LCB(size_t i);
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *MAIN();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    antlr4::tree::TerminalNode *RP();
    MethodBodyContext *methodBody();
    std::vector<antlr4::tree::TerminalNode *> RCB();
    antlr4::tree::TerminalNode* RCB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainClassContext* mainClass();

  class  ClassDeclContext : public antlr4::ParserRuleContext {
  public:
    ClassDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    antlr4::tree::TerminalNode *EXTENDS();
    std::vector<MethodDeclContext *> methodDecl();
    MethodDeclContext* methodDecl(size_t i);
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);
    std::vector<VarDeclAndAttContext *> varDeclAndAtt();
    VarDeclAndAttContext* varDeclAndAtt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDeclContext* classDecl();

  class  MethodDeclContext : public antlr4::ParserRuleContext {
  public:
    MethodDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUBLIC();
    MethodTypeContext *methodType();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *LCB();
    MethodBodyContext *methodBody();
    antlr4::tree::TerminalNode *RCB();
    MethodParamsContext *methodParams();
    MethodReturnContext *methodReturn();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodDeclContext* methodDecl();

  class  MethodBodyContext : public antlr4::ParserRuleContext {
  public:
    MethodBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);
    std::vector<VarDeclAndAttContext *> varDeclAndAtt();
    VarDeclAndAttContext* varDeclAndAtt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodBodyContext* methodBody();

  class  MethodReturnContext : public antlr4::ParserRuleContext {
  public:
    MethodReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodReturnContext* methodReturn();

  class  MethodCallContext : public antlr4::ParserRuleContext {
  public:
    MethodCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUPER();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpListContext *expList();
    antlr4::tree::TerminalNode *THIS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodCallContext* methodCall();

  class  MethodParamsContext : public antlr4::ParserRuleContext {
  public:
    MethodParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarTypeContext *> varType();
    VarTypeContext* varType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodParamsContext* methodParams();

  class  MethodTypeContext : public antlr4::ParserRuleContext {
  public:
    MethodTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodTypeContext* methodType();

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VarDeclAndAttContext : public antlr4::ParserRuleContext {
  public:
    VarDeclAndAttContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclAndAttContext* varDeclAndAtt();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *SOUT();
    antlr4::tree::TerminalNode *SC();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    MethodCallContext *methodCall();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    antlr4::tree::TerminalNode *ID();
    MethodCallContext *methodCall();
    antlr4::tree::TerminalNode *SUPER();
    antlr4::tree::TerminalNode *THIS();
    antlr4::tree::TerminalNode *LITINT();
    antlr4::tree::TerminalNode *LITSTRING();
    antlr4::tree::TerminalNode *LITBOOL();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *SUM();
    antlr4::tree::TerminalNode *COMP_OP();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LENGTH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ExpListContext : public antlr4::ParserRuleContext {
  public:
    ExpListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpListContext* expList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

