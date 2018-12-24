#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"


class Var : public Commands {
    string name;
    string path;
    Expression *value;
    vector<Var*> friends;

public:
    int execute();

    virtual void setCommand(string& str);

    Var(string name, Expression* value, string path, mapCommand *commandTable,
            symbolTable *varTable  ,ShuntingYard* shuntingYard);

    const string &getSentence() const;

    void setSentence(const string &sentence);

    Expression *getValue() const;

    void setValue(Expression *value);

    string getName();

    void setFriends();

    vector<Var*> getFriends();
};


#endif //FLIGHT_SIMULATOR_VAR_H