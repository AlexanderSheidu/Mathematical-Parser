// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function parseName. That function consumes all alphanumeric 
// characters until the next whitespace and returns the name that those characters form.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

#include "parse.h"

/*Use the .h file to parse the code and check 
* if it is alphanumeric or has underscores,
* as well as initializing and returning the 
* name variable
*/


string parseName(stringstream& in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()) || in.peek() == '_') {
        in >> alnum;
        name += alnum;
    }
    return name;
}