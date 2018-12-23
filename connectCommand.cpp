#include "connectCommand.h"
#include "openClient.h"
#include "ShuntingYard.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <cstring>

#define EXIT_FAILURE 1

using namespace std;


char* stringToCharPointer (string str){
    char *newStr = new char[str.size() + 1];
    copy(str.begin() , str.end() , newStr);
    newStr[str.size()] = '\0';
    return newStr;
}


void connectCommand::setCommand(string& str) {

    vector<string> result = getParameters(str);

    char * ip = stringToCharPointer(result[1]);
    string expression = shuntingYard->fromVectorToString(result , 2 , (unsigned)result.size());
    int port = (int)shuntingYard->shuntingYard(expression)->calculate();

    client = new openClient(ip, port);

}

int connectCommand::execute() {
    client->openSocketClient();
    return 1;
}



//int main(){
//
//    string str = "connect 10.13.15.9 -50 + 9 * 6 -8/16 ";
//    connectCommand command(nullptr , nullptr);
//    command.setCommand(str);
//}
