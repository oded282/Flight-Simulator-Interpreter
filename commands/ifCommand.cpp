
#include "ifCommand.h"


/*
 * This func check if the condition of the if statement
 * is valid and if so it parse all the info inside the statement.
 */
int ifCommand::execute() {
    if (ConditionParser::execute()) { // case the condition is true;
        commands = parser->doParser(numberOfWhileCommands(), true);
    } else { // case the condition is false just iterate the parser without execution.
        commands = parser->doParser(numberOfWhileCommands(), false);
    }
    return 1;
}

/*
 * This func clean the command and set the condition.
 */
void ifCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str, 2);
    ConditionParser::setCommand(str);
}
