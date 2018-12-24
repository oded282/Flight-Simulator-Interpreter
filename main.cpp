
#include <sstream>
#include <stack>
#include "dataReaderServer.h"
#include "Number.h"
#include "mapCommand.h"
#include "ShuntingYard.h"
#include "varFactory.h"
#include "openServerCommand.h"
#include "AssignCommand.h"
#include "sleepCommand.h"
#include "whileCommand.h"


using namespace std;


mapCommand *buildMapExpressionCommand() {

    mapCommand* mapCommand1 = new mapCommand();
    ShuntingYard* shuntingYard = new ShuntingYard(&mapCommand1->getCommandMap());
    symbolTable* varMap = new symbolTable();


    commandExpression* c1 = new commandExpression(new openServerCommand(mapCommand1 , varMap, shuntingYard));
    commandExpression* c2 = new commandExpression(new connectCommand(mapCommand1 , varMap, shuntingYard));
    commandExpression * c3 = new commandExpression((new AssignCommand(mapCommand1,varMap,shuntingYard)));
    commandExpression* c4 = new commandExpression(new sleepCommand(mapCommand1 , varMap, shuntingYard));
    commandExpression* c5 =new commandExpression( new whileCommand(nullptr , mapCommand1 , varMap, shuntingYard));
    //commandExpression* c6 =new commandExpression(new ifCommand(mapCommand1 , varMap, shuntingYard));
    commandExpression* c7 = new commandExpression(new varFactory(mapCommand1 , varMap, shuntingYard));
    //commandExpression* c8 = new commandExpression(new preintCommand(mapCommand1 , varMap, shuntingYard));



    mapCommand1->addCommand("openDataServer" , c1);
    mapCommand1->addCommand("connect" , c2);
    mapCommand1->addCommand("=" , c3);
    mapCommand1->addCommand("sleep" , c4);
    mapCommand1->addCommand("while" , c5);
    //mapCommand1->addCommand("if" , c6);
    mapCommand1->addCommand("var" , c7);
    //mapCommand1->addCommand("print" , c8);









    return nullptr;
}





int main(int argc, char* argv[]){





    mapCommand* mapExpressionCommand = buildMapExpressionCommand();





    symbolTable* symbolMap = new symbolTable();

    Var* v1 = new Var("alt1" , new Number(10) , "/instrumentation/airspeed-indicator/indicated-speed-kt" ,
            nullptr , symbolMap ,nullptr);
    Var* v2 = new Var("alt2" , new Number(10) , "/instrumentation/altimeter/pressure-alt-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v3 = new Var("alt3" , new Number(10) , "/instrumentation/attitude-indicator/indicated-pitch-deg" ,
                      nullptr , symbolMap ,nullptr);
    Var* v4 = new Var("alt4" , new Number(10) , "/instrumentation/attitude-indicator/internal-pitch-deg" ,
                      nullptr , symbolMap ,nullptr);
    Var* v5 = new Var("alt5" , new Number(10) , "/instrumentation/encoder/indicated-altitude-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v6 = new Var("alt6" , new Number(10) , "/instrumentation/gps/indicated-altitude-ft" ,
                      nullptr , symbolMap ,nullptr);
    Var* v7 = new Var("alt7" , new Number(10) , "/instrumentation/gps/indicated-vertical-speed" ,
                      nullptr , symbolMap ,nullptr);
    Var* v8 = new Var("alt8" , new Number(10) , "/instrumentation/magnetic-compass/indicated-heading-deg" ,
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

