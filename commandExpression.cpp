#include "commandExpression.h"
#include "Commands.h"


commandExpression::commandExpression(Commands *command) {
    commandExpression::command = command;
}

double commandExpression::calculate(){
    return this->command->execute();
}

Commands* commandExpression::getCommand() {
    return command;
}
