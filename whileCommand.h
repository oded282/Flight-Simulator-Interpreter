
#ifndef FLIGHT_SIMULATOR_WHILECOMMAND_H
#define FLIGHT_SIMULATOR_WHILECOMMAND_H


#include "Commands.h"
#include "mapCommand.h"
#include "ConditionParser.h"

class whileCommand : public ConditionParser{

public:
    virtual int execute();
    whileCommand(Parser* parser, mapCommand* mapTable , symbolTable* varTable) : ConditionParser(nullptr, nullptr,
                                                                                                 nullptr){
        this->parser = parser;
        this->commandTable = mapTable;
        this->varTable = varTable;
    }
    virtual void setCommand(string& str);


};


#endif //FLIGHT_SIMULATOR_WHILECOMMAND_H
