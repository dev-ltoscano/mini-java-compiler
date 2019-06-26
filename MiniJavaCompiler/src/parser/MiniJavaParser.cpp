/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/

#include "parser/MiniJavaParser.h"

#include "parser/listener/MiniJavaListener.h"
#include "parser/visitor/MiniJavaVisitor.h"

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
    setState(30);
    mainClass();
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::CLASS) {
      setState(31);
      classDecl();
      setState(36);
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
    setState(37);
    match(MiniJavaParser::CLASS);
    setState(38);
    match(MiniJavaParser::ID);
    setState(39);
    match(MiniJavaParser::LCB);
    setState(40);
    match(MiniJavaParser::PUBLIC);
    setState(41);
    match(MiniJavaParser::STATIC);
    setState(42);
    match(MiniJavaParser::VOID);
    setState(43);
    match(MiniJavaParser::MAIN);
    setState(44);
    match(MiniJavaParser::LP);
    setState(45);
    match(MiniJavaParser::STRING);
    setState(46);
    match(MiniJavaParser::LSB);
    setState(47);
    match(MiniJavaParser::RSB);
    setState(48);
    match(MiniJavaParser::ID);
    setState(49);
    match(MiniJavaParser::RP);
    setState(50);
    match(MiniJavaParser::LCB);
    setState(51);
    methodBody();
    setState(52);
    match(MiniJavaParser::RCB);
    setState(53);
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

std::vector<MiniJavaParser::MethodDeclContext *> MiniJavaParser::ClassDeclContext::methodDecl() {
  return getRuleContexts<MiniJavaParser::MethodDeclContext>();
}

MiniJavaParser::MethodDeclContext* MiniJavaParser::ClassDeclContext::methodDecl(size_t i) {
  return getRuleContext<MiniJavaParser::MethodDeclContext>(i);
}

std::vector<MiniJavaParser::VarDeclContext *> MiniJavaParser::ClassDeclContext::varDecl() {
  return getRuleContexts<MiniJavaParser::VarDeclContext>();
}

MiniJavaParser::VarDeclContext* MiniJavaParser::ClassDeclContext::varDecl(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclContext>(i);
}

std::vector<MiniJavaParser::VarDeclAndAttContext *> MiniJavaParser::ClassDeclContext::varDeclAndAtt() {
  return getRuleContexts<MiniJavaParser::VarDeclAndAttContext>();
}

MiniJavaParser::VarDeclAndAttContext* MiniJavaParser::ClassDeclContext::varDeclAndAtt(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclAndAttContext>(i);
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
    setState(55);
    match(MiniJavaParser::CLASS);
    setState(56);
    match(MiniJavaParser::ID);
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MiniJavaParser::EXTENDS) {
      setState(57);
      match(MiniJavaParser::EXTENDS);
      setState(58);
      match(MiniJavaParser::ID);
    }
    setState(61);
    match(MiniJavaParser::LCB);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 13) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 13)) & ((1ULL << (MiniJavaParser::PUBLIC - 13))
      | (1ULL << (MiniJavaParser::INT - 13))
      | (1ULL << (MiniJavaParser::STRING - 13))
      | (1ULL << (MiniJavaParser::BOOLEAN - 13))
      | (1ULL << (MiniJavaParser::ID - 13)))) != 0)) {
      setState(67);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MiniJavaParser::INT:
        case MiniJavaParser::STRING:
        case MiniJavaParser::BOOLEAN:
        case MiniJavaParser::ID: {
          setState(64);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
          case 1: {
            setState(62);
            varDecl();
            break;
          }

          case 2: {
            setState(63);
            varDeclAndAtt();
            break;
          }

          }
          break;
        }

        case MiniJavaParser::PUBLIC: {
          setState(66);
          methodDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
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

MiniJavaParser::MethodTypeContext* MiniJavaParser::MethodDeclContext::methodType() {
  return getRuleContext<MiniJavaParser::MethodTypeContext>(0);
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

MiniJavaParser::MethodParamsContext* MiniJavaParser::MethodDeclContext::methodParams() {
  return getRuleContext<MiniJavaParser::MethodParamsContext>(0);
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
    methodType();
    setState(76);
    match(MiniJavaParser::ID);
    setState(77);
    match(MiniJavaParser::LP);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 19) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 19)) & ((1ULL << (MiniJavaParser::INT - 19))
      | (1ULL << (MiniJavaParser::STRING - 19))
      | (1ULL << (MiniJavaParser::BOOLEAN - 19))
      | (1ULL << (MiniJavaParser::ID - 19)))) != 0)) {
      setState(78);
      methodParams();
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

std::vector<MiniJavaParser::StatementContext *> MiniJavaParser::MethodBodyContext::statement() {
  return getRuleContexts<MiniJavaParser::StatementContext>();
}

MiniJavaParser::StatementContext* MiniJavaParser::MethodBodyContext::statement(size_t i) {
  return getRuleContext<MiniJavaParser::StatementContext>(i);
}

std::vector<MiniJavaParser::VarDeclContext *> MiniJavaParser::MethodBodyContext::varDecl() {
  return getRuleContexts<MiniJavaParser::VarDeclContext>();
}

MiniJavaParser::VarDeclContext* MiniJavaParser::MethodBodyContext::varDecl(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclContext>(i);
}

std::vector<MiniJavaParser::VarDeclAndAttContext *> MiniJavaParser::MethodBodyContext::varDeclAndAtt() {
  return getRuleContexts<MiniJavaParser::VarDeclAndAttContext>();
}

MiniJavaParser::VarDeclAndAttContext* MiniJavaParser::MethodBodyContext::varDeclAndAtt(size_t i) {
  return getRuleContext<MiniJavaParser::VarDeclAndAttContext>(i);
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
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
      | (1ULL << MiniJavaParser::THIS)
      | (1ULL << MiniJavaParser::INT)
      | (1ULL << MiniJavaParser::STRING)
      | (1ULL << MiniJavaParser::BOOLEAN)
      | (1ULL << MiniJavaParser::IF)
      | (1ULL << MiniJavaParser::WHILE)
      | (1ULL << MiniJavaParser::SOUT))) != 0) || _la == MiniJavaParser::LCB

    || _la == MiniJavaParser::ID) {
      setState(94);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(91);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          setState(89);
          varDecl();
          break;
        }

        case 2: {
          setState(90);
          varDeclAndAtt();
          break;
        }

        }
        break;
      }

      case 2: {
        setState(93);
        statement();
        break;
      }

      }
      setState(98);
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
    setState(99);
    match(MiniJavaParser::RETURN);
    setState(100);
    expression(0);
    setState(101);
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

std::vector<tree::TerminalNode *> MiniJavaParser::MethodCallContext::ID() {
  return getTokens(MiniJavaParser::ID);
}

tree::TerminalNode* MiniJavaParser::MethodCallContext::ID(size_t i) {
  return getToken(MiniJavaParser::ID, i);
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
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      match(MiniJavaParser::SUPER);
      setState(104);
      match(MiniJavaParser::DOT);
      setState(105);
      match(MiniJavaParser::ID);
      setState(106);
      match(MiniJavaParser::LP);
      setState(108);
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
        setState(107);
        expList();
      }
      setState(110);
      match(MiniJavaParser::RP);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(MiniJavaParser::THIS);
      setState(112);
      match(MiniJavaParser::DOT);
      setState(113);
      match(MiniJavaParser::ID);
      setState(114);
      match(MiniJavaParser::LP);
      setState(116);
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
        setState(115);
        expList();
      }
      setState(118);
      match(MiniJavaParser::RP);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(119);
      match(MiniJavaParser::ID);
      setState(120);
      match(MiniJavaParser::LP);
      setState(122);
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
        setState(121);
        expList();
      }
      setState(124);
      match(MiniJavaParser::RP);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(125);
      match(MiniJavaParser::ID);
      setState(126);
      match(MiniJavaParser::DOT);
      setState(127);
      match(MiniJavaParser::ID);
      setState(128);
      match(MiniJavaParser::LP);
      setState(130);
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
        setState(129);
        expList();
      }
      setState(132);
      match(MiniJavaParser::RP);
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

