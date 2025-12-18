// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function contained in The Variable class. The evaluate function 
// looks up te value of a variable in the symbol table and returns that value.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

// Declare all of the imports being used

#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"
#include "varexception.h"

extern SymbolTable symbolTable;

// Function of type double, used to look up the name and to 
// throw the exception found
double Variable::evaluate() {
    int r = symbolTable.lookUp(name);
    if (r == -1) 
        throw VarException("Variable is not initialized");

    return (double) r;
}