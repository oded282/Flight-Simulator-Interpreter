#ifndef FLIGHT_SIMULATOR_VAR_H
#define FLIGHT_SIMULATOR_VAR_H

#include "Commands.h"


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

    ~VarCommand(){
       // delete value;
    }
};


#endif //FLIGHT_SIMULATOR_VAR_H