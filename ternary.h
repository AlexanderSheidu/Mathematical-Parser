// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the Ternary class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left and right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the true part or the false part of the values of the three subexpressions.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

class Ternary: public SubExpression {
public:
    Ternary(Expression* left, Expression* right, Expression* e3): SubExpression(left, right, e3) {
    }
    double evaluate() {
       return (int) left->evaluate() ? right->evaluate() : e3->evaluate();
    }
};