#include <algorithm>
#include "openServerCommand.h"
#include "dataReaderServer.h"
#include "ShuntingYard.h"

void openServerCommand::setCommand(string& str){
    vector<string> par = getParameters(str);
    this->readerServer = new dataReaderServer((int)shuntingYard->shuntingYard(par[0])->calculate(),
                                  (int)shuntingYard->shuntingYard(par[1])->calculate());
}
int openServerCommand::execute() {

    readerServer->openServer();

}




//int main(){
   // openServerCommand* openDataServer1;
   // string string1("bined 5 * 3  2");
   // string string2(" bined 5 * 3, - 2");
   // string string3("  bined 5 * 3 ,- 2   ");
   // string string4("bined 5 * (3 -2) , 3 + -1");
   // string string5("bined (5 + 3) - 2");

//}