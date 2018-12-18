#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"

class Var : Commands{
    string sentence;
    double value;

public:
    virtual int execute();
    Var(){};
    Var(string sentence, double value);

    const string &getSentence() const;
    void setSentence(const string &sentence);

    void setValue(double value);
};





#endif //FLIGHT_SIMULATOR_VAR_H