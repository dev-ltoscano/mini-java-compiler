/*
*	Jefferson do Nascimento Amar� (201765125C)
*	Luis Augusto Toscano Guimar�es (201365165AC)
*/
#pragma once

#include "MiniJavaListener.h"
#include "antlr4/antlr4-runtime.h"

/**
 * This class provides an empty implementation of MiniJavaListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MiniJavaBaseListener : public MiniJavaListener {
public:

  virtual void enterProg(MiniJavaParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(MiniJavaParser::ProgContext * /*ctx*/) override { }

  virtual void enterMainClass(MiniJavaParser::MainClassContext * /*ctx*/) override { }
  virtual void exitMainClass(MiniJavaParser::MainClassContext * /*ctx*/) override { }

  virtual void enterClassDecl(MiniJavaParser::ClassDeclContext * /*ctx*/) override { }
  virtual void exitClassDecl(MiniJavaParser::ClassDeclContext * /*ctx*/) override { }

  virtual void enterMethodDecl(MiniJavaParser::MethodDeclContext * /*ctx*/) override { }
  virtual void exitMethodDecl(MiniJavaParser::MethodDeclContext * /*ctx*/) override { }

  virtual void enterMethodBody(MiniJavaParser::MethodBodyContext * /*ctx*/) override { }
  virtual void exitMethodBody(MiniJavaParser::MethodBodyContext * /*ctx*/) override { }

  virtual void enterMethodReturn(MiniJavaParser::MethodReturnContext * /*ctx*/) override { }
  virtual void exitMethodReturn(MiniJavaParser::MethodReturnContext * /*ctx*/) override { }

  virtual void enterMethodCall(MiniJavaParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(MiniJavaParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterMethodParams(MiniJavaParser::MethodParamsContext * /*ctx*/) override { }
  virtual void exitMethodParams(MiniJavaParser::MethodParamsContext * /*ctx*/) override { }

  virtual void enterMethodType(MiniJavaParser::MethodTypeContext * /*ctx*/) override { }
  virtual void exitMethodType(MiniJavaParser::MethodTypeContext * /*ctx*/) override { }

  virtual void enterVarType(MiniJavaParser::VarTypeContext * /*ctx*/) override { }
  virtual void exitVarType(MiniJavaParser::VarTypeContext * /*ctx*/) override { }

  virtual void enterVarDecl(MiniJavaParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(MiniJavaParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext * /*ctx*/) override { }
  virtual void exitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext * /*ctx*/) override { }

  virtual void enterStatement(MiniJavaParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(MiniJavaParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression(MiniJavaParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(MiniJavaParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpList(MiniJavaParser::ExpListContext * /*ctx*/) override { }
  virtual void exitExpList(MiniJavaParser::ExpListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

