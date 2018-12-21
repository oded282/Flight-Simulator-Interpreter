
#include "Var.h"


int Var::execute(){

}

Var::Var(string& name , string& path,mapCommand* commandTable, symbolTable* varTable) : Commands(commandTable, varTable){
    Var::name = name;
    Var::path = path;
    Var::value = 0;
}

const string &Var::getSentence() const {
    return path;
}

void Var::setSentence(const string &sentence) {
    Var::path = sentence;
}

void Var::setValue(double value) {
    Var::value = value;
}

double Var::getValue() const {
    return value;
}
