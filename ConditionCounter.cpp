

#include "ConditionCounter.h"

int ConditionCounter::getCount() {
    return ConditionCounter::counter;
}

void ConditionCounter::addCounter(int counter) {
    ConditionCounter::counter += counter;
}

ConditionCounter::ConditionCounter(int counter) {
    ConditionCounter::counter = counter;
}
