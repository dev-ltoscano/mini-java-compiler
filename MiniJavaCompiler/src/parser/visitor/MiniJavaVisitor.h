#pragma once

#include "antlr4-runtime.h"
#include "../MiniJavaParser.h"

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MiniJavaParser.
 */
class  MiniJavaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MiniJavaParser.
   */
    virtual antlrcpp::Any visitProg(MiniJavaParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitMainClass(MiniJavaParser::MainClassContext *context) = 0;

    virtual antlrcpp::Any visitClassDecl(MiniJavaParser::ClassDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodDecl(MiniJavaParser::MethodDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodBody(MiniJavaParser::MethodBodyContext *context) = 0;

    virtual antlrcpp::Any visitMethodReturn(MiniJavaParser::MethodReturnContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(MiniJavaParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitParams(MiniJavaParser::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitType(MiniJavaParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(MiniJavaParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclAndAtt(MiniJavaParser::VarDeclAndAttContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MiniJavaParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(MiniJavaParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpList(MiniJavaParser::ExpListContext *context) = 0;


};

