

#include "whileCommand.h"


int whileCommand:: execute(){
    int i = 0;
    while(ConditionParser::execute()){
        commands[i].execute();
    }
}
