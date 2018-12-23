#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"


class Var : public Commands {
    string name;
    string path;
    Expression *value;

public:
    int execute();

    virtual void setCommand(string& str);

    Var(string &name, Expression* value, string &path, mapCommand *commandTable, symbolTable *varTable);

    const string &getSentence() const;

    void setSentence(const string &sentence);

    Expression *getValue() const;

    void setValue(Expression *value);
};


#endif //FLIGHT_SIMULATOR_VAR_H