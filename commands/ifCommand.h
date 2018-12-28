
#ifndef FLIGHT_SIMULATOR_IFCOMMAND_H
#define FLIGHT_SIMULATOR_IFCOMMAND_H


#include "Commands.h"
#include "ConditionParser.h"

/*
 * This func responsible to execute if statements writen in the file/user
 */
class ifCommand : public ConditionParser {

public:
    ifCommand(Parser* parser, mapCommand* mapTable , symbolTable* varTable , ShuntingYard* shuntingYard) :
    ConditionParser(parser, mapTable,varTable , shuntingYard){}
    virtual int execute();
    virtual void setCommand(string& str);
    ~ifCommand(){}
};


#endif //FLIGHT_SIMULATOR_IFCOMMAND_H
