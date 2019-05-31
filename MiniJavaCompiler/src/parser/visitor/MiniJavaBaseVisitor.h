#pragma once

#include "antlr4-runtime.h"
#include "MiniJavaVisitor.h"

/**
 * This class provides an empty implementation of MiniJavaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MiniJavaBaseVisitor : public MiniJavaVisitor {
public:

  virtual antlrcpp::Any visitProg(MiniJavaParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMainClass(MiniJavaParser::MainClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassDecl(MiniJavaParser::ClassDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDecl(MiniJavaParser::MethodDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodBody(MiniJavaParser::MethodBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodReturn(MiniJavaParser::MethodReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParams(MiniJavaParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(MiniJavaParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(MiniJavaParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(MiniJavaParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpList(MiniJavaParser::ExpListContext *ctx) override {
    return visitChildren(ctx);
  }


};

