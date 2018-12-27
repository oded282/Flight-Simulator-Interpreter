

#ifndef FLIGHT_SIMULATOR_CONDITIONCOUNTER_H
#define FLIGHT_SIMULATOR_CONDITIONCOUNTER_H


class ConditionCounter {

    int counter;

public:
    ConditionCounter(int counter);

    int getCount();

    void addCounter(int counter);
};


#endif //FLIGHT_SIMULATOR_CONDITIONCOUNTER_H
