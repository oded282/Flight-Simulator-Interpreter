//
// Created by oded on 12/18/18.
//

#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"

class Var : Commands{
    string sentence;
    double value;

public:
    virtual int execute();
    Var(){};

    const string &getSentence() const;
    void setSentence(const string &sentence);

    void setValue(double value);
};





#endif //FLIGHT_SIMULATOR_VAR_H
