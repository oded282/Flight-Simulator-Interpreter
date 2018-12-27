
#ifndef FLIGHT_SIMULATOR_EXPRESSION_H
#define FLIGHT_SIMULATOR_EXPRESSION_H


class Expression{
public:
    virtual double calculate() =0;
    virtual ~Expression() = default;
};










#endif //FLIGHT_SIMULATOR_EXPRESSION_H
