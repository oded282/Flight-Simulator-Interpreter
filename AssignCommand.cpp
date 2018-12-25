
#include <sstream>
#include "AssignCommand.h"
#include "Number.h"
#include "symbolTable.h"
#include "ShuntingYard.h"
#include "mapCommand.h"

AssignCommand:: AssignCommand(connectCommand* c ,mapCommand* commandTable, symbolTable* varTable ,
        ShuntingYard* shuntingYard):Commands(commandTable,varTable,shuntingYard){
    AssignCommand::connect = c;
}

void AssignCommand::setFriends(Var* var){
    vector<Var*> ::iterator it;
    for(it = var->getFriends().begin(); it != var->getFriends().end(); it++){
        (*it)->setValue(var->getValue());
    }
}


int AssignCommand:: execute(){
    string str;
    str = "set " + left->getSentence() + " " + to_string(right->calculate()) + "\r\n" ; //TODO need to check how to send the string of the expression(right)
    connect->getClient()->sendCommand(connect->stringToCharPointer(str));
    return 1;
}

void AssignCommand::setCommand(string& str) {
    vector<string> vector = getAssinParam(str);
    right = shuntingYard->shuntingYard(vector[1]);
    left = varTable->getVar(vector[0]);
    left->setValue(right);
    setFriends(left);
}

void AssignCommand::setConnectCommand(connectCommand *c) {
    AssignCommand::connect = c;
}