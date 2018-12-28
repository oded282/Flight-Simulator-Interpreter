
#include "whileCommand.h"

/*
 * That func parse all data inside the loop, and execute
 * the commands if the condition is true;
 */
int whileCommand::execute() {
    if(ConditionParser::execute()){ // parse all commands and execute the condition once.
        commands = parser->doParser(ConditionParser::numberOfWhileCommands(),true);
        isParsedNeeded = false;
    }else{
        if(isParsedNeeded) { // parse all commands but wont execute the commands.
            parser->setIndex((int) parser->getIndex() + ConditionParser::numberOfWhileCommands());
            isParsedNeeded = false;
        }
    }
    while (ConditionParser::execute()) { // execute the command while the condition still true.
        for(commandExpression* val: commands){
            val->calculate();
        }
    }
    return 1;
}

/*
 * This func sets the while command, clean the string read from user/file
 * and initial the condition who is the 'father' of this command.
 */
void whileCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str, 5);
    ConditionParser::setCommand(str);
}
