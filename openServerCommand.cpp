#include <algorithm>
#include "openServerCommand.h"
#include "dataReaderServer.h"

int openServerCommand::execute(string str){

    vector<string> par = getParameters(str);

    dataReaderServer readerServer((int)shuntingYard(par[0])->calculate(),
            (int)shuntingYard(par[1])->calculate());

    readerServer.openServer();
}



int main(){
   // openServerCommand* openDataServer1;
   // string string1("bined 5 * 3  2");
   // string string2(" bined 5 * 3, - 2");
   // string string3("  bined 5 * 3 ,- 2   ");
   // string string4("bined 5 * (3 -2) , 3 + -1");
   // string string5("bined (5 + 3) - 2");
   // if(openDataServer1->checkLegality(string1)){
   //     printf("bad1\n");
   // }
   // if(openDataServer1->checkLegality(string2)){
   //     printf("good1\n");
   // }
   // if(openDataServer1->checkLegality(string3)){
   //     printf("good2\n");
   // }    if(openDataServer1->checkLegality(string4)){
   //     printf("good3\n");
   // }
   // if(openDataServer1->checkLegality(string5)){
   //     printf("bad2\n");
   // }


}