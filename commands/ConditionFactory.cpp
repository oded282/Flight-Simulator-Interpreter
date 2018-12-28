
#include "ConditionFactory.h"
#include "ifCommand.h"
#include "whileCommand.h"

/*
 * This command creates new condition command.
 * there are two cases create if command or while command int our prog
 * so far, rap them with the command adapter and add them to the map.
 */

void ConditionFactory::setCommand(string& str){
    if(str.find("if") != string::npos){
        commandExpression* ifCom = new commandExpression(new ifCommand(parser,commandTable,varTable,shuntingYard));
        commandTable->addCommand("if" + to_string(getCounter()->getCount()),ifCom);
        ifCom->getCommand()->setCommand(str);
    }else {
        commandExpression* whileCom = new commandExpression(new whileCommand(parser,commandTable,varTable,shuntingYard));
        commandTable->addCommand("while" + to_string(getCounter()->getCount()),whileCom);
        whileCom->getCommand()->setCommand(str);
    }
}

int ConditionFactory::execute(){

}
/*
 * Return the counter of all commands.
 */
ConditionCounter* ConditionFactory::getCounter()  {
    return counter;
}
