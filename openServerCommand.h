#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include <string>
#include "Expression.h"
#include "Commands.h"
#include "dataReaderServer.h"

class openServerCommand : public Commands {

    dataReaderServer *readerServer;
public:
    openServerCommand(mapCommand *commandMap, symbolTable *varTable, ShuntingYard *shuntingYard) :
            Commands(commandMap, varTable, shuntingYard) {
        this->readerServer = nullptr;
    }

    bool checkLegality(string);

    void setCommand(string &);

    virtual int execute();


};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H

