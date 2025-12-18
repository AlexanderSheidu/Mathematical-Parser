#include <string>
using namespace std;

// This class is used to find the variable exception, 
// it throws the exception and puts the error message
// on display

/*
* Alexander Sheidu
* Project 2
* Date: 6/18/2024
* Course: CMSC 330/6380
*/

class VarException : public exception {
    public:
        VarException(string msg) : msg(msg) {}
        const char* what() const throw() {
            return msg.c_str();
        }

    private:
        string msg;
};
