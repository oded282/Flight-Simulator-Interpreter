
#include <sstream>
#include <stack>
#include "dataReaderServer.h"
#include "Number.h"

using namespace std;


int main(int argc, char* argv[]){

    symbolTable* symbolMap = new symbolTable();

    Var* v1 = new Var("alt1" , new Number(0) , "/instrumentation/airspeed-indicator/indicated-speed-kt" ,
            nullptr , symbolMap ,nullptr);
    Var* v2 = new Var("alt2" , new Number(0) , "/instrumentation/altimeter/pressure-alt-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v3 = new Var("alt3" , new Number(0) , "/instrumentation/attitude-indicator/indicated-pitch-deg" ,
                      nullptr , symbolMap ,nullptr);
    Var* v4 = new Var("alt4" , new Number(0) , "/instrumentation/attitude-indicator/internal-pitch-deg" ,
                      nullptr , symbolMap ,nullptr);
    Var* v5 = new Var("alt5" , new Number(0) , "/instrumentation/encoder/indicated-altitude-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v6 = new Var("alt6" , new Number(0) , "/instrumentation/gps/indicated-altitude-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v7 = new Var("alt7" , new Number(0) , "/instrumentation/gps/indicated-vertical-speed" ,
                      nullptr , symbolMap ,nullptr);
    Var* v8 = new Var("alt8" , new Number(0) , "/instrumentation/magnetic-compass/indicated-heading-deg" ,
                      nullptr , symbolMap ,nullptr);

    symbolMap->addVar(v1);
    symbolMap->addVar(v2);
    symbolMap->addVar(v3);
    symbolMap->addVar(v4);
    symbolMap->addVar(v5);
    symbolMap->addVar(v6);
    symbolMap->addVar(v7);
    symbolMap->addVar(v8);



    dataReaderServer server(5400 , 10 , symbolMap);

    server.openServer();

}
