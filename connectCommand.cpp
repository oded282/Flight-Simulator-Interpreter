#include "connectCommand.h"
#include "openClient.h"
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


connectCommand::connectCommand(int port, char* ip) : Commands(commandTable, varTable) {
    connectCommand::port = port;
    connectCommand::ip = ip;
}

int connectCommand::execute(string str) {

    vector<string> result = getParameters(str);

    char * c = stringToCharPointer(result[1]);
    string expression = ShuntingYard::fromVectorToString(result , 2 , result.size());
    int x = (int)shuntingYard(expression)->calculate();

    openClient client(c, x);

    client.openSocketClient();

}

int main(){

    string str = "connect 10.13.15.9 -50 + 9 * 6 -8/16 ";
    connectCommand command(nullptr , nullptr);
    command.execute(str);




}
