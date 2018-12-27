
#include <map>
#include <iostream>
#include "VarCommand.h"
#include "../data/symbolTable.h"

extern pthread_mutex_t mutex;

int VarCommand::execute() {
    return (int)value->calculate();
}

void VarCommand::setCommand(string& str){

}

VarCommand::VarCommand(string name, Expression *value , string path, mapCommand *commandTable,
        symbolTable *varTable, ShuntingYard* shuntingYard) :
        Commands(commandTable,varTable , shuntingYard) {
    VarCommand::name = name;
    VarCommand::path = path;
    VarCommand::value = value;
}

const string &VarCommand::getSentence() const {
    return path;
}

void VarCommand::setSentence(const string &sentence) {
    VarCommand::path = sentence;
}

void VarCommand::setValue(Expression *value) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    cout << "lock set var"<<endl;
    //delete this->value;
    VarCommand::value = value;
    cout << "unlock get var by path" << endl;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
}

Expression *VarCommand::getValue() const {
    return value;
}

string VarCommand::getName() {
    return name;
}

vector<VarCommand*> VarCommand::getFriends(){
    return friends;
}

void VarCommand::setFriends(){
    map<string,VarCommand*> :: iterator it;
    for(it = varTable->getSymbolMap().begin(); it != varTable->getSymbolMap().end(); it++){
        if((*it).second->getSentence() == path){
            friends.push_back((*it).second);
        }
    }
}