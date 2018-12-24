
#include <sstream>
#include "AssignCommand.h"
#include "Number.h"
#include "symbolTable.h"
#include "ShuntingYard.h"
#include "mapCommand.h"

AssignCommand:: AssignCommand(mapCommand* commandTable, symbolTable* varTable , ShuntingYard* shuntingYard,connectCommand* connect):Commands(commandTable,varTable,shuntingYard){
    AssignCommand::connect = connect;
}


int AssignCommand:: execute(){
    std::stringstream str;
    str << "set " << left->getSentence() << " " << right <<"\r\n" ; //TODO need to check how to send the string of the expression(right)
    connect->getClient()->sendCommand(connect->stringToCharPointer(str.str()));
}

void AssignCommand::setCommand(string& str) {
    vector<string> vector = getParameters(str);
    left = varTable->getVar(str);
    right = shuntingYard->shuntingYard(vector[2]);
}
