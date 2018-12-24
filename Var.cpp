
#include <map>
#include "Var.h"
#include "symbolTable.h"


int Var::execute() {
    return (int)value->calculate();
}

void Var::setCommand(string& str){

}

Var::Var(string name, Expression *value , string path, mapCommand *commandTable,
        symbolTable *varTable, ShuntingYard* shuntingYard) :
        Commands(commandTable,varTable , shuntingYard) {
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

string Var::getName() {
    return name;
}

vector<Var*> Var::getFriends(){
    return friends;
}

void Var::setFriends(){
    map<string,Var*> :: iterator it;
    for(it = varTable->getSymbolMap().begin(); it != varTable->getSymbolMap().end(); it++){
        if((*it).second->getSentence() == path){
            friends.push_back((*it).second);
        }
    }
}