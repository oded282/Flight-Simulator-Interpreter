#include <unistd.h>
#include "sleepCommand.h"
#include "ShuntingYard.h"


int sleepCommand::execute(string str) {
    vector<string> result = getParameters(str);

    int s = (int)ShuntingYard::shuntingYard(result[1])->calculate();
    usleep((__useconds_t)((s*1000)/0.001));
    return 1;
}


