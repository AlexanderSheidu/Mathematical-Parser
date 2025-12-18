// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the definition of the Operand class, which is a subclass of Expression. It is an
// abstract class because it does not implement the evaluate function. It contains one static (class)
// function parse that parses an operand as either a literal or variable.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

class Operand: public Expression {
public:
    static Expression* parse(stringstream& in);
};
