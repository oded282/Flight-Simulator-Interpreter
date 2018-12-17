#include <string>
#include <algorithm>
#include "Commands.h"

using namespace std;

void Commands::cleanWhiteSpaces(string& sentence){
    sentence.erase( remove( sentence.begin(), sentence.end(), ' ' ), sentence.end() );
}

