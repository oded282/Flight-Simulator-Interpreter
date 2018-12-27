

#include <vector>
#include <iostream>
#include "varFactory.h"
#include "../expressions/Number.h"
#include "../utils/ShuntingYard.h"


varFactory::varFactory(mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard) :
        Commands(commandTable, varTable, shuntingYard) {
    numZero = new Number(0);
}

string::iterator varFactory::jumpSpace(string::iterator& it) {
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
    it += 2;
    return it;
}

string::iterator varFactory::jumpToStartOfVar(string::iterator it) {
    while (*it == ' ' || *it == '=') {
        it++;
    }
    it++;
    return it;
}

string varFactory::getName(string::iterator& it,string::iterator itEnd) {
    string name;
    while (*it != '=' && it != itEnd) {
        name += *it;
        it++;
    }
    return name;
}

string varFactory::getSentence(string::iterator& it, string::iterator itEnd) {
    string sentence;
    while (*it != '\"' && it != itEnd) {
        sentence += *it;
        it++;
    }
    return sentence;
}

void varFactory::getVariables(string sentence, vector<string> &vector, bool isBind) {
    cleanWhiteSpaces(sentence);
    sentence = sentence.substr(3,sentence.size());
    string name;
    string varCommand;
    string::iterator it = sentence.begin();
    vector.push_back(getName(it,sentence.end()));
    if (isBind) {
        it = jumpToSentence(it);
    } else {
        it++;
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
    if (sentence.find("bind") != string::npos) {
        getVariables(sentence, vector, true);
        Var *newVar = new Var(vector[0], numZero, vector[1], commandTable, varTable, shuntingYard);
        varTable->addVar(newVar);
        commandTable->addCommand(vector[0], new commandExpression(newVar));
    } else{
        getVariables(sentence, vector, false);
        Var *newVar = new Var(vector[0], varTable->getVarValue(vector[1]),
                              varTable->getVarPath(vector[1]), commandTable, varTable, shuntingYard);
        newVar->setFriends();
        varTable->addVar(newVar);
        commandTable->addCommand(vector[0], new commandExpression(newVar));
    }
}
