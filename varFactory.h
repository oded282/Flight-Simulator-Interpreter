
#ifndef FLIGHT_SIMULATOR_VARFACTORY_H
#define FLIGHT_SIMULATOR_VARFACTORY_H


#include "Commands.h"
#include "symbolTable.h"


class varFactory : public Commands {


public:
    virtual int execute(string sentence);
    string getName(string::iterator it);
    string getSentence(string::iterator it);
    string getVariables(string sentence,vector<string>& vector);
    string::iterator jumpSpace(string::iterator it);
    string::iterator jumpUponWord(string::iterator it);
    string::iterator jumpToSentence(string::iterator it);
};


#endif //FLIGHT_SIMULATOR_VARFACTORY_H
