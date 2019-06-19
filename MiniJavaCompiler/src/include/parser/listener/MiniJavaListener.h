/*
*	Jefferson do Nascimento Amará (201765125C)
*	Luis Augusto Toscano Guimarães (201365165AC)
*/
#pragma once

#include "antlr4/antlr4-runtime.h"
#include "parser/MiniJavaParser.h"

/**
 * This interface defines an abstract listener for a parse tree produced by MiniJavaParser.
 */
class  MiniJavaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(MiniJavaParser::ProgContext *ctx) = 0;
  virtual void exitProg(MiniJavaParser::ProgContext *ctx) = 0;

  virtual void enterMainClass(MiniJavaParser::MainClassContext *ctx) = 0;
  virtual void exitMainClass(MiniJavaParser::MainClassContext *ctx) = 0;

  virtual void enterClassDecl(MiniJavaParser::ClassDeclContext *ctx) = 0;
  virtual void exitClassDecl(MiniJavaParser::ClassDeclContext *ctx) = 0;

  virtual void enterMethodDecl(MiniJavaParser::MethodDeclContext *ctx) = 0;
  virtual void exitMethodDecl(MiniJavaParser::MethodDeclContext *ctx) = 0;

  virtual void enterMethodBody(MiniJavaParser::MethodBodyContext *ctx) = 0;
  virtual void exitMethodBody(MiniJavaParser::MethodBodyContext *ctx) = 0;

  virtual void enterMethodReturn(MiniJavaParser::MethodReturnContext *ctx) = 0;
  virtual void exitMethodReturn(MiniJavaParser::MethodReturnContext *ctx) = 0;

  virtual void enterMethodCall(MiniJavaParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(MiniJavaParser::MethodCallContext *ctx) = 0;

  virtual void enterMethodParams(MiniJavaParser::MethodParamsContext *ctx) = 0;
  virtual void exitMethodParams(MiniJavaParser::MethodParamsContext *ctx) = 0;

  virtual void enterMethodType(MiniJavaParser::MethodTypeContext *ctx) = 0;
  virtual void exitMethodType(MiniJavaParser::MethodTypeContext *ctx) = 0;

  virtual void enterVarType(MiniJavaParser::VarTypeContext *ctx) = 0;
  virtual void exitVarType(MiniJavaParser::VarTypeContext *ctx) = 0;

  virtual void enterVarDecl(MiniJavaParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(MiniJavaParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext *ctx) = 0;
  virtual void exitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext *ctx) = 0;

  virtual void enterStatement(MiniJavaParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MiniJavaParser::StatementContext *ctx) = 0;

  virtual void enterExpression(MiniJavaParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MiniJavaParser::ExpressionContext *ctx) = 0;

  virtual void enterExpList(MiniJavaParser::ExpListContext *ctx) = 0;
  virtual void exitExpList(MiniJavaParser::ExpListContext *ctx) = 0;


};

