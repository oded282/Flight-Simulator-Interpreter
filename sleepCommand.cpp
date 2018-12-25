#include <unistd.h>
#include "sleepCommand.h"
#include "ShuntingYard.h"


void sleepCommand::setCommand(string& str) {
    str = str.substr(5, str.size());
    cleanWhiteSpaces(str);
    time = (int)shuntingYard->shuntingYard(str)->calculate();
}

int sleepCommand::execute() {
    sleep((unsigned)time/1000);
    return 1;
}



