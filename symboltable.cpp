// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

// Declare all imports used

#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"

// Use this function for getting the variable and parsing it

void SymbolTable::insert(string variable, double value) {
    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

// This function is used to look up and variables and strings to parse
double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;
    return -1;
}

// Function that is used to clear any of the elements
void SymbolTable::clear() {
    elements.clear();
}

// Boolean function to check if it contains the name and symbol, if true return 1
// else return 0 (false).
bool SymbolTable::contains(string name) {
    for (Symbol s : elements)
        if (s.variable == name)
            return 1;

    return 0;
}

