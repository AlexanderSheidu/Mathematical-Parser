// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

// Declare all of the imports being used

#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "remain.h"
#include "expo.h"
#include "min.h"
#include "max.h"
#include "avg.h"
#include "neg.h"
#include "ternary.h"
#include "quaternary.h"

// Constructor to get the instance variables used
SubExpression::SubExpression(Expression* left, Expression* right, Expression* e3, Expression* e4) {
    this->left = left;
    this->right = right;
    this->e3 = e3;
    this->e4 = e4;    
}

// Another constructor to initialize the values of the instance variables
SubExpression::SubExpression(Expression* left, Expression* right, Expression* e3): SubExpression(left, right, e3, nullptr) {}
SubExpression::SubExpression(Expression* left, Expression* right): SubExpression(left, right, nullptr, nullptr) {}
SubExpression::SubExpression(Expression* left): SubExpression(left, nullptr, nullptr, nullptr) {}

// Begin parsing and initializing the instance variables
Expression* SubExpression::parse(stringstream& in) {
    Expression* left = nullptr;
    Expression* right = nullptr;
    Expression* e3 = nullptr;
    Expression* e4 = nullptr;
    char operation, paren;
    
    left = Operand::parse(in);
    in >> operation;
    
    if (operation != '~')
        right = Operand::parse(in);

    if (operation == '?') {
        e3 = Operand::parse(in);
    } else if (operation == '#') {
        e3 = Operand::parse(in);
        e4 = Operand::parse(in);
    }

    // Get the different cases, for appropriate signs used
    in >> paren;
    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);    
        case '/':
            return new Divide(left, right);   
        case '%':
            return new Remain(left, right);  
        case '^':
            return new Expo(left, right);  
        case '<':
            return new Min(left, right); 
        case '>':
            return new Max(left, right);  
        case '&':
            return new Avg(left, right);  
        case '~':
            return new Neg(left);  
        case '?':
            return new Ternary(left, right, e3);    
        case '#':
            return new Quaternary(left, right, e3, e4);                                                                                                        
    }
    return 0;
}
        