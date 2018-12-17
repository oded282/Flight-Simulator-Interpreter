#include <algorithm>
#include "openDataServer.h"



bool isNumber (char c){
        return c <= '9' && c >= '0';
}

bool legalExpression1(char c){
    return c == ',';
}

bool legalExpression2(char c1 , char c2 , char c3){
    return isNumber(c1) && c2 == ' ' && isNumber(c3);
}


bool openDataServer::checkLegality(string par) {
    string parameter1 , parameter2;
    bool flag = false;
    // delete the name of the commend.
    for (int j = 0; j < par.size(); j++) {
        if (par[j] == ' '){
            par = par.substr((unsigned)j+1 , par.size()-1);
            break;
        }
    }

    for (int i = 0; i < par.size() - 1; i++){
        if (legalExpression1(par[i]) || legalExpression2(par[i-1] , par[i] , par[i+1])){
            parameter1 = par.substr(0 , (unsigned)i-1);
            parameter2 = par.substr((unsigned)i+1 , par.size()-1);
            flag = true;
            break;
        }
    }
    if (!flag){
        return false;
    }
    // clean space.
    cleanWhiteSpaces(parameter1);
    cleanWhiteSpaces(parameter2);

    // call to polish.

}
int main(){
    openDataServer* openDataServer1;
    string string1("bined 5 * 3  2");
    string string2(" bined 5 * 3, - 2");
    string string3("  bined 5 * 3 ,- 2   ");
    string string4("bined 5 * (3 -2) , 3 + -1");
    string string5("bined (5 + 3) - 2");
    if(openDataServer1->checkLegality(string1)){
        printf("bad1\n");
    }
    if(openDataServer1->checkLegality(string2)){
        printf("good1\n");
    }
    if(openDataServer1->checkLegality(string3)){
        printf("good2\n");
    }    if(openDataServer1->checkLegality(string4)){
        printf("good3\n");
    }
    if(openDataServer1->checkLegality(string5)){
        printf("bad2\n");
    }


}