
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
#include "PrintCommand.h"
#include "ifCommand.cpp"


using namespace std;

bool isStop;
pthread_mutex_t mutex;

void buildMapExpressionCommand(mapCommand* mapCommand1, symbolTable* varMap, ShuntingYard* shuntingYard, Parser &parser) {

    connectCommand* c = new connectCommand(mapCommand1, varMap, shuntingYard);

    commandExpression* c1 = new commandExpression(new openServerCommand(mapCommand1, varMap, shuntingYard));
    commandExpression* c2 = new commandExpression((c));
    commandExpression* c3 = new commandExpression(((new AssignCommand(c ,mapCommand1, varMap, shuntingYard))));
    commandExpression* c4 = new commandExpression((new sleepCommand(mapCommand1, varMap, shuntingYard)));
    commandExpression* c5 = new commandExpression((new whileCommand(&parser, mapCommand1, varMap, shuntingYard)));
    commandExpression* c6 = new commandExpression((new ifCommand(&parser, mapCommand1 , varMap, shuntingYard)));
    commandExpression* c7 = new commandExpression(new varFactory(mapCommand1, varMap, shuntingYard));
    commandExpression* c8 = new commandExpression(new PrintCommand(mapCommand1 , varMap, shuntingYard));


    mapCommand1->addCommand("openDataServer", c1);
    mapCommand1->addCommand("connect", c2);
    mapCommand1->addCommand("=", c3);
    mapCommand1->addCommand("sleep", c4);
    mapCommand1->addCommand("while", c5);
    mapCommand1->addCommand("if" , c6);
    mapCommand1->addCommand("var", c7);
    mapCommand1->addCommand("print" , c8);

}


int main(int argc, char *argv[]) {
    isStop = true;
    vector<string> lineCod;
    Lexer lexer;

    if (argc == 2) {
        lineCod = lexer.lexerFromFile(argv[1]);
    } else {
        lineCod = lexer.lexerFromConsole();
    }


    mapCommand *mapExpressionCommand = new mapCommand();
    symbolTable* varMap =  new symbolTable();
    ShuntingYard* shuntingYard = new ShuntingYard(varMap);
    Parser parser(lineCod , mapExpressionCommand);

    buildMapExpressionCommand(mapExpressionCommand, varMap, shuntingYard, parser);

    parser.doParser((int)lineCod.size());



    isStop = false;
}