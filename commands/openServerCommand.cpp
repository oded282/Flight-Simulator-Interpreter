#include <algorithm>
#include "openServerCommand.h"
#include "../connection/dataReaderServer.h"
#include "../utils/ShuntingYard.h"

//set the command.
void openServerCommand::setCommand(string& str){
    vector<string> par = getParameters(str);
    this->readerServer = new dataReaderServer((int)shuntingYard->shuntingYard(par[0])->calculate(),
                                  (int)shuntingYard->shuntingYard(par[1])->calculate(),
                                  varTable);
}
//open server.
int openServerCommand::execute() {
    readerServer->openServer();
}
