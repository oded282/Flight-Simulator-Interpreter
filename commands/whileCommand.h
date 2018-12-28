
#ifndef FLIGHT_SIMULATOR_WHILECOMMAND_H
#define FLIGHT_SIMULATOR_WHILECOMMAND_H


#include "Commands.h"
#include "../data/mapCommand.h"
#include "../ConditionParser.h"

/*
 *This command used to execute while loops that sent as command by the user/file.
 */
class whileCommand : public ConditionParser{
    bool isParsedNeeded = true;

public:

    virtual int execute();
    whileCommand(Parser* parser, mapCommand* mapTable , symbolTable* varTable , ShuntingYard* shuntingYard) :
    ConditionParser(parser, mapTable,varTable , shuntingYard){}
    virtual void setCommand(string& str);
    ~whileCommand(){}

};

#endif //FLIGHT_SIMULATOR_WHILECOMMAND_H
