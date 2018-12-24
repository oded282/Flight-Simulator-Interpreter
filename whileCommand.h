
#ifndef FLIGHT_SIMULATOR_WHILECOMMAND_H
#define FLIGHT_SIMULATOR_WHILECOMMAND_H


#include "Commands.h"
#include "mapCommand.h"
#include "ConditionParser.h"

class whileCommand : public ConditionParser{

public:
    virtual int execute();
    whileCommand(Parser* parser, mapCommand* mapTable , symbolTable* varTable , ShuntingYard* shuntingYard) :
    ConditionParser(parser, mapTable,varTable , shuntingYard){}
    virtual void setCommand(string& str);
    int numberOfWhileCommands();
    void removeClosingParanthesis(double counter);
    void setParser(Parser*);


};


#endif //FLIGHT_SIMULATOR_WHILECOMMAND_H
