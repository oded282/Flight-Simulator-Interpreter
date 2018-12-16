
#include "Div.h"


Div::Div(Expression * left, Expression * right) {
    Div::left = left;
    Div::right = right;
}

double Div::calculate() {
    return left->calculate() / right->calculate();
}

