
#include "ifCommand.h"

int ifCommand::execute() {
    if(ConditionParser::execute()){
        commands = parser->doParser(numberOfWhileCommands());
    }
    if (ConditionParser::execute()) {
        for(commandExpression* val: commands){
            val->calculate();
        }
    }
    return 1;
}

void ifCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str ,2);
    ConditionParser::setCommand(str);
}