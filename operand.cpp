// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function parseName contained in the Operand class. That function
// parses the next token. When the next non-whitespace character is a digit, it assumes a literal is next. 
// When the next character is a left parenthesis, a recursive call is made to parse the subexpression.
// Otherwise the next token is assumed to a variable. No checks are made to ensure correct syntax.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

// Declare all of the imports
#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

/* Check if there is a digit, or parenthases
* and begin the parsing process.
*/
Expression* Operand::parse(stringstream& in) {
    char paren;
    double value;

    in >> ws;
    if (isdigit(in.peek())) {
        in >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (in.peek() == '(') {
        in >> paren;
        return SubExpression::parse(in);
    }
    if (in.peek() == ')') {
        in >> paren;
        return nullptr;
    }    
    else
        return new Variable(parseName(in));
    return 0;
}