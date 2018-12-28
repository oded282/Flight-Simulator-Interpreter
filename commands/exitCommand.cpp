#include <unistd.h>
#include <iostream>
#include "exitCommand.h"

extern bool isStop;



void exitCommand::setCommand(string &str) {

}

//destruct all the resource
int exitCommand::execute() {
    isStop = false;
    sleep(3);
    return 1;

}


