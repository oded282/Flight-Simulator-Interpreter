#include <sstream>
#include "AssignCommand.h"
#include "../expressions/Number.h"
#include "../data/symbolTable.h"
#include "../utils/ShuntingYard.h"
#include "../data/mapCommand.h"

AssignCommand::AssignCommand(connectCommand *c, mapCommand *commandTable, symbolTable *varTable,
                             ShuntingYard *shuntingYard) : Commands(commandTable, varTable, shuntingYard) {
    AssignCommand::connect = c;
}

void AssignCommand::setFriends(VarCommand *var) {
    vector<VarCommand *>::iterator it;
    for (it = var->getFriends().begin(); it != var->getFriends().end(); it++) {
        (*it)->setValue(var->getValue());
    }
}

int AssignCommand::execute() {
    string str;
    value = new Number(right->calculate());
    colector.push_back(value);
    left->setValue(value);
    str = "set " + left->getSentence() + " " + to_string(value->calculate()) + "\r\n";
    //connect->getClient()->communicationClient(str);
    return 1;
}

void AssignCommand::setCommand(string &str) {
    vector<string> vector = getAssinParam(str);
    right = shuntingYard->shuntingYard(vector[1]);
    left = varTable->getVar(vector[0]);
    setFriends(left);
}

void AssignCommand::setConnectCommand(connectCommand *c) {
    AssignCommand::connect = c;
}