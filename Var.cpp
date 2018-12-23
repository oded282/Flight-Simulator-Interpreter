
#include "Var.h"


int Var::execute() {
    return 1;
}

void Var::setCommand(string& str){

}

Var::Var(string &name, Expression *value , string &path, mapCommand *commandTable, symbolTable *varTable) : Commands(commandTable,
                                                                                                 varTable) {
    Var::name = name;
    Var::path = path;
    Var::value = value;
}

const string &Var::getSentence() const {
    return path;
}

void Var::setSentence(const string &sentence) {
    Var::path = sentence;
}

void Var::setValue(Expression *value) {
    Var::value = value;
}

Expression *Var::getValue() const {
    return value;
}
