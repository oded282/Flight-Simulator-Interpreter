#include "Plus.h"


Plus::Plus(Expression* left, Expression* right) {
    Plus::left = left;
    Plus::right = right;
}

double Plus::calculate() {
    return left->calculate() + right->calculate();
}