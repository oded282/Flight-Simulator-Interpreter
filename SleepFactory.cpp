
#include "SleepFactory.h"
#include "commands/sleepCommand.h"


SleepFactory:: SleepFactory(ConditionCounter* counter,Parser* parser,mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard) : Commands( commandTable, varTable,shuntingYard){
    SleepFactory::counter = counter;
    SleepFactory::parser = parser;
}

/**
 * Create new sleep command and add it to the map.
 */
void SleepFactory::setCommand(string& str){
    commandExpression* newPrint = new commandExpression (new sleepCommand(commandTable ,varTable,shuntingYard));
    commandTable->addCommand("sleep" + to_string(getCounter()->getCount()),newPrint);
    newPrint->getCommand()->setCommand(str);
}

int SleepFactory::execute(){

}

ConditionCounter* SleepFactory::getCounter()  {
    return counter;
}