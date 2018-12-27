#include "commandExpression.h"
#include "../commands/Commands.h"


commandExpression::commandExpression(Commands *command) {
    commandExpression::command = command;
}

float commandExpression::calculate(){
    return this->command->execute();
}

Commands* commandExpression::getCommand() {
    return command;
}
