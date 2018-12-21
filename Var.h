#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"



class Var : public Commands{
    string name;
    string path;
    double value;

public:
    virtual int execute();

    Var(string& name , string& path ,mapCommand* commandTable, symbolTable* varTable);

    const string &getSentence() const;
    void setSentence(const string &sentence);

    double getValue() const;

    void setValue(double value);
};





#endif //FLIGHT_SIMULATOR_VAR_H