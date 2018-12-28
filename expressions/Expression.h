
#ifndef FLIGHT_SIMULATOR_EXPRESSION_H
#define FLIGHT_SIMULATOR_EXPRESSION_H



/*
 * This class used as an interface to all expressions.
 */
class Expression{
public:
    virtual float calculate() =0;
    virtual ~Expression() = default;
};










#endif //FLIGHT_SIMULATOR_EXPRESSION_H
