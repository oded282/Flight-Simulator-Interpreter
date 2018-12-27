
#include "whileCommand.h"


int whileCommand::execute() {
    if(ConditionParser::execute()){
        commands = parser->doParser(ConditionParser::numberOfWhileCommands(),true);
    }else{
        if(isParsedNeeded) {
            parser->setIndex((int) parser->getIndex() + ConditionParser::numberOfWhileCommands());
            isParsedNeeded = false;
        }
    }
    while (ConditionParser::execute()) {
        for(commandExpression* val: commands){
            val->calculate();
        }
    }
    return 1;
}

void whileCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str, 5);
    ConditionParser::setCommand(str);
}
