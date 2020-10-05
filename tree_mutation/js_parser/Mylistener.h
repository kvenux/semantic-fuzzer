#pragma once


#include "antlr4-runtime.h"
#include "antlr4-common.h"
#include "ECMAScriptParser.h"
#include <iostream>
using namespace std;


class  MyListener : public antlr4::tree::ParseTreeListener {
public:
    virtual void visitTerminal(antlr4::tree::TerminalNode *node) = 0;
};