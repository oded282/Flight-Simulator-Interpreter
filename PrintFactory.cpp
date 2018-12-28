
#include "PrintFactory.h"
#include "expressions/commandExpression.h"
#include "commands/PrintCommand.h"


PrintFactory:: PrintFactory(ConditionCounter* counter,Parser* parser,
        mapCommand* commandTable, symbolTable* varTable, ShuntingYard* shuntingYard) :
        Commands( commandTable, varTable,shuntingYard){
   PrintFactory::counter = counter;
   PrintFactory::parser = parser;
}

/*
 * This func creates new sleep command and add it to the map.
 */
void PrintFactory::setCommand(string& str){
   commandExpression* newPrint = new commandExpression (new PrintCommand(commandTable ,varTable,shuntingYard));
   commandTable->addCommand("print" + to_string(getCounter()->getCount()),newPrint);
   newPrint->getCommand()->setCommand(str);
}

int PrintFactory::execute(){

}

ConditionCounter* PrintFactory::getCounter()  {
   return counter;
}