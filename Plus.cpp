#include "Plus.h"


double Plus::calculate() {
    return left->calculate() + right->calculate();
}