//
// Created by oded on 12/18/18.
//

#include "Var.h"


int Var::execute(){

}

const string &Var::getSentence() const {
    return sentence;
}

void Var::setSentence(const string &sentence) {
    Var::sentence = sentence;
}

void Var::setValue(double value) {
    Var::value = value;
}
