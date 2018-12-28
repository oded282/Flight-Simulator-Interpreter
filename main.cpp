#include <sstream>
#include <stack>
#include "connection/dataReaderServer.h"
#include "expressions/Number.h"
#include "data/mapCommand.h"
#include "utils/ShuntingYard.h"
#include "commands/varFactory.h"
#include "commands/openServerCommand.h"
#include "commands/AssignCommand.h"
#include "commands/sleepCommand.h"
#include "commands/whileCommand.h"
#include "utils/Lexer.h"
#include "commands/PrintCommand.h"
#include "commands/ifCommand.cpp"
#include "commands/ConditionFactory.h"
#include "commandsFactory/PrintFactory.h"
#include "commandsFactory/AssignFactory.h"
#include "commandsFactory/SleepFactory.h"
#include <algorithm>

using namespace std;

bool isStop;
pthread_mutex_t mutex;


/**
 * This func creates all the classes "blueprint", that the program runs
 * and add them to the map.
 * @param counter count number of commands.
 * @param mapCommand1 map of all the command.
 * @param varMap map of all variables.
 * @param shuntingYard the calculation algortihem.
 * @param parser the class who parse all data.
 */
void buildMapExpressionCommand(ConditionCounter *counter, mapCommand *mapCommand1, symbolTable *varMap,
                               ShuntingYard *shuntingYard, Parser &parser) {

    connectCommand *c = new connectCommand(mapCommand1, varMap, shuntingYard);

    commandExpression *c1 = new commandExpression(new openServerCommand(mapCommand1, varMap, shuntingYard));
    commandExpression *c2 = new commandExpression((c));
    commandExpression *c3 = new commandExpression(((new AssignCommand(c, mapCommand1, varMap, shuntingYard))));
    commandExpression *c4 = new commandExpression((new sleepCommand(mapCommand1, varMap, shuntingYard)));
    commandExpression *c5 = new commandExpression((new whileCommand(&parser, mapCommand1, varMap, shuntingYard)));
    commandExpression *c6 = new commandExpression((new ifCommand(&parser, mapCommand1, varMap, shuntingYard)));
    commandExpression *c7 = new commandExpression(new varFactory(mapCommand1, varMap, shuntingYard));
    commandExpression *c8 = new commandExpression(new PrintCommand(mapCommand1, varMap, shuntingYard));
    commandExpression *c9 = new commandExpression(
            (new ConditionFactory(counter, &parser, mapCommand1, varMap, shuntingYard)));
    commandExpression *c10 = new commandExpression(
            (new PrintFactory(counter, &parser, mapCommand1, varMap, shuntingYard)));
    commandExpression *c11 = new commandExpression(
            (new AssignFactory(counter, &parser, c, mapCommand1, varMap, shuntingYard)));
    commandExpression *c12 = new commandExpression(
            (new SleepFactory(counter, &parser, mapCommand1, varMap, shuntingYard)));

    mapCommand1->addCommand("openDataServer", c1);
    mapCommand1->addCommand("connect", c2);
    mapCommand1->addCommand("=", c3);
    mapCommand1->addCommand("sleep", c4);
    mapCommand1->addCommand("while", c5);
    mapCommand1->addCommand("if", c6);
    mapCommand1->addCommand("var", c7);
    mapCommand1->addCommand("print", c8);
    mapCommand1->addCommand("ConditionFactory", c9);
    mapCommand1->addCommand("PrintFactory", c10);
    mapCommand1->addCommand("AssignFactory", c11);
    mapCommand1->addCommand("SleepFactory", c12);

}

/**
 * This func clean whitspaces from the string.
 * @param str the string who needs to be clean.
 */
void cleanWhitSpaces(string& str) {
    unsigned int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    str = str.substr(i,str.size());
}

/**
 * This func check the paranthesis validation.
 * @param lineCod all data string vector.
 */
void fixLineCod(vector<string> &lineCod) {
    int index = 0;
    while (index < lineCod.size()) {
        cleanWhitSpaces(lineCod[index]);
        if (lineCod[index] == "}") {
            index++;
            continue;
        }
        if (lineCod[index].find('}') != string::npos) {
            lineCod[index].erase(std::remove(lineCod[index].begin(), lineCod[index].end(), '}'), lineCod[index].end());
            lineCod.insert(lineCod.begin() + (index + 1), "}");
            index++;
        }
        index++;
    }
}

/**
 * This func reads the data from the string and start's to parse
 * all data.
 * @param argc number of arguments.
 * @param argv the list of all arguments (the file).
 * @return zero
 */

int main(int argc, char *argv[]) {
    isStop = true;
    vector<string> lineCod;
    Lexer lexer;

    if (argc == 2) {
        lineCod = lexer.lexerFromFile(argv[1]);
    } else {
        lineCod = lexer.lexerFromConsole();
    }
    fixLineCod(lineCod);
    ConditionCounter *counter = new ConditionCounter(1);
    mapCommand *mapExpressionCommand = new mapCommand();
    symbolTable *varMap = new symbolTable();
    ShuntingYard *shuntingYard = new ShuntingYard(varMap, mapExpressionCommand);
    Parser parser(counter, lineCod, mapExpressionCommand);

    buildMapExpressionCommand(counter, mapExpressionCommand, varMap, shuntingYard, parser);
    parser.doParser((int) lineCod.size(), true);

    isStop = false;
    sleep(10);
    delete shuntingYard;
    delete mapExpressionCommand;
    delete varMap;
}