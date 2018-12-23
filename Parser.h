#ifndef FLIGHT_SIMULATOR_PARSER_H
#define FLIGHT_SIMULATOR_PARSER_H

#include <vector>
#include <string>
#include "mapCommand.h"

using namespace std;

class Parser
{
    vector<string> vectorInfo;
    double index;
    mapCommand * commandmap;

public:
    Parser(){};

    Parser(const vector<string> &vectorInfo, mapCommand*);

    const vector<string> &getVector() const;

    double getIndex() const;

    void setParser(const vector<string> &vector);

    void setIndex(int index);

    void doParser();
};



#endif //FLIGHT_SIMULATOR_PARSER_H
