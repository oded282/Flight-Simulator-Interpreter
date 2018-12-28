#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"

/*
 * This class implement's commands interface and got responsibility
 * to create new vars.
 */
class VarCommand : public Commands {
    string name;
    string path;
    Expression *value;
    vector<VarCommand*> friends;

public:
    int execute();

    virtual void setCommand(string& str);

    VarCommand(string name, Expression* value, string path, mapCommand *commandTable,
            symbolTable *varTable  ,ShuntingYard* shuntingYard);

    const string &getSentence() const;

    void setSentence(const string &sentence);

    Expression *getValue() const;

    void setValue(Expression *value);

    string getName();

    void setFriends();

    vector<VarCommand*> getFriends();

    ~VarCommand(){}
};


#endif //FLIGHT_SIMULATOR_VAR_H