

#include <vector>
#include "varFactory.h"


varFactory::varFactory(mapCommand *commandTable, symbolTable *varTable) : Commands(commandTable , varTable){}

string::iterator varFactory::jumpSpace(string::iterator it) {
    while (*it == ' ') {
        it++;
    }
    return it;
}

string::iterator varFactory::jumpUponWord(string::iterator it) {
    while (*it != ' ') {
        it++;
    }
    return it;
}

string::iterator varFactory::jumpToSentence(string::iterator it) {
    while (*it != '\"') {
        it++;
    }
    it++;
    return it;
}

string varFactory::getName(string::iterator it){
    string name;
    while(*it != ' '){
        name += *it;
        it++;
    }
    return name;
}

string varFactory::getSentence(string::iterator it){
    string sentence;
    while(*it != '\"'){
        sentence += *it;
        it++;
    }
    return sentence;
}


string varFactory::getVariables(string sentence,vector<string>& vector) {
    string name;
    string varCommand;
    string::iterator it = sentence.begin();
    if (*it == ' ') {
        jumpSpace(it);
    }
    it = jumpUponWord(it);
    it = jumpSpace(it);
    vector.push_back(getName(it));
    it = jumpToSentence(it);
    vector.push_back(getSentence(it));

}

int varFactory::execute(string sentence) {
    vector<string> vector;
    getVariables(sentence,vector);
    Var* var = new Var(vector[0] , vector[1] , commandTable,varTable);
    varTable->addVar(vector[0],0); //TODO initial the var value to zero, need to check if it's fine.
}

/*
int main(){
    varFactory factory;
    vector<string> vector;
    string s = "var breaks = bind \"/controls/flight/speedbrake\"";
    factory.getVariables(s,vector);

}
*/