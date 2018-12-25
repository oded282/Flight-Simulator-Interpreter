#include <iostream>
#include "PrintCommand.h"



int PrintCommand::execute() {
    cout << str << endl;
    return 1;
}

void PrintCommand::setCommand(string& str) {
    str = str.substr(5, str.size());
    cleanWhiteSpaces(str);
    this->str = str;
}