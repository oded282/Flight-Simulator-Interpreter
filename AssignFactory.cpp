
#include <sys/socket.h>
#include "AssignFactory.h"
#include "expressions/commandExpression.h"
#include "commands/AssignCommand.h"


AssignFactory::AssignFactory(ConditionCounter *counter, Parser *parser, connectCommand *connect,
                             mapCommand *commandTable,
                             symbolTable *varTable, ShuntingYard *shuntingYard) : Commands(commandTable, varTable,
                                                                                           shuntingYard) {
    AssignFactory::counter = counter;
    AssignFactory::connect = connect;
    AssignFactory::parser = parser;
}

void AssignFactory::setCommand(string &str) {
    commandExpression *newAssign = new commandExpression(
            new AssignCommand(connect, commandTable, varTable, shuntingYard));
    commandTable->addCommand("=" + to_string(getCounter()->getCount()), newAssign);
    newAssign->getCommand()->setCommand(str);
}

int AssignFactory::execute() {

}

ConditionCounter *AssignFactory::getCounter() {
    return counter;
}