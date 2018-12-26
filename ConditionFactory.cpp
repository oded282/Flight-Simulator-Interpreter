
#include "ConditionFactory.h"
#include "ifCommand.h"
#include "whileCommand.h"


commandExpression* ConditionFactory::creatCondition(string str){
    if(str.find("if") != string::npos){
        commandExpression* ifCom = new commandExpression(new whileCommand(parser,commandTable,varTable,shuntingYard));
        commandTable->addCommand("if",ifCom);
        ifCom->getCommand()->setCommand(str);
    }else if(str.find("while") != string::npos){
        commandExpression* whileCom = new commandExpression(new whileCommand(parser,commandTable,varTable,shuntingYard));
        commandTable->addCommand("while",whileCom);
        whileCom->getCommand()->setCommand(str);
        return whileCom;
    }


}