#ifndef FLIGHT_SIMULATOR_PARSER_H
#define FLIGHT_SIMULATOR_PARSER_H

#include <vector>
#include <string>
#include "../data/mapCommand.h"
#include "../ConditionCounter.h"

using namespace std;

class Parser
{
    vector<string> vectorInfo;
    double index;
    mapCommand * commandmap;
    ConditionCounter* counter;

public:
    Parser(){
        index = 0;
    };

    Parser(ConditionCounter* counter,const vector<string> &vectorInfo, mapCommand*);

    vector<string> &getVector();

    double getIndex();

    void setParser(const vector<string> &vector);

    void setIndex(int newIndex);

    void setMap(mapCommand*);

    vector<commandExpression*> doParser(int,bool);

    ~Parser(){}
};



#endif //FLIGHT_SIMULATOR_PARSER_H
