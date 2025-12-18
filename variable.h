// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the Variable class. The variable is represented by its
// name, which the construcor initializes. Because this class is a subclass of Operand which in turn is 
// a subclass of Expression, it must implement the function evaluate, whose body is defined in variable.cpp.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

#include <iostream>
using namespace std;
class Variable: public Operand {
public:
    Variable(string name) {
        if (name[0] == '_') {
            cout << "Variable name can not start with _" << endl;
		    exit(1);
        }

        this->name = name;
    }
    double evaluate();
private:
    string name;
};