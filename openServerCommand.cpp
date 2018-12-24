#include <algorithm>
#include "openServerCommand.h"
#include "dataReaderServer.h"
#include "ShuntingYard.h"

void openServerCommand::setCommand(string& str){
    vector<string> par = getParameters(str);
    this->readerServer = new dataReaderServer((int)shuntingYard->shuntingYard(par[0])->calculate(),
                                  (int)shuntingYard->shuntingYard(par[1])->calculate(),
                                  varTable);
}
int openServerCommand::execute() {

    readerServer->openServer();

}
