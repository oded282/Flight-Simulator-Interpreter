#include <unistd.h>
#include "sleepCommand.h"
#include "../utils/ShuntingYard.h"

/*
 * Cleans the unnecessary inforamtion and initial the func.
 */
void sleepCommand::setCommand(string& str) {
    str = str.substr(5, str.size());
    cleanWhiteSpaces(str);
    time = (int)shuntingYard->shuntingYard(str)->calculate();
}

/*
 * This func execute the sleep method with the params initialed by ctor.
 */
int sleepCommand::execute() {
    sleep((unsigned)time/1000);
    return 1;
}



