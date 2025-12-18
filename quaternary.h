// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the Quaternary class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left and right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning either of the three numbers involved in the expression of the values of the four 
// subexpressions.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

class Quaternary: public SubExpression {
public:
    Quaternary(Expression* left, Expression* right, Expression* e3, Expression* e4): SubExpression(left, right, e3, e4) {
    }
    double evaluate() {
        if (left->evaluate() < 0) return right->evaluate();
        if (left->evaluate() == 0) 
            return e3->evaluate();
        else 
            return e4->evaluate();
    }
};