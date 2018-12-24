

#include <vector>
#include "varFactory.h"
#include "Number.h"


varFactory::varFactory(mapCommand *commandTable, symbolTable *varTable,ShuntingYard* shuntingYard) : Commands(commandTable, varTable,shuntingYard) {}

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

string::iterator varFactory::jumpToStartOfVar(string::iterator it) {
    while (*it == ' ' || *it == '=') {
        it++;
    }
    it++;
    return it;
}

string varFactory::getName(string::iterator it) {
    string name;
    while (*it != ' ') {
        name += *it;
        it++;
    }
    return name;
}

string varFactory::getSentence(string::iterator it, string::iterator itEnd) {
    string sentence;
    while (*it != '\"' || it != itEnd) {
        sentence += *it;
        it++;
    }
    return sentence;
}

string varFactory::getVariables(string sentence, vector<string> &vector, bool isBind) {
    string name;
    string varCommand;
    string::iterator it = sentence.begin();
    if (*it == ' ') {
        jumpSpace(it);
    }
    it = jumpUponWord(it);
    it = jumpSpace(it);
    vector.push_back(getName(it));
    if (isBind) {
        it = jumpToSentence(it);
    } else {
        jumpToStartOfVar(it);
    }
    vector.push_back(getSentence(it, sentence.end()));
}

int varFactory::execute() {
    return 1;
}

void varFactory::setCommand(string &sentence) {
    string bind = "bind";
    string var = "var";
    vector<string> vector;
    if (sentence.find(bind)) {
        getVariables(sentence, vector, true);
        Var *newVar = new Var(vector[0], new Number(0), vector[1], commandTable, varTable, shuntingYard);
        varTable->addVar(newVar);
    } else if (sentence.find(var) && !sentence.find(bind)) {
        getVariables(sentence, vector, false);
        Var *newVar = new Var(vector[0], varTable->getVarValue(vector[1]),
                              varTable->getVarPath(vector[1]), commandTable, varTable, shuntingYard);
        varTable->addVar(varTable->getVar(vector[1]));
    }else if(!sentence.find(var)){


    }
}


/*
int main(){
    varFactory factory;
    vector<string> vector;
    string s = "var breaks = bind \"/controls/flight/speedbrake\"";
    factory.getVariables(s,vector);

}
*/