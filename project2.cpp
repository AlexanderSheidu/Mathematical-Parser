// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the main function for the project 2 code. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "varexception.h"

// Get the SymbolTable
SymbolTable symbolTable;

// Call the parseAssignments function
void parseAssignments(stringstream& in);

// The main method
int main() {
	/*Use ifstream to read from the input.txt file
	* get necessary exceptions
	*/
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open())) {
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}
	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in); 
		in >> paren;
		cout << line << " ";
		symbolTable.clear();
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		} catch (string message) {
			cout << message << endl;
		} catch (VarException ex) {
			cout << ex.what() << endl;
		}
	}
	system("pause");
	return 0;
}

/* Parse the input file, and check if there are any errors
* also make sure the delimeters are intact
*/
void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    double value;
    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
		
		if (symbolTable.contains(variable)) 
		    throw VarException("variable initialized more than once");
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
   
