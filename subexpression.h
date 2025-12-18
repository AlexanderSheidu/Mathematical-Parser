// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp. 

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right, Expression* e3, Expression* e4);
    SubExpression(Expression* left, Expression* right, Expression* e3);
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
    Expression* e3;
    Expression* e4;
};    