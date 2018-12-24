
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
#include "Lexer.h"


using namespace std;


void buildMapExpressionCommand(mapCommand mapCommand1, symbolTable varMap, ShuntingYard shuntingYard, Parser &parser) {


    commandExpression c1(new openServerCommand(&mapCommand1, &varMap, &shuntingYard));
    commandExpression c2(new connectCommand(&mapCommand1, &varMap, &shuntingYard));
    commandExpression c3((new AssignCommand(&mapCommand1, &varMap, &shuntingYard)));
    commandExpression c4(new sleepCommand(&mapCommand1, &varMap, &shuntingYard));
    commandExpression c5(new whileCommand(&parser, &mapCommand1, &varMap, &shuntingYard));
    //commandExpression c6(new ifCommand(&parser, &mapCommand1 , &varMap, &shuntingYard));
    commandExpression c7(new varFactory(&mapCommand1, &varMap, &shuntingYard));
    //commandExpression c8(new PrintCommand(&mapCommand1 , &varMap, &shuntingYard));



    mapCommand1.addCommand("openDataServer", &c1);
    mapCommand1.addCommand("connect", &c2);
    mapCommand1.addCommand("=", &c3);
    mapCommand1.addCommand("sleep", &c4);
    mapCommand1.addCommand("while", &c5);
    //mapCommand1.addCommand("if" , &c6);
    mapCommand1.addCommand("var", &c7);
    //mapCommand1.addCommand("print" , c8);

}


int main(int argc, char *argv[]) {
    vector<string> lineCod;
    Lexer lexer;

    if (argc == 1) {
        lineCod = lexer.lexerFromFile(argv[0]);
    } else {
        lineCod = lexer.lexerFromConsole();
    }


    mapCommand mapExpressionCommand;
    ShuntingYard shuntingYard(&mapExpressionCommand.getCommandMap());
    symbolTable varMap;
    Parser parser(lineCod , &mapExpressionCommand);

    buildMapExpressionCommand(mapExpressionCommand, varMap, shuntingYard, parser);

    parser.doParser((int)lineCod.size());

}