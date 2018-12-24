#include <iostream>
#include "PrintCommand.h"



int PrintCommand::execute() {
    cout << str << endl;
    return 1;
}

void PrintCommand::setCommand(string& str) {
    vector<string> result = cleanSpace(str);

    vector<string>::iterator it;
    for (it = result.begin() ; it != result.end(); ++it) {
        this->str += *it;
    }
}