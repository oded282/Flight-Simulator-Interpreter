#include <algorithm>
#include "openServerCommand.h"
#include "dataReaderServer.h"
#include "ShuntingYard.h"

int openServerCommand::execute(string str){

    vector<string> par = getParameters(str);

    dataReaderServer readerServer((int)ShuntingYard::shuntingYard(par[0])->calculate(),
            (int)ShuntingYard::shuntingYard(par[1])->calculate());

    readerServer.openServer();
}



//int main(){
   // openServerCommand* openDataServer1;
   // string string1("bined 5 * 3  2");
   // string string2(" bined 5 * 3, - 2");
   // string string3("  bined 5 * 3 ,- 2   ");
   // string string4("bined 5 * (3 -2) , 3 + -1");
   // string string5("bined (5 + 3) - 2");

//}