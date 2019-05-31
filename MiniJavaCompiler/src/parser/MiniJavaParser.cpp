#include "listener/MiniJavaListener.h"
#include "visitor/MiniJavaVisitor.h"

#include "MiniJavaParser.h"

using namespace antlrcpp;
using namespace antlr4;

MiniJavaParser::MiniJavaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MiniJavaParser::~MiniJavaParser() {
  delete _interpreter;
}

std::string MiniJavaParser::getGrammarFileName() const {
  return "MiniJava.g4";
}

const std::vector<std::string>& MiniJavaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MiniJavaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniJavaParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniJavaParser::MainClassContext* MiniJavaParser::ProgContext::mainClass() {
  return getRuleContext<MiniJavaParser::MainClassContext>(0);
}

std::vector<MiniJavaParser::ClassDeclContext *> MiniJavaParser::ProgContext::classDecl() {
  return getRuleContexts<MiniJavaParser::ClassDeclContext>();
}

MiniJavaParser::ClassDeclContext* MiniJavaParser::ProgContext::classDecl(size_t i) {
  return getRuleContext<MiniJavaParser::ClassDeclContext>(i);
}


size_t MiniJavaParser::ProgContext::getRuleIndex() const {
  return MiniJavaParser::RuleProg;
}

void MiniJavaParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MiniJavaParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any MiniJavaParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::ProgContext* MiniJavaParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniJavaParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    mainClass();
    setState(32);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::CLASS) {
      setState(29);
      classDecl();
      setState(34);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainClassContext ------------------------------------------------------------------

MiniJavaParser::MainClassContext::MainClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::MainClassContext::CLASS() {
  return getToken(MiniJavaParser::CLASS, 0);
}

std::vector<tree::TerminalNode *> MiniJavaParser::MainClassContext::ID() {
  return getTokens(MiniJavaParser::ID);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::ID(size_t i) {
  return getToken(MiniJavaParser::ID, i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::MainClassContext::LCB() {
  return getTokens(MiniJavaParser::LCB);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::LCB(size_t i) {
  return getToken(MiniJavaParser::LCB, i);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::PUBLIC() {
  return getToken(MiniJavaParser::PUBLIC, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::STATIC() {
  return getToken(MiniJavaParser::STATIC, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::VOID() {
  return getToken(MiniJavaParser::VOID, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::MAIN() {
  return getToken(MiniJavaParser::MAIN, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::LP() {
  return getToken(MiniJavaParser::LP, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::STRING() {
  return getToken(MiniJavaParser::STRING, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::RP() {
  return getToken(MiniJavaParser::RP, 0);
}

MiniJavaParser::MethodBodyContext* MiniJavaParser::MainClassContext::methodBody() {
  return getRuleContext<MiniJavaParser::MethodBodyContext>(0);
}

std::vector<tree::TerminalNode *> MiniJavaParser::MainClassContext::RCB() {
  return getTokens(MiniJavaParser::RCB);
}

tree::TerminalNode* MiniJavaParser::MainClassContext::RCB(size_t i) {
  return getToken(MiniJavaParser::RCB, i);
}


size_t MiniJavaParser::MainClassContext::getRuleIndex() const {
  return MiniJavaParser::RuleMainClass;
}

void MiniJavaParser::MainClassContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainClass(this);
}

void MiniJavaParser::MainClassContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainClass(this);
}


antlrcpp::Any MiniJavaParser::MainClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMainClass(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MainClassContext* MiniJavaParser::mainClass() {
  MainClassContext *_localctx = _tracker.createInstance<MainClassContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniJavaParser::RuleMainClass);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(MiniJavaParser::CLASS);
    setState(36);
    match(MiniJavaParser::ID);
    setState(37);
    match(MiniJavaParser::LCB);
    setState(38);
    match(MiniJavaParser::PUBLIC);
    setState(39);
    match(MiniJavaParser::STATIC);
    setState(40);
    match(MiniJavaParser::VOID);
    setState(41);
    match(MiniJavaParser::MAIN);
    setState(42);
    match(MiniJavaParser::LP);
    setState(43);
    match(MiniJavaParser::STRING);
    setState(44);
    match(MiniJavaParser::LSB);
    setState(45);
    match(MiniJavaParser::RSB);
    setState(46);
    match(MiniJavaParser::ID);
    setState(47);
    match(MiniJavaParser::RP);
    setState(48);
    match(MiniJavaParser::LCB);
    setState(49);
    methodBody();
    setState(50);
    match(MiniJavaParser::RCB);
    setState(51);
    match(MiniJavaParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclContext ------------------------------------------------------------------

MiniJavaParser::ClassDeclContext::ClassDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::ClassDeclContext::CLASS() {
  return getToken(MiniJavaParser::CLASS, 0);
}

std::vector<tree::TerminalNode *> MiniJavaParser::ClassDeclContext::ID() {
  return getTokens(MiniJavaParser::ID);
}

tree::TerminalNode* MiniJavaParser::ClassDeclContext::ID(size_t i) {
  return getToken(MiniJavaParser::ID, i);
}

tree::TerminalNode* MiniJavaParser::ClassDeclContext::LCB() {
  return getToken(MiniJavaParser::LCB, 0);
}

tree::TerminalNode* MiniJavaParser::ClassDeclContext::RCB() {
  return getToken(MiniJavaParser::RCB, 0);
}

tree::TerminalNode* MiniJavaParser::ClassDeclContext::EXTENDS() {
  return getToken(MiniJavaParser::EXTENDS, 0);
}

std::vector<MiniJavaParser::VarDeclContext *> MiniJavaParser::ClassDeclContext::varDecl() {
  return getRuleContexts<MiniJavaParser::VarDeclContext>();
}

MiniJavaParser::VarDeclContext* MiniJavaParser::ClassDeclContext::varDecl(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclContext>(i);
}

std::vector<MiniJavaParser::MethodDeclContext *> MiniJavaParser::ClassDeclContext::methodDecl() {
  return getRuleContexts<MiniJavaParser::MethodDeclContext>();
}

MiniJavaParser::MethodDeclContext* MiniJavaParser::ClassDeclContext::methodDecl(size_t i) {
  return getRuleContext<MiniJavaParser::MethodDeclContext>(i);
}


size_t MiniJavaParser::ClassDeclContext::getRuleIndex() const {
  return MiniJavaParser::RuleClassDecl;
}

void MiniJavaParser::ClassDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDecl(this);
}

void MiniJavaParser::ClassDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDecl(this);
}


antlrcpp::Any MiniJavaParser::ClassDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitClassDecl(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::ClassDeclContext* MiniJavaParser::classDecl() {
  ClassDeclContext *_localctx = _tracker.createInstance<ClassDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniJavaParser::RuleClassDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(MiniJavaParser::CLASS);
    setState(54);
    match(MiniJavaParser::ID);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MiniJavaParser::EXTENDS) {
      setState(55);
      match(MiniJavaParser::EXTENDS);
      setState(56);
      match(MiniJavaParser::ID);
    }
    setState(59);
    match(MiniJavaParser::LCB);
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (MiniJavaParser::VOID - 18))
      | (1ULL << (MiniJavaParser::INT - 18))
      | (1ULL << (MiniJavaParser::BOOLEAN - 18))
      | (1ULL << (MiniJavaParser::ID - 18)))) != 0)) {
      setState(60);
      varDecl();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::PUBLIC) {
      setState(66);
      methodDecl();
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(MiniJavaParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclContext ------------------------------------------------------------------

MiniJavaParser::MethodDeclContext::MethodDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::PUBLIC() {
  return getToken(MiniJavaParser::PUBLIC, 0);
}

MiniJavaParser::TypeContext* MiniJavaParser::MethodDeclContext::type() {
  return getRuleContext<MiniJavaParser::TypeContext>(0);
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::LP() {
  return getToken(MiniJavaParser::LP, 0);
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::RP() {
  return getToken(MiniJavaParser::RP, 0);
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::LCB() {
  return getToken(MiniJavaParser::LCB, 0);
}

MiniJavaParser::MethodBodyContext* MiniJavaParser::MethodDeclContext::methodBody() {
  return getRuleContext<MiniJavaParser::MethodBodyContext>(0);
}

tree::TerminalNode* MiniJavaParser::MethodDeclContext::RCB() {
  return getToken(MiniJavaParser::RCB, 0);
}

MiniJavaParser::ParamsContext* MiniJavaParser::MethodDeclContext::params() {
  return getRuleContext<MiniJavaParser::ParamsContext>(0);
}

MiniJavaParser::MethodReturnContext* MiniJavaParser::MethodDeclContext::methodReturn() {
  return getRuleContext<MiniJavaParser::MethodReturnContext>(0);
}


size_t MiniJavaParser::MethodDeclContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodDecl;
}

void MiniJavaParser::MethodDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDecl(this);
}

void MiniJavaParser::MethodDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDecl(this);
}


antlrcpp::Any MiniJavaParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodDeclContext* MiniJavaParser::methodDecl() {
  MethodDeclContext *_localctx = _tracker.createInstance<MethodDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniJavaParser::RuleMethodDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(MiniJavaParser::PUBLIC);
    setState(75);
    type();
    setState(76);
    match(MiniJavaParser::ID);
    setState(77);
    match(MiniJavaParser::LP);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (MiniJavaParser::VOID - 18))
      | (1ULL << (MiniJavaParser::INT - 18))
      | (1ULL << (MiniJavaParser::BOOLEAN - 18))
      | (1ULL << (MiniJavaParser::ID - 18)))) != 0)) {
      setState(78);
      params();
    }
    setState(81);
    match(MiniJavaParser::RP);
    setState(82);
    match(MiniJavaParser::LCB);
    setState(83);
    methodBody();
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MiniJavaParser::RETURN) {
      setState(84);
      methodReturn();
    }
    setState(87);
    match(MiniJavaParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodBodyContext ------------------------------------------------------------------

MiniJavaParser::MethodBodyContext::MethodBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniJavaParser::VarDeclContext *> MiniJavaParser::MethodBodyContext::varDecl() {
  return getRuleContexts<MiniJavaParser::VarDeclContext>();
}

MiniJavaParser::VarDeclContext* MiniJavaParser::MethodBodyContext::varDecl(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclContext>(i);
}

std::vector<MiniJavaParser::StatementContext *> MiniJavaParser::MethodBodyContext::statement() {
  return getRuleContexts<MiniJavaParser::StatementContext>();
}

MiniJavaParser::StatementContext* MiniJavaParser::MethodBodyContext::statement(size_t i) {
  return getRuleContext<MiniJavaParser::StatementContext>(i);
}


size_t MiniJavaParser::MethodBodyContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodBody;
}

void MiniJavaParser::MethodBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodBody(this);
}

void MiniJavaParser::MethodBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodBody(this);
}


antlrcpp::Any MiniJavaParser::MethodBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodBody(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodBodyContext* MiniJavaParser::methodBody() {
  MethodBodyContext *_localctx = _tracker.createInstance<MethodBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniJavaParser::RuleMethodBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(89);
        varDecl(); 
      }
      setState(94);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
      | (1ULL << MiniJavaParser::THIS)
      | (1ULL << MiniJavaParser::IF)
      | (1ULL << MiniJavaParser::WHILE)
      | (1ULL << MiniJavaParser::SOUT))) != 0) || _la == MiniJavaParser::LCB

    || _la == MiniJavaParser::ID) {
      setState(95);
      statement();
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodReturnContext ------------------------------------------------------------------

MiniJavaParser::MethodReturnContext::MethodReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::MethodReturnContext::RETURN() {
  return getToken(MiniJavaParser::RETURN, 0);
}

MiniJavaParser::ExpressionContext* MiniJavaParser::MethodReturnContext::expression() {
  return getRuleContext<MiniJavaParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniJavaParser::MethodReturnContext::SC() {
  return getToken(MiniJavaParser::SC, 0);
}


size_t MiniJavaParser::MethodReturnContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodReturn;
}

void MiniJavaParser::MethodReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodReturn(this);
}

void MiniJavaParser::MethodReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodReturn(this);
}


antlrcpp::Any MiniJavaParser::MethodReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodReturn(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodReturnContext* MiniJavaParser::methodReturn() {
  MethodReturnContext *_localctx = _tracker.createInstance<MethodReturnContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniJavaParser::RuleMethodReturn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(MiniJavaParser::RETURN);
    setState(102);
    expression(0);
    setState(103);
    match(MiniJavaParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

MiniJavaParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::SUPER() {
  return getToken(MiniJavaParser::SUPER, 0);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::DOT() {
  return getToken(MiniJavaParser::DOT, 0);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::LP() {
  return getToken(MiniJavaParser::LP, 0);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::RP() {
  return getToken(MiniJavaParser::RP, 0);
}

MiniJavaParser::ExpListContext* MiniJavaParser::MethodCallContext::expList() {
  return getRuleContext<MiniJavaParser::ExpListContext>(0);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::THIS() {
  return getToken(MiniJavaParser::THIS, 0);
}


size_t MiniJavaParser::MethodCallContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodCall;
}

void MiniJavaParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void MiniJavaParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}


antlrcpp::Any MiniJavaParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodCallContext* MiniJavaParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniJavaParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniJavaParser::SUPER: {
        enterOuterAlt(_localctx, 1);
        setState(105);
        match(MiniJavaParser::SUPER);
        setState(106);
        match(MiniJavaParser::DOT);
        setState(107);
        match(MiniJavaParser::ID);
        setState(108);
        match(MiniJavaParser::LP);
        setState(110);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
          | (1ULL << MiniJavaParser::THIS)
          | (1ULL << MiniJavaParser::NEW)
          | (1ULL << MiniJavaParser::MINUS)
          | (1ULL << MiniJavaParser::NOT)
          | (1ULL << MiniJavaParser::LP))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 69)) & ((1ULL << (MiniJavaParser::LITBOOL - 69))
          | (1ULL << (MiniJavaParser::LITINT - 69))
          | (1ULL << (MiniJavaParser::LITSTRING - 69))
          | (1ULL << (MiniJavaParser::ID - 69)))) != 0)) {
          setState(109);
          expList();
        }
        setState(112);
        match(MiniJavaParser::RP);
        break;
      }

      case MiniJavaParser::THIS: {
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(MiniJavaParser::THIS);
        setState(114);
        match(MiniJavaParser::DOT);
        setState(115);
        match(MiniJavaParser::ID);
        setState(116);
        match(MiniJavaParser::LP);
        setState(118);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
          | (1ULL << MiniJavaParser::THIS)
          | (1ULL << MiniJavaParser::NEW)
          | (1ULL << MiniJavaParser::MINUS)
          | (1ULL << MiniJavaParser::NOT)
          | (1ULL << MiniJavaParser::LP))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 69)) & ((1ULL << (MiniJavaParser::LITBOOL - 69))
          | (1ULL << (MiniJavaParser::LITINT - 69))
          | (1ULL << (MiniJavaParser::LITSTRING - 69))
          | (1ULL << (MiniJavaParser::ID - 69)))) != 0)) {
          setState(117);
          expList();
        }
        setState(120);
        match(MiniJavaParser::RP);
        break;
      }

      case MiniJavaParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(121);
        match(MiniJavaParser::ID);
        setState(122);
        match(MiniJavaParser::LP);
        setState(124);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
          | (1ULL << MiniJavaParser::THIS)
          | (1ULL << MiniJavaParser::NEW)
          | (1ULL << MiniJavaParser::MINUS)
          | (1ULL << MiniJavaParser::NOT)
          | (1ULL << MiniJavaParser::LP))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 69)) & ((1ULL << (MiniJavaParser::LITBOOL - 69))
          | (1ULL << (MiniJavaParser::LITINT - 69))
          | (1ULL << (MiniJavaParser::LITSTRING - 69))
          | (1ULL << (MiniJavaParser::ID - 69)))) != 0)) {
          setState(123);
          expList();
        }
        setState(126);
        match(MiniJavaParser::RP);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

MiniJavaParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniJavaParser::TypeContext *> MiniJavaParser::ParamsContext::type() {
  return getRuleContexts<MiniJavaParser::TypeContext>();
}

MiniJavaParser::TypeContext* MiniJavaParser::ParamsContext::type(size_t i) {
  return getRuleContext<MiniJavaParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::ParamsContext::ID() {
  return getTokens(MiniJavaParser::ID);
}

tree::TerminalNode* MiniJavaParser::ParamsContext::ID(size_t i) {
  return getToken(MiniJavaParser::ID, i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::ParamsContext::COMMA() {
  return getTokens(MiniJavaParser::COMMA);
}

tree::TerminalNode* MiniJavaParser::ParamsContext::COMMA(size_t i) {
  return getToken(MiniJavaParser::COMMA, i);
}


size_t MiniJavaParser::ParamsContext::getRuleIndex() const {
  return MiniJavaParser::RuleParams;
}

void MiniJavaParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void MiniJavaParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


antlrcpp::Any MiniJavaParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::ParamsContext* MiniJavaParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniJavaParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    type();
    setState(130);
    match(MiniJavaParser::ID);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::COMMA) {
      setState(131);
      match(MiniJavaParser::COMMA);
      setState(132);
      type();
      setState(133);
      match(MiniJavaParser::ID);
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MiniJavaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::TypeContext::VOID() {
  return getToken(MiniJavaParser::VOID, 0);
}

tree::TerminalNode* MiniJavaParser::TypeContext::INT() {
  return getToken(MiniJavaParser::INT, 0);
}

tree::TerminalNode* MiniJavaParser::TypeContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::TypeContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

tree::TerminalNode* MiniJavaParser::TypeContext::BOOLEAN() {
  return getToken(MiniJavaParser::BOOLEAN, 0);
}

tree::TerminalNode* MiniJavaParser::TypeContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}


size_t MiniJavaParser::TypeContext::getRuleIndex() const {
  return MiniJavaParser::RuleType;
}

void MiniJavaParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void MiniJavaParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any MiniJavaParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::TypeContext* MiniJavaParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniJavaParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      match(MiniJavaParser::VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      match(MiniJavaParser::INT);
      setState(142);
      match(MiniJavaParser::LSB);
      setState(143);
      match(MiniJavaParser::RSB);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(144);
      match(MiniJavaParser::INT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(145);
      match(MiniJavaParser::BOOLEAN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(146);
      match(MiniJavaParser::ID);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

MiniJavaParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniJavaParser::TypeContext* MiniJavaParser::VarDeclContext::type() {
  return getRuleContext<MiniJavaParser::TypeContext>(0);
}

tree::TerminalNode* MiniJavaParser::VarDeclContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::VarDeclContext::SC() {
  return getToken(MiniJavaParser::SC, 0);
}

MiniJavaParser::VarDeclAndAttContext* MiniJavaParser::VarDeclContext::varDeclAndAtt() {
  return getRuleContext<MiniJavaParser::VarDeclAndAttContext>(0);
}


size_t MiniJavaParser::VarDeclContext::getRuleIndex() const {
  return MiniJavaParser::RuleVarDecl;
}

void MiniJavaParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void MiniJavaParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


antlrcpp::Any MiniJavaParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::VarDeclContext* MiniJavaParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniJavaParser::RuleVarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(149);
      type();
      setState(150);
      match(MiniJavaParser::ID);
      setState(151);
      match(MiniJavaParser::SC);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(153);
      varDeclAndAtt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclAndAttContext ------------------------------------------------------------------

MiniJavaParser::VarDeclAndAttContext::VarDeclAndAttContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniJavaParser::TypeContext* MiniJavaParser::VarDeclAndAttContext::type() {
  return getRuleContext<MiniJavaParser::TypeContext>(0);
}

tree::TerminalNode* MiniJavaParser::VarDeclAndAttContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::VarDeclAndAttContext::ASSIGN() {
  return getToken(MiniJavaParser::ASSIGN, 0);
}

MiniJavaParser::ExpressionContext* MiniJavaParser::VarDeclAndAttContext::expression() {
  return getRuleContext<MiniJavaParser::ExpressionContext>(0);
}

tree::TerminalNode* MiniJavaParser::VarDeclAndAttContext::SC() {
  return getToken(MiniJavaParser::SC, 0);
}

MiniJavaParser::MethodCallContext* MiniJavaParser::VarDeclAndAttContext::methodCall() {
  return getRuleContext<MiniJavaParser::MethodCallContext>(0);
}


size_t MiniJavaParser::VarDeclAndAttContext::getRuleIndex() const {
  return MiniJavaParser::RuleVarDeclAndAtt;
}

void MiniJavaParser::VarDeclAndAttContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclAndAtt(this);
}

void MiniJavaParser::VarDeclAndAttContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclAndAtt(this);
}


antlrcpp::Any MiniJavaParser::VarDeclAndAttContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitVarDeclAndAtt(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::VarDeclAndAttContext* MiniJavaParser::varDeclAndAtt() {
  VarDeclAndAttContext *_localctx = _tracker.createInstance<VarDeclAndAttContext>(_ctx, getState());
  enterRule(_localctx, 20, MiniJavaParser::RuleVarDeclAndAtt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      type();
      setState(157);
      match(MiniJavaParser::ID);
      setState(158);
      match(MiniJavaParser::ASSIGN);
      setState(159);
      expression(0);
      setState(160);
      match(MiniJavaParser::SC);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      type();
      setState(163);
      match(MiniJavaParser::ID);
      setState(164);
      match(MiniJavaParser::ASSIGN);
      setState(165);
      methodCall();
      setState(166);
      match(MiniJavaParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MiniJavaParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::StatementContext::LCB() {
  return getToken(MiniJavaParser::LCB, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::RCB() {
  return getToken(MiniJavaParser::RCB, 0);
}

std::vector<MiniJavaParser::StatementContext *> MiniJavaParser::StatementContext::statement() {
  return getRuleContexts<MiniJavaParser::StatementContext>();
}

MiniJavaParser::StatementContext* MiniJavaParser::StatementContext::statement(size_t i) {
  return getRuleContext<MiniJavaParser::StatementContext>(i);
}

tree::TerminalNode* MiniJavaParser::StatementContext::IF() {
  return getToken(MiniJavaParser::IF, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::LP() {
  return getToken(MiniJavaParser::LP, 0);
}

std::vector<MiniJavaParser::ExpressionContext *> MiniJavaParser::StatementContext::expression() {
  return getRuleContexts<MiniJavaParser::ExpressionContext>();
}

MiniJavaParser::ExpressionContext* MiniJavaParser::StatementContext::expression(size_t i) {
  return getRuleContext<MiniJavaParser::ExpressionContext>(i);
}

tree::TerminalNode* MiniJavaParser::StatementContext::RP() {
  return getToken(MiniJavaParser::RP, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::ELSE() {
  return getToken(MiniJavaParser::ELSE, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::WHILE() {
  return getToken(MiniJavaParser::WHILE, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::SOUT() {
  return getToken(MiniJavaParser::SOUT, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::SC() {
  return getToken(MiniJavaParser::SC, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::ASSIGN() {
  return getToken(MiniJavaParser::ASSIGN, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::StatementContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

MiniJavaParser::MethodCallContext* MiniJavaParser::StatementContext::methodCall() {
  return getRuleContext<MiniJavaParser::MethodCallContext>(0);
}


size_t MiniJavaParser::StatementContext::getRuleIndex() const {
  return MiniJavaParser::RuleStatement;
}

void MiniJavaParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MiniJavaParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any MiniJavaParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::StatementContext* MiniJavaParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, MiniJavaParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(170);
      match(MiniJavaParser::LCB);
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
        | (1ULL << MiniJavaParser::THIS)
        | (1ULL << MiniJavaParser::IF)
        | (1ULL << MiniJavaParser::WHILE)
        | (1ULL << MiniJavaParser::SOUT))) != 0) || _la == MiniJavaParser::LCB

      || _la == MiniJavaParser::ID) {
        setState(171);
        statement();
        setState(176);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(177);
      match(MiniJavaParser::RCB);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      match(MiniJavaParser::IF);
      setState(179);
      match(MiniJavaParser::LP);
      setState(180);
      expression(0);
      setState(181);
      match(MiniJavaParser::RP);
      setState(182);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(184);
      match(MiniJavaParser::IF);
      setState(185);
      match(MiniJavaParser::LP);
      setState(186);
      expression(0);
      setState(187);
      match(MiniJavaParser::RP);
      setState(188);
      statement();
      setState(189);
      match(MiniJavaParser::ELSE);
      setState(190);
      statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(192);
      match(MiniJavaParser::WHILE);
      setState(193);
      match(MiniJavaParser::LP);
      setState(194);
      expression(0);
      setState(195);
      match(MiniJavaParser::RP);
      setState(196);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(198);
      match(MiniJavaParser::SOUT);
      setState(199);
      match(MiniJavaParser::LP);
      setState(200);
      expression(0);
      setState(201);
      match(MiniJavaParser::RP);
      setState(202);
      match(MiniJavaParser::SC);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(204);
      match(MiniJavaParser::ID);
      setState(205);
      match(MiniJavaParser::ASSIGN);
      setState(206);
      expression(0);
      setState(207);
      match(MiniJavaParser::SC);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(209);
      match(MiniJavaParser::ID);
      setState(210);
      match(MiniJavaParser::LSB);
      setState(211);
      expression(0);
      setState(212);
      match(MiniJavaParser::RSB);
      setState(213);
      match(MiniJavaParser::ASSIGN);
      setState(214);
      expression(0);
      setState(215);
      match(MiniJavaParser::SC);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(217);
      methodCall();
      setState(218);
      match(MiniJavaParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MiniJavaParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LP() {
  return getToken(MiniJavaParser::LP, 0);
}

std::vector<MiniJavaParser::ExpressionContext *> MiniJavaParser::ExpressionContext::expression() {
  return getRuleContexts<MiniJavaParser::ExpressionContext>();
}

MiniJavaParser::ExpressionContext* MiniJavaParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<MiniJavaParser::ExpressionContext>(i);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::RP() {
  return getToken(MiniJavaParser::RP, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::MINUS() {
  return getToken(MiniJavaParser::MINUS, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::NOT() {
  return getToken(MiniJavaParser::NOT, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::NEW() {
  return getToken(MiniJavaParser::NEW, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::INT() {
  return getToken(MiniJavaParser::INT, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

MiniJavaParser::MethodCallContext* MiniJavaParser::ExpressionContext::methodCall() {
  return getRuleContext<MiniJavaParser::MethodCallContext>(0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::SUPER() {
  return getToken(MiniJavaParser::SUPER, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::THIS() {
  return getToken(MiniJavaParser::THIS, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LITINT() {
  return getToken(MiniJavaParser::LITINT, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LITSTRING() {
  return getToken(MiniJavaParser::LITSTRING, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LITBOOL() {
  return getToken(MiniJavaParser::LITBOOL, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::MULT() {
  return getToken(MiniJavaParser::MULT, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::DIV() {
  return getToken(MiniJavaParser::DIV, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::SUM() {
  return getToken(MiniJavaParser::SUM, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::COMP_OP() {
  return getToken(MiniJavaParser::COMP_OP, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::AND() {
  return getToken(MiniJavaParser::AND, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::OR() {
  return getToken(MiniJavaParser::OR, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::DOT() {
  return getToken(MiniJavaParser::DOT, 0);
}

tree::TerminalNode* MiniJavaParser::ExpressionContext::LENGTH() {
  return getToken(MiniJavaParser::LENGTH, 0);
}


size_t MiniJavaParser::ExpressionContext::getRuleIndex() const {
  return MiniJavaParser::RuleExpression;
}

void MiniJavaParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void MiniJavaParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any MiniJavaParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


MiniJavaParser::ExpressionContext* MiniJavaParser::expression() {
   return expression(0);
}

MiniJavaParser::ExpressionContext* MiniJavaParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniJavaParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MiniJavaParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MiniJavaParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(223);
      match(MiniJavaParser::LP);
      setState(224);
      expression(0);
      setState(225);
      match(MiniJavaParser::RP);
      break;
    }

    case 2: {
      setState(227);
      match(MiniJavaParser::MINUS);
      setState(228);
      expression(16);
      break;
    }

    case 3: {
      setState(229);
      match(MiniJavaParser::NOT);
      setState(230);
      expression(15);
      break;
    }

    case 4: {
      setState(231);
      match(MiniJavaParser::NEW);
      setState(232);
      match(MiniJavaParser::INT);
      setState(233);
      match(MiniJavaParser::LSB);
      setState(234);
      expression(0);
      setState(235);
      match(MiniJavaParser::RSB);
      break;
    }

    case 5: {
      setState(237);
      match(MiniJavaParser::NEW);
      setState(238);
      match(MiniJavaParser::ID);
      setState(239);
      match(MiniJavaParser::LP);
      setState(240);
      match(MiniJavaParser::RP);
      break;
    }

    case 6: {
      setState(241);
      methodCall();
      break;
    }

    case 7: {
      setState(242);
      match(MiniJavaParser::SUPER);
      break;
    }

    case 8: {
      setState(243);
      match(MiniJavaParser::THIS);
      break;
    }

    case 9: {
      setState(244);
      match(MiniJavaParser::LITINT);
      break;
    }

    case 10: {
      setState(245);
      match(MiniJavaParser::LITSTRING);
      break;
    }

    case 11: {
      setState(246);
      match(MiniJavaParser::LITBOOL);
      break;
    }

    case 12: {
      setState(247);
      match(MiniJavaParser::ID);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(276);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(250);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(251);
          _la = _input->LA(1);
          if (!(_la == MiniJavaParser::MULT

          || _la == MiniJavaParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(252);
          expression(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(254);
          _la = _input->LA(1);
          if (!(_la == MiniJavaParser::SUM

          || _la == MiniJavaParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(255);
          expression(11);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(257);
          match(MiniJavaParser::COMP_OP);
          setState(258);
          expression(10);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(259);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(260);
          match(MiniJavaParser::AND);
          setState(261);
          expression(9);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(262);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(263);
          match(MiniJavaParser::OR);
          setState(264);
          expression(8);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(266);
          match(MiniJavaParser::LSB);
          setState(267);
          expression(0);
          setState(268);
          match(MiniJavaParser::RSB);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(271);
          match(MiniJavaParser::DOT);
          setState(272);
          match(MiniJavaParser::LENGTH);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(273);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(274);
          match(MiniJavaParser::DOT);
          setState(275);
          methodCall();
          break;
        }

        } 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpListContext ------------------------------------------------------------------

MiniJavaParser::ExpListContext::ExpListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniJavaParser::ExpressionContext *> MiniJavaParser::ExpListContext::expression() {
  return getRuleContexts<MiniJavaParser::ExpressionContext>();
}

MiniJavaParser::ExpressionContext* MiniJavaParser::ExpListContext::expression(size_t i) {
  return getRuleContext<MiniJavaParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::ExpListContext::COMMA() {
  return getTokens(MiniJavaParser::COMMA);
}

tree::TerminalNode* MiniJavaParser::ExpListContext::COMMA(size_t i) {
  return getToken(MiniJavaParser::COMMA, i);
}


size_t MiniJavaParser::ExpListContext::getRuleIndex() const {
  return MiniJavaParser::RuleExpList;
}

void MiniJavaParser::ExpListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpList(this);
}

void MiniJavaParser::ExpListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpList(this);
}


antlrcpp::Any MiniJavaParser::ExpListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitExpList(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::ExpListContext* MiniJavaParser::expList() {
  ExpListContext *_localctx = _tracker.createInstance<ExpListContext>(_ctx, getState());
  enterRule(_localctx, 26, MiniJavaParser::RuleExpList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    expression(0);
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::COMMA) {
      setState(282);
      match(MiniJavaParser::COMMA);
      setState(283);
      expression(0);
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniJavaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniJavaParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 20);
    case 6: return precpred(_ctx, 19);
    case 7: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MiniJavaParser::_decisionToDFA;
atn::PredictionContextCache MiniJavaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MiniJavaParser::_atn;
std::vector<uint16_t> MiniJavaParser::_serializedATN;

std::vector<std::string> MiniJavaParser::_ruleNames = {
  "prog", "mainClass", "classDecl", "methodDecl", "methodBody", "methodReturn", 
  "methodCall", "params", "type", "varDecl", "varDeclAndAtt", "statement", 
  "expression", "expList"
};

std::vector<std::string> MiniJavaParser::_literalNames = {
  "", "'package'", "'import'", "'class'", "'interface'", "'extends'", "'implements'", 
  "'super'", "'this'", "'null'", "'new'", "'return'", "'instanceof'", "'public'", 
  "", "'static'", "", "'enum'", "'void'", "'int'", "'String'", "'boolean'", 
  "", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "", "'&&'", "'||'", 
  "'!'", "", "'++'", "'--'", "", "'assert'", "'if'", "'else'", "'switch'", 
  "'case'", "'default'", "'for'", "'while'", "'do'", "'goto'", "'continue'", 
  "'break'", "'try'", "'catch'", "'finally'", "'throws'", "'throw'", "'native'", 
  "'strictfp'", "'main'", "'length'", "'System.out.println'", "','", "'.'", 
  "';'", "'('", "')'", "'{'", "'}'", "'['", "']'"
};

std::vector<std::string> MiniJavaParser::_symbolicNames = {
  "", "PACKAGE", "IMPORT", "CLASS", "INTERFACE", "EXTENDS", "IMPLEMENTS", 
  "SUPER", "THIS", "NULLABLE", "NEW", "RETURN", "INSTANCEOF", "PUBLIC", 
  "ACCESS_MODIFIER", "STATIC", "MODIFIER", "ENUM", "VOID", "INT", "STRING", 
  "BOOLEAN", "TYPE", "ASSIGN", "SUM", "MINUS", "MULT", "DIV", "MOD", "POW", 
  "COMP_OP", "AND", "OR", "NOT", "TERNARY_OP", "INCREMENT_OP", "DECREMENT_OP", 
  "BITWISE_OP", "ASSERT", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "FOR", 
  "WHILE", "DO", "GOTO", "CONTINUE", "BREAK", "TRY", "CATCH", "FINALLY", 
  "THROWS", "THROW", "NATIVE", "STRICTFP", "MAIN", "LENGTH", "SOUT", "COMMA", 
  "DOT", "SC", "LP", "RP", "LCB", "RCB", "LSB", "RSB", "LITBOOL", "LITINT", 
  "LITSTRING", "ID", "MULTILINE_COMMENT", "LINE_COMMENT", "WHITESPACE"
};

dfa::Vocabulary MiniJavaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MiniJavaParser::_tokenNames;

MiniJavaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4d, 0x124, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x21, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x24, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3c, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x40, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x43, 0xb, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x46, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x49, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x58, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x7, 0x6, 0x5d, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x60, 0xb, 0x6, 0x3, 0x6, 0x7, 0x6, 0x63, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x66, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x71, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x79, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x7f, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x82, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x8a, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x8d, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x96, 0xa, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9d, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xab, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xaf, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xb2, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xdf, 0xa, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xfb, 0xa, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x117, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x11a, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0x11f, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x122, 0xb, 0xf, 0x3, 0xf, 0x2, 
    0x3, 0x1a, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1a, 
    0x1b, 0x2, 0x145, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x37, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x83, 0x3, 0x2, 0x2, 0x2, 0x12, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x16, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xde, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x22, 0x5, 0x4, 0x3, 0x2, 
    0x1f, 0x21, 0x5, 0x6, 0x4, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x24, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x3, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x5, 0x2, 0x2, 0x26, 0x27, 0x7, 0x4a, 
    0x2, 0x2, 0x27, 0x28, 0x7, 0x43, 0x2, 0x2, 0x28, 0x29, 0x7, 0xf, 0x2, 
    0x2, 0x29, 0x2a, 0x7, 0x11, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x14, 0x2, 0x2, 
    0x2b, 0x2c, 0x7, 0x3b, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x41, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0x16, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x45, 0x2, 0x2, 0x2f, 0x30, 
    0x7, 0x46, 0x2, 0x2, 0x30, 0x31, 0x7, 0x4a, 0x2, 0x2, 0x31, 0x32, 0x7, 
    0x42, 0x2, 0x2, 0x32, 0x33, 0x7, 0x43, 0x2, 0x2, 0x33, 0x34, 0x5, 0xa, 
    0x6, 0x2, 0x34, 0x35, 0x7, 0x44, 0x2, 0x2, 0x35, 0x36, 0x7, 0x44, 0x2, 
    0x2, 0x36, 0x5, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x5, 0x2, 0x2, 
    0x38, 0x3b, 0x7, 0x4a, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x7, 0x2, 0x2, 0x3a, 
    0x3c, 0x7, 0x4a, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x41, 0x7, 
    0x43, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x14, 0xb, 0x2, 0x3f, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x5, 0x8, 0x5, 0x2, 0x45, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x44, 
    0x2, 0x2, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xf, 0x2, 
    0x2, 0x4d, 0x4e, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x7, 0x4a, 0x2, 0x2, 
    0x4f, 0x51, 0x7, 0x41, 0x2, 0x2, 0x50, 0x52, 0x5, 0x10, 0x9, 0x2, 0x51, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x42, 0x2, 0x2, 0x54, 0x55, 0x7, 
    0x43, 0x2, 0x2, 0x55, 0x57, 0x5, 0xa, 0x6, 0x2, 0x56, 0x58, 0x5, 0xc, 
    0x7, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x44, 0x2, 0x2, 
    0x5a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0x14, 0xb, 0x2, 0x5c, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0x5, 0x18, 
    0xd, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0xb, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x7, 0xd, 0x2, 0x2, 0x68, 0x69, 0x5, 0x1a, 0xe, 0x2, 0x69, 0x6a, 
    0x7, 0x40, 0x2, 0x2, 0x6a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 
    0x9, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x3f, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x4a, 
    0x2, 0x2, 0x6e, 0x70, 0x7, 0x41, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x1c, 0xf, 
    0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x82, 0x7, 0x42, 0x2, 0x2, 0x73, 
    0x74, 0x7, 0xa, 0x2, 0x2, 0x74, 0x75, 0x7, 0x3f, 0x2, 0x2, 0x75, 0x76, 
    0x7, 0x4a, 0x2, 0x2, 0x76, 0x78, 0x7, 0x41, 0x2, 0x2, 0x77, 0x79, 0x5, 
    0x1c, 0xf, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x82, 0x7, 0x42, 0x2, 
    0x2, 0x7b, 0x7c, 0x7, 0x4a, 0x2, 0x2, 0x7c, 0x7e, 0x7, 0x41, 0x2, 0x2, 
    0x7d, 0x7f, 0x5, 0x1c, 0xf, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 
    0x7, 0x42, 0x2, 0x2, 0x81, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x81, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x82, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x5, 0x12, 0xa, 0x2, 0x84, 0x8b, 0x7, 0x4a, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0x3e, 0x2, 0x2, 0x86, 0x87, 0x5, 0x12, 0xa, 0x2, 
    0x87, 0x88, 0x7, 0x4a, 0x2, 0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x96, 0x7, 0x14, 
    0x2, 0x2, 0x8f, 0x90, 0x7, 0x15, 0x2, 0x2, 0x90, 0x91, 0x7, 0x45, 0x2, 
    0x2, 0x91, 0x96, 0x7, 0x46, 0x2, 0x2, 0x92, 0x96, 0x7, 0x15, 0x2, 0x2, 
    0x93, 0x96, 0x7, 0x17, 0x2, 0x2, 0x94, 0x96, 0x7, 0x4a, 0x2, 0x2, 0x95, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x95, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x13, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 0x12, 
    0xa, 0x2, 0x98, 0x99, 0x7, 0x4a, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x40, 0x2, 
    0x2, 0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x16, 0xc, 0x2, 
    0x9c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x12, 0xa, 0x2, 0x9f, 0xa0, 
    0x7, 0x4a, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x19, 0x2, 0x2, 0xa1, 0xa2, 0x5, 
    0x1a, 0xe, 0x2, 0xa2, 0xa3, 0x7, 0x40, 0x2, 0x2, 0xa3, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x5, 0x12, 0xa, 0x2, 0xa5, 0xa6, 0x7, 0x4a, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0x19, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0xe, 0x8, 0x2, 
    0xa8, 0xa9, 0x7, 0x40, 0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xab, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xb0, 0x7, 0x43, 0x2, 0x2, 0xad, 0xaf, 0x5, 
    0x18, 0xd, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xdf, 0x7, 0x44, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x29, 0x2, 0x2, 0xb5, 
    0xb6, 0x7, 0x41, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x1a, 0xe, 0x2, 0xb7, 0xb8, 
    0x7, 0x42, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x18, 0xd, 0x2, 0xb9, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x29, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x41, 
    0x2, 0x2, 0xbc, 0xbd, 0x5, 0x1a, 0xe, 0x2, 0xbd, 0xbe, 0x7, 0x42, 0x2, 
    0x2, 0xbe, 0xbf, 0x5, 0x18, 0xd, 0x2, 0xbf, 0xc0, 0x7, 0x2a, 0x2, 0x2, 
    0xc0, 0xc1, 0x5, 0x18, 0xd, 0x2, 0xc1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x7, 0x2f, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x41, 0x2, 0x2, 0xc4, 0xc5, 
    0x5, 0x1a, 0xe, 0x2, 0xc5, 0xc6, 0x7, 0x42, 0x2, 0x2, 0xc6, 0xc7, 0x5, 
    0x18, 0xd, 0x2, 0xc7, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x3d, 
    0x2, 0x2, 0xc9, 0xca, 0x7, 0x41, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x1a, 0xe, 
    0x2, 0xcb, 0xcc, 0x7, 0x42, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x40, 0x2, 0x2, 
    0xcd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x4a, 0x2, 0x2, 0xcf, 
    0xd0, 0x7, 0x19, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x1a, 0xe, 0x2, 0xd1, 0xd2, 
    0x7, 0x40, 0x2, 0x2, 0xd2, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 
    0x4a, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x45, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x1a, 
    0xe, 0x2, 0xd6, 0xd7, 0x7, 0x46, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x19, 0x2, 
    0x2, 0xd8, 0xd9, 0x5, 0x1a, 0xe, 0x2, 0xd9, 0xda, 0x7, 0x40, 0x2, 0x2, 
    0xda, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0xe, 0x8, 0x2, 0xdc, 
    0xdd, 0x7, 0x40, 0x2, 0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xde, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xde, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xce, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xe1, 0x8, 0xe, 0x1, 0x2, 0xe1, 0xe2, 0x7, 0x41, 0x2, 0x2, 0xe2, 
    0xe3, 0x5, 0x1a, 0xe, 0x2, 0xe3, 0xe4, 0x7, 0x42, 0x2, 0x2, 0xe4, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x1b, 0x2, 0x2, 0xe6, 0xfb, 0x5, 
    0x1a, 0xe, 0x12, 0xe7, 0xe8, 0x7, 0x23, 0x2, 0x2, 0xe8, 0xfb, 0x5, 0x1a, 
    0xe, 0x11, 0xe9, 0xea, 0x7, 0xc, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x15, 0x2, 
    0x2, 0xeb, 0xec, 0x7, 0x45, 0x2, 0x2, 0xec, 0xed, 0x5, 0x1a, 0xe, 0x2, 
    0xed, 0xee, 0x7, 0x46, 0x2, 0x2, 0xee, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0xc, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x4a, 0x2, 0x2, 0xf1, 0xf2, 
    0x7, 0x41, 0x2, 0x2, 0xf2, 0xfb, 0x7, 0x42, 0x2, 0x2, 0xf3, 0xfb, 0x5, 
    0xe, 0x8, 0x2, 0xf4, 0xfb, 0x7, 0x9, 0x2, 0x2, 0xf5, 0xfb, 0x7, 0xa, 
    0x2, 0x2, 0xf6, 0xfb, 0x7, 0x48, 0x2, 0x2, 0xf7, 0xfb, 0x7, 0x49, 0x2, 
    0x2, 0xf8, 0xfb, 0x7, 0x47, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x4a, 0x2, 0x2, 
    0xfa, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0xc, 0xd, 0x2, 0x2, 0xfd, 0xfe, 0x9, 0x2, 0x2, 0x2, 0xfe, 
    0x117, 0x5, 0x1a, 0xe, 0xe, 0xff, 0x100, 0xc, 0xc, 0x2, 0x2, 0x100, 
    0x101, 0x9, 0x3, 0x2, 0x2, 0x101, 0x117, 0x5, 0x1a, 0xe, 0xd, 0x102, 
    0x103, 0xc, 0xb, 0x2, 0x2, 0x103, 0x104, 0x7, 0x20, 0x2, 0x2, 0x104, 
    0x117, 0x5, 0x1a, 0xe, 0xc, 0x105, 0x106, 0xc, 0xa, 0x2, 0x2, 0x106, 
    0x107, 0x7, 0x21, 0x2, 0x2, 0x107, 0x117, 0x5, 0x1a, 0xe, 0xb, 0x108, 
    0x109, 0xc, 0x9, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x22, 0x2, 0x2, 0x10a, 
    0x117, 0x5, 0x1a, 0xe, 0xa, 0x10b, 0x10c, 0xc, 0x16, 0x2, 0x2, 0x10c, 
    0x10d, 0x7, 0x45, 0x2, 0x2, 0x10d, 0x10e, 0x5, 0x1a, 0xe, 0x2, 0x10e, 
    0x10f, 0x7, 0x46, 0x2, 0x2, 0x10f, 0x117, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0x111, 0xc, 0x15, 0x2, 0x2, 0x111, 0x112, 0x7, 0x3f, 0x2, 0x2, 0x112, 
    0x117, 0x7, 0x3c, 0x2, 0x2, 0x113, 0x114, 0xc, 0x14, 0x2, 0x2, 0x114, 
    0x115, 0x7, 0x3f, 0x2, 0x2, 0x115, 0x117, 0x5, 0xe, 0x8, 0x2, 0x116, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0x116, 0xff, 0x3, 0x2, 0x2, 0x2, 0x116, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x105, 0x3, 0x2, 0x2, 0x2, 0x116, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x116, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x113, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x119, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x11b, 0x120, 0x5, 0x1a, 0xe, 0x2, 0x11c, 0x11d, 0x7, 
    0x3e, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x1a, 0xe, 0x2, 0x11e, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 
    0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x18, 0x22, 0x3b, 0x41, 
    0x47, 0x51, 0x57, 0x5e, 0x64, 0x70, 0x78, 0x7e, 0x81, 0x8b, 0x95, 0x9c, 
    0xaa, 0xb0, 0xde, 0xfa, 0x116, 0x118, 0x120, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MiniJavaParser::Initializer MiniJavaParser::_init;
