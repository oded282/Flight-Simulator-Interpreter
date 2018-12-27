#include <iostream>
#include "PrintCommand.h"
#include "../data/symbolTable.h"


int PrintCommand::execute() {
    string result;
    string::iterator itr = str.begin();
    while (itr != str.end()){
        if (*itr == '\"'){
            itr++;
            string temp;
            while (*itr != '\"'){
                temp += *itr;
                itr++;
            }
            result += temp;
            itr++;
        }else {
            string temp;
            while (*itr != '\"' && itr != str.end()){
                temp += *itr;
                itr++;
            }
            cleanSpace(temp);
            if (this->varTable->getVar(temp) == nullptr){
                throw "Invalid Input!";
            }
            temp = to_string(this->varTable->getVarValue(temp)->calculate());
            result += temp;
        }
    }
    cout << str << endl;
    return 1;
}

void PrintCommand::setCommand(string& str) {
    str = str.substr(6, str.size());
    this->str = str;
}