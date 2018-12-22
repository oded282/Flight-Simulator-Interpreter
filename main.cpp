
#include <sstream>
#include <stack>
#include "dataReaderServer.h"

using namespace std;


int main(int argc, char* argv[]){


    dataReaderServer server(5400 , 10);
    server.openServer();

}
