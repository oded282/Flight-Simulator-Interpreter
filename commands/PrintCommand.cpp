#include <iostream>
#include "PrintCommand.h"
#include "../data/symbolTable.h"

/*
 * This func check the string initialized and print it.
 */
int PrintCommand::execute() {
    string result;
    string::iterator itr = str.begin();
    while (itr != str.end()){ // check all the string and copy it to temp.
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
            if (this->varTable->getVar(temp) == nullptr){ // invalid string.
                throw "Invalid Input!";
            }
            temp = to_string(this->varTable->getVarValue(temp)->calculate());
            result += temp;
        }
    }
    cout << result << endl;
    return 1;
}

/*
 * This func cleans the string from unnecessary info
 * and initial the string needs to be print.
 */
void PrintCommand::setCommand(string& str) {
    str = str.substr(6, str.size());
    this->str = str;
}