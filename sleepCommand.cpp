#include <unistd.h>
#include "sleepCommand.h"
#include "ShuntingYard.h"


void sleepCommand::setCommand(string& str) {
    vector<string> result = getParameters(str);

     time = (int)ShuntingYard::shuntingYard(result[1])->calculate();
}

int sleepCommand::execute() {
    sleep((unsigned)time/1000);
    return 1;
}



