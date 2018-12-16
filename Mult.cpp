#include "Mult.h"

Mult::Mult(Expression * left, Expression * right) {
    Mult::left = left;
    Mult::right = right;
}

double Mult::calculate() {
    return left->calculate() * right->calculate();
}