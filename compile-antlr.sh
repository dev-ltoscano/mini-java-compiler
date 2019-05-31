#!/bin/bash

cd antlr4/4.7.2
cmake .
make
cp dist/libantlr4-runtime.a ../../MiniJavaCompiler/lib/Linux/x64/libantlr4-runtime.a
cp dist/libantlr4-runtime.so.4.7.2 ../../MiniJavaCompiler/lib/Linux/x64/libantlr4-runtime.so.4.7.2