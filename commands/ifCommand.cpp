
#include "ifCommand.h"

int ifCommand::execute() {
    if(ConditionParser::execute()){
        commands = parser->doParser(numberOfWhileCommands(),true);
    }else{
        commands = parser->doParser(numberOfWhileCommands(),false);
    }
    return 1;
}

void ifCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str, 2);
    ConditionParser::setCommand(str);
    //commands = parser->doParser(numberOfWhileCommands(),false);
}