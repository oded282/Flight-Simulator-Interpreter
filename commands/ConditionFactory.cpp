
#include "ConditionFactory.h"
#include "ifCommand.h"
#include "whileCommand.h"



void ConditionFactory::setCommand(string& str){
    if(str.find("if") != string::npos){
        commandExpression* ifCom = new commandExpression(new whileCommand(parser,commandTable,varTable,shuntingYard));
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

ConditionCounter* ConditionFactory::getCounter()  {
    return counter;
}