//----------------- MethodParamsContext ------------------------------------------------------------------

MiniJavaParser::MethodParamsContext::MethodParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniJavaParser::VarTypeContext *> MiniJavaParser::MethodParamsContext::varType() {
  return getRuleContexts<MiniJavaParser::VarTypeContext>();
}

MiniJavaParser::VarTypeContext* MiniJavaParser::MethodParamsContext::varType(size_t i) {
  return getRuleContext<MiniJavaParser::VarTypeContext>(i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::MethodParamsContext::ID() {
  return getTokens(MiniJavaParser::ID);
}

tree::TerminalNode* MiniJavaParser::MethodParamsContext::ID(size_t i) {
  return getToken(MiniJavaParser::ID, i);
}

std::vector<tree::TerminalNode *> MiniJavaParser::MethodParamsContext::COMMA() {
  return getTokens(MiniJavaParser::COMMA);
}

tree::TerminalNode* MiniJavaParser::MethodParamsContext::COMMA(size_t i) {
  return getToken(MiniJavaParser::COMMA, i);
}


size_t MiniJavaParser::MethodParamsContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodParams;
}

void MiniJavaParser::MethodParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodParams(this);
}

void MiniJavaParser::MethodParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodParams(this);
}


antlrcpp::Any MiniJavaParser::MethodParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodParams(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodParamsContext* MiniJavaParser::methodParams() {
  MethodParamsContext *_localctx = _tracker.createInstance<MethodParamsContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniJavaParser::RuleMethodParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    varType();
    setState(136);
    match(MiniJavaParser::ID);
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::COMMA) {
      setState(137);
      match(MiniJavaParser::COMMA);
      setState(138);
      varType();
      setState(139);
      match(MiniJavaParser::ID);
      setState(145);
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

//----------------- MethodTypeContext ------------------------------------------------------------------

MiniJavaParser::MethodTypeContext::MethodTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::VOID() {
  return getToken(MiniJavaParser::VOID, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::INT() {
  return getToken(MiniJavaParser::INT, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::BOOLEAN() {
  return getToken(MiniJavaParser::BOOLEAN, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::STRING() {
  return getToken(MiniJavaParser::STRING, 0);
}

tree::TerminalNode* MiniJavaParser::MethodTypeContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}


size_t MiniJavaParser::MethodTypeContext::getRuleIndex() const {
  return MiniJavaParser::RuleMethodType;
}

void MiniJavaParser::MethodTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodType(this);
}

void MiniJavaParser::MethodTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodType(this);
}


antlrcpp::Any MiniJavaParser::MethodTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitMethodType(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::MethodTypeContext* MiniJavaParser::methodType() {
  MethodTypeContext *_localctx = _tracker.createInstance<MethodTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniJavaParser::RuleMethodType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      match(MiniJavaParser::VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(147);
      match(MiniJavaParser::INT);
      setState(148);
      match(MiniJavaParser::LSB);
      setState(149);
      match(MiniJavaParser::RSB);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(150);
      match(MiniJavaParser::INT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(151);
      match(MiniJavaParser::BOOLEAN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(152);
      match(MiniJavaParser::STRING);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(153);
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

//----------------- VarTypeContext ------------------------------------------------------------------

MiniJavaParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::INT() {
  return getToken(MiniJavaParser::INT, 0);
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::LSB() {
  return getToken(MiniJavaParser::LSB, 0);
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::RSB() {
  return getToken(MiniJavaParser::RSB, 0);
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::BOOLEAN() {
  return getToken(MiniJavaParser::BOOLEAN, 0);
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::STRING() {
  return getToken(MiniJavaParser::STRING, 0);
}

tree::TerminalNode* MiniJavaParser::VarTypeContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}


size_t MiniJavaParser::VarTypeContext::getRuleIndex() const {
  return MiniJavaParser::RuleVarType;
}

void MiniJavaParser::VarTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarType(this);
}

void MiniJavaParser::VarTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniJavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarType(this);
}


antlrcpp::Any MiniJavaParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniJavaVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

MiniJavaParser::VarTypeContext* MiniJavaParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniJavaParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      match(MiniJavaParser::INT);
      setState(157);
      match(MiniJavaParser::LSB);
      setState(158);
      match(MiniJavaParser::RSB);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      match(MiniJavaParser::INT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(160);
      match(MiniJavaParser::BOOLEAN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(161);
      match(MiniJavaParser::STRING);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(162);
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

MiniJavaParser::VarTypeContext* MiniJavaParser::VarDeclContext::varType() {
  return getRuleContext<MiniJavaParser::VarTypeContext>(0);
}

tree::TerminalNode* MiniJavaParser::VarDeclContext::ID() {
  return getToken(MiniJavaParser::ID, 0);
}

tree::TerminalNode* MiniJavaParser::VarDeclContext::SC() {
  return getToken(MiniJavaParser::SC, 0);
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
  enterRule(_localctx, 20, MiniJavaParser::RuleVarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    varType();
    setState(166);
    match(MiniJavaParser::ID);
    setState(167);
    match(MiniJavaParser::SC);
   
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

MiniJavaParser::VarTypeContext* MiniJavaParser::VarDeclAndAttContext::varType() {
  return getRuleContext<MiniJavaParser::VarTypeContext>(0);
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
  enterRule(_localctx, 22, MiniJavaParser::RuleVarDeclAndAtt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    varType();
    setState(170);
    match(MiniJavaParser::ID);
    setState(171);
    match(MiniJavaParser::ASSIGN);
    setState(172);
    expression(0);
    setState(173);
    match(MiniJavaParser::SC);
   
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
  enterRule(_localctx, 24, MiniJavaParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      match(MiniJavaParser::LCB);
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniJavaParser::SUPER)
        | (1ULL << MiniJavaParser::THIS)
        | (1ULL << MiniJavaParser::IF)
        | (1ULL << MiniJavaParser::WHILE)
        | (1ULL << MiniJavaParser::SOUT))) != 0) || _la == MiniJavaParser::LCB

      || _la == MiniJavaParser::ID) {
        setState(176);
        statement();
        setState(181);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(182);
      match(MiniJavaParser::RCB);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(183);
      match(MiniJavaParser::IF);
      setState(184);
      match(MiniJavaParser::LP);
      setState(185);
      expression(0);
      setState(186);
      match(MiniJavaParser::RP);
      setState(187);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(189);
      match(MiniJavaParser::IF);
      setState(190);
      match(MiniJavaParser::LP);
      setState(191);
      expression(0);
      setState(192);
      match(MiniJavaParser::RP);
      setState(193);
      statement();
      setState(194);
      match(MiniJavaParser::ELSE);
      setState(195);
      statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(197);
      match(MiniJavaParser::WHILE);
      setState(198);
      match(MiniJavaParser::LP);
      setState(199);
      expression(0);
      setState(200);
      match(MiniJavaParser::RP);
      setState(201);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(203);
      match(MiniJavaParser::SOUT);
      setState(204);
      match(MiniJavaParser::LP);
      setState(205);
      expression(0);
      setState(206);
      match(MiniJavaParser::RP);
      setState(207);
      match(MiniJavaParser::SC);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(209);
      match(MiniJavaParser::ID);
      setState(210);
      match(MiniJavaParser::ASSIGN);
      setState(211);
      expression(0);
      setState(212);
      match(MiniJavaParser::SC);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(214);
      match(MiniJavaParser::ID);
      setState(215);
      match(MiniJavaParser::LSB);
      setState(216);
      expression(0);
      setState(217);
      match(MiniJavaParser::RSB);
      setState(218);
      match(MiniJavaParser::ASSIGN);
      setState(219);
      expression(0);
      setState(220);
      match(MiniJavaParser::SC);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(222);
      methodCall();
      setState(223);
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
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MiniJavaParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(228);
      match(MiniJavaParser::LP);
      setState(229);
      expression(0);
      setState(230);
      match(MiniJavaParser::RP);
      break;
    }

    case 2: {
      setState(232);
      match(MiniJavaParser::MINUS);
      setState(233);
      expression(16);
      break;
    }

    case 3: {
      setState(234);
      match(MiniJavaParser::NOT);
      setState(235);
      expression(15);
      break;
    }

    case 4: {
      setState(236);
      match(MiniJavaParser::NEW);
      setState(237);
      match(MiniJavaParser::INT);
      setState(238);
      match(MiniJavaParser::LSB);
      setState(239);
      expression(0);
      setState(240);
      match(MiniJavaParser::RSB);
      break;
    }

    case 5: {
      setState(242);
      match(MiniJavaParser::NEW);
      setState(243);
      match(MiniJavaParser::ID);
      setState(244);
      match(MiniJavaParser::LP);
      setState(245);
      match(MiniJavaParser::RP);
      break;
    }

    case 6: {
      setState(246);
      methodCall();
      break;
    }

    case 7: {
      setState(247);
      match(MiniJavaParser::SUPER);
      break;
    }

    case 8: {
      setState(248);
      match(MiniJavaParser::THIS);
      break;
    }

    case 9: {
      setState(249);
      match(MiniJavaParser::LITINT);
      break;
    }

    case 10: {
      setState(250);
      match(MiniJavaParser::LITSTRING);
      break;
    }

    case 11: {
      setState(251);
      match(MiniJavaParser::LITBOOL);
      break;
    }

    case 12: {
      setState(252);
      match(MiniJavaParser::ID);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(283);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(281);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(256);
          _la = _input->LA(1);
          if (!(_la == MiniJavaParser::MULT

          || _la == MiniJavaParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(257);
          expression(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(259);
          _la = _input->LA(1);
          if (!(_la == MiniJavaParser::SUM

          || _la == MiniJavaParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(260);
          expression(11);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(262);
          match(MiniJavaParser::COMP_OP);
          setState(263);
          expression(10);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(264);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(265);
          match(MiniJavaParser::AND);
          setState(266);
          expression(9);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(267);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(268);
          match(MiniJavaParser::OR);
          setState(269);
          expression(8);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(271);
          match(MiniJavaParser::LSB);
          setState(272);
          expression(0);
          setState(273);
          match(MiniJavaParser::RSB);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(275);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(276);
          match(MiniJavaParser::DOT);
          setState(277);
          match(MiniJavaParser::LENGTH);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(278);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(279);
          match(MiniJavaParser::DOT);
          setState(280);
          methodCall();
          break;
        }

        } 
      }
      setState(285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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
  enterRule(_localctx, 28, MiniJavaParser::RuleExpList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    expression(0);
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniJavaParser::COMMA) {
      setState(287);
      match(MiniJavaParser::COMMA);
      setState(288);
      expression(0);
      setState(293);
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
    case 13: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
  "methodCall", "methodParams", "methodType", "varType", "varDecl", "varDeclAndAtt", 
  "statement", "expression", "expList"
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
    0x3, 0x4d, 0x129, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x23, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x26, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x3e, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x43, 0xa, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x46, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x49, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x58, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0x5e, 0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x61, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x64, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6f, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x77, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x7d, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x85, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x88, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x90, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0x93, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9d, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xa6, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0xb4, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xb7, 0xb, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0xe4, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x100, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0x11c, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x11f, 0xb, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x124, 0xa, 0x10, 0xc, 
    0x10, 0xe, 0x10, 0x127, 0xb, 0x10, 0x3, 0x10, 0x2, 0x3, 0x1c, 0x11, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x2, 0x4, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1a, 0x1b, 0x2, 
    0x150, 0x2, 0x20, 0x3, 0x2, 0x2, 0x2, 0x4, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x89, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0xab, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xff, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x20, 0x24, 
    0x5, 0x4, 0x3, 0x2, 0x21, 0x23, 0x5, 0x6, 0x4, 0x2, 0x22, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x26, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x5, 0x2, 0x2, 
    0x28, 0x29, 0x7, 0x4a, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x43, 0x2, 0x2, 0x2a, 
    0x2b, 0x7, 0xf, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x11, 0x2, 0x2, 0x2c, 0x2d, 
    0x7, 0x14, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x3b, 0x2, 0x2, 0x2e, 0x2f, 0x7, 
    0x41, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x16, 0x2, 0x2, 0x30, 0x31, 0x7, 0x45, 
    0x2, 0x2, 0x31, 0x32, 0x7, 0x46, 0x2, 0x2, 0x32, 0x33, 0x7, 0x4a, 0x2, 
    0x2, 0x33, 0x34, 0x7, 0x42, 0x2, 0x2, 0x34, 0x35, 0x7, 0x43, 0x2, 0x2, 
    0x35, 0x36, 0x5, 0xa, 0x6, 0x2, 0x36, 0x37, 0x7, 0x44, 0x2, 0x2, 0x37, 
    0x38, 0x7, 0x44, 0x2, 0x2, 0x38, 0x5, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0x5, 0x2, 0x2, 0x3a, 0x3d, 0x7, 0x4a, 0x2, 0x2, 0x3b, 0x3c, 0x7, 
    0x7, 0x2, 0x2, 0x3c, 0x3e, 0x7, 0x4a, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x47, 0x7, 0x43, 0x2, 0x2, 0x40, 0x43, 0x5, 0x16, 0xc, 0x2, 
    0x41, 0x43, 0x5, 0x18, 0xd, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 
    0x5, 0x8, 0x5, 0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x44, 0x2, 0x2, 
    0x4b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xf, 0x2, 0x2, 0x4d, 
    0x4e, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x7, 0x4a, 0x2, 0x2, 0x4f, 0x51, 
    0x7, 0x41, 0x2, 0x2, 0x50, 0x52, 0x5, 0x10, 0x9, 0x2, 0x51, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x54, 0x7, 0x42, 0x2, 0x2, 0x54, 0x55, 0x7, 0x43, 0x2, 
    0x2, 0x55, 0x57, 0x5, 0xa, 0x6, 0x2, 0x56, 0x58, 0x5, 0xc, 0x7, 0x2, 
    0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x44, 0x2, 0x2, 0x5a, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e, 0x5, 0x16, 0xc, 0x2, 0x5c, 0x5e, 0x5, 
    0x18, 0xd, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x5, 0x1a, 0xe, 
    0x2, 0x60, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0xb, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0xd, 0x2, 0x2, 0x66, 0x67, 0x5, 
    0x1c, 0xf, 0x2, 0x67, 0x68, 0x7, 0x40, 0x2, 0x2, 0x68, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x6a, 0x7, 0x9, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x3f, 0x2, 
    0x2, 0x6b, 0x6c, 0x7, 0x4a, 0x2, 0x2, 0x6c, 0x6e, 0x7, 0x41, 0x2, 0x2, 
    0x6d, 0x6f, 0x5, 0x1e, 0x10, 0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x88, 
    0x7, 0x42, 0x2, 0x2, 0x71, 0x72, 0x7, 0xa, 0x2, 0x2, 0x72, 0x73, 0x7, 
    0x3f, 0x2, 0x2, 0x73, 0x74, 0x7, 0x4a, 0x2, 0x2, 0x74, 0x76, 0x7, 0x41, 
    0x2, 0x2, 0x75, 0x77, 0x5, 0x1e, 0x10, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x88, 0x7, 0x42, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x4a, 0x2, 0x2, 0x7a, 
    0x7c, 0x7, 0x41, 0x2, 0x2, 0x7b, 0x7d, 0x5, 0x1e, 0x10, 0x2, 0x7c, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x88, 0x7, 0x42, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x4a, 
    0x2, 0x2, 0x80, 0x81, 0x7, 0x3f, 0x2, 0x2, 0x81, 0x82, 0x7, 0x4a, 0x2, 
    0x2, 0x82, 0x84, 0x7, 0x41, 0x2, 0x2, 0x83, 0x85, 0x5, 0x1e, 0x10, 0x2, 
    0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x7, 0x42, 0x2, 0x2, 0x87, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x71, 0x3, 0x2, 0x2, 0x2, 0x87, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x88, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x5, 0x14, 0xb, 0x2, 0x8a, 0x91, 0x7, 0x4a, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0x3e, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x14, 0xb, 0x2, 
    0x8d, 0x8e, 0x7, 0x4a, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x9d, 0x7, 0x14, 
    0x2, 0x2, 0x95, 0x96, 0x7, 0x15, 0x2, 0x2, 0x96, 0x97, 0x7, 0x45, 0x2, 
    0x2, 0x97, 0x9d, 0x7, 0x46, 0x2, 0x2, 0x98, 0x9d, 0x7, 0x15, 0x2, 0x2, 
    0x99, 0x9d, 0x7, 0x17, 0x2, 0x2, 0x9a, 0x9d, 0x7, 0x16, 0x2, 0x2, 0x9b, 
    0x9d, 0x7, 0x4a, 0x2, 0x2, 0x9c, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x15, 0x2, 
    0x2, 0x9f, 0xa0, 0x7, 0x45, 0x2, 0x2, 0xa0, 0xa6, 0x7, 0x46, 0x2, 0x2, 
    0xa1, 0xa6, 0x7, 0x15, 0x2, 0x2, 0xa2, 0xa6, 0x7, 0x17, 0x2, 0x2, 0xa3, 
    0xa6, 0x7, 0x16, 0x2, 0x2, 0xa4, 0xa6, 0x7, 0x4a, 0x2, 0x2, 0xa5, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x14, 0xb, 
    0x2, 0xa8, 0xa9, 0x7, 0x4a, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x40, 0x2, 0x2, 
    0xaa, 0x17, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 0x14, 0xb, 0x2, 0xac, 
    0xad, 0x7, 0x4a, 0x2, 0x2, 0xad, 0xae, 0x7, 0x19, 0x2, 0x2, 0xae, 0xaf, 
    0x5, 0x1c, 0xf, 0x2, 0xaf, 0xb0, 0x7, 0x40, 0x2, 0x2, 0xb0, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb5, 0x7, 0x43, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x1a, 
    0xe, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xe4, 0x7, 0x44, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x29, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x41, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x1c, 0xf, 0x2, 0xbc, 0xbd, 0x7, 
    0x42, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x1a, 0xe, 0x2, 0xbe, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc0, 0x7, 0x29, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x41, 0x2, 
    0x2, 0xc1, 0xc2, 0x5, 0x1c, 0xf, 0x2, 0xc2, 0xc3, 0x7, 0x42, 0x2, 0x2, 
    0xc3, 0xc4, 0x5, 0x1a, 0xe, 0x2, 0xc4, 0xc5, 0x7, 0x2a, 0x2, 0x2, 0xc5, 
    0xc6, 0x5, 0x1a, 0xe, 0x2, 0xc6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 
    0x7, 0x2f, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x41, 0x2, 0x2, 0xc9, 0xca, 0x5, 
    0x1c, 0xf, 0x2, 0xca, 0xcb, 0x7, 0x42, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x1a, 
    0xe, 0x2, 0xcc, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x3d, 0x2, 
    0x2, 0xce, 0xcf, 0x7, 0x41, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x1c, 0xf, 0x2, 
    0xd0, 0xd1, 0x7, 0x42, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x40, 0x2, 0x2, 0xd2, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x4a, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x19, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x1c, 0xf, 0x2, 0xd6, 0xd7, 0x7, 
    0x40, 0x2, 0x2, 0xd7, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x4a, 
    0x2, 0x2, 0xd9, 0xda, 0x7, 0x45, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x1c, 0xf, 
    0x2, 0xdb, 0xdc, 0x7, 0x46, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x19, 0x2, 0x2, 
    0xdd, 0xde, 0x5, 0x1c, 0xf, 0x2, 0xde, 0xdf, 0x7, 0x40, 0x2, 0x2, 0xdf, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0xe, 0x8, 0x2, 0xe1, 0xe2, 
    0x7, 0x40, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe6, 0x8, 0xf, 0x1, 0x2, 0xe6, 0xe7, 0x7, 0x41, 0x2, 0x2, 0xe7, 0xe8, 
    0x5, 0x1c, 0xf, 0x2, 0xe8, 0xe9, 0x7, 0x42, 0x2, 0x2, 0xe9, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x1b, 0x2, 0x2, 0xeb, 0x100, 0x5, 0x1c, 
    0xf, 0x12, 0xec, 0xed, 0x7, 0x23, 0x2, 0x2, 0xed, 0x100, 0x5, 0x1c, 
    0xf, 0x11, 0xee, 0xef, 0x7, 0xc, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x15, 0x2, 
    0x2, 0xf0, 0xf1, 0x7, 0x45, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0x1c, 0xf, 0x2, 
    0xf2, 0xf3, 0x7, 0x46, 0x2, 0x2, 0xf3, 0x100, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf5, 0x7, 0xc, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x4a, 0x2, 0x2, 0xf6, 0xf7, 
    0x7, 0x41, 0x2, 0x2, 0xf7, 0x100, 0x7, 0x42, 0x2, 0x2, 0xf8, 0x100, 
    0x5, 0xe, 0x8, 0x2, 0xf9, 0x100, 0x7, 0x9, 0x2, 0x2, 0xfa, 0x100, 0x7, 
    0xa, 0x2, 0x2, 0xfb, 0x100, 0x7, 0x48, 0x2, 0x2, 0xfc, 0x100, 0x7, 0x49, 
    0x2, 0x2, 0xfd, 0x100, 0x7, 0x47, 0x2, 0x2, 0xfe, 0x100, 0x7, 0x4a, 
    0x2, 0x2, 0xff, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xff, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0xec, 0x3, 0x2, 0x2, 0x2, 0xff, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xff, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0xf9, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x11d, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x102, 0xc, 0xd, 0x2, 0x2, 0x102, 0x103, 0x9, 0x2, 
    0x2, 0x2, 0x103, 0x11c, 0x5, 0x1c, 0xf, 0xe, 0x104, 0x105, 0xc, 0xc, 
    0x2, 0x2, 0x105, 0x106, 0x9, 0x3, 0x2, 0x2, 0x106, 0x11c, 0x5, 0x1c, 
    0xf, 0xd, 0x107, 0x108, 0xc, 0xb, 0x2, 0x2, 0x108, 0x109, 0x7, 0x20, 
    0x2, 0x2, 0x109, 0x11c, 0x5, 0x1c, 0xf, 0xc, 0x10a, 0x10b, 0xc, 0xa, 
    0x2, 0x2, 0x10b, 0x10c, 0x7, 0x21, 0x2, 0x2, 0x10c, 0x11c, 0x5, 0x1c, 
    0xf, 0xb, 0x10d, 0x10e, 0xc, 0x9, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x22, 
    0x2, 0x2, 0x10f, 0x11c, 0x5, 0x1c, 0xf, 0xa, 0x110, 0x111, 0xc, 0x16, 
    0x2, 0x2, 0x111, 0x112, 0x7, 0x45, 0x2, 0x2, 0x112, 0x113, 0x5, 0x1c, 
    0xf, 0x2, 0x113, 0x114, 0x7, 0x46, 0x2, 0x2, 0x114, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x116, 0xc, 0x15, 0x2, 0x2, 0x116, 0x117, 0x7, 0x3f, 
    0x2, 0x2, 0x117, 0x11c, 0x7, 0x3c, 0x2, 0x2, 0x118, 0x119, 0xc, 0x14, 
    0x2, 0x2, 0x119, 0x11a, 0x7, 0x3f, 0x2, 0x2, 0x11a, 0x11c, 0x5, 0xe, 
    0x8, 0x2, 0x11b, 0x101, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x107, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x115, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x125, 0x5, 0x1c, 0xf, 
    0x2, 0x121, 0x122, 0x7, 0x3e, 0x2, 0x2, 0x122, 0x124, 0x5, 0x1c, 0xf, 
    0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x24, 0x3d, 0x42, 0x45, 0x47, 0x51, 0x57, 0x5d, 0x60, 0x62, 0x6e, 
    0x76, 0x7c, 0x84, 0x87, 0x91, 0x9c, 0xa5, 0xb5, 0xe3, 0xff, 0x11b, 0x11d, 
    0x125, 
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
