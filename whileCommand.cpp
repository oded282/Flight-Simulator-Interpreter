

#include "whileCommand.h"


int whileCommand:: execute(){
    int i = 0;
    while(ConditionParser::execute()){
        commands[i].execute();
    }
    return 1;
}

void whileCommand::setCommand(string& str){
    ConditionParser::setCommand(str);
}

void whileCommand::setParser(Parser *p) {
    whileCommand::parser = p;
}
