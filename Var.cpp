
#include "Var.h"


int Var::execute(){

}

Var:: Var(string sentence, double value){
    Var::sentence = sentence;
    Var::value = value;
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