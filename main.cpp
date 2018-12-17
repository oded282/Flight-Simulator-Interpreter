#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;


void  cleanWhiteSpaces(string& sentence){
    sentence.erase( remove( sentence.begin(), sentence.end(), ' ' ), sentence.end() );
}



int main(int argc, char* argv[]) {

    string s = "5*3 + 2 ,-5";
    cleanWhiteSpaces(s);


    return 0;

}
