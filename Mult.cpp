#include "Mult.h"


double Mult::calculate() {
    return left->calculate() * right->calculate();
}