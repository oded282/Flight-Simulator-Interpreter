#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

vector<string> lexerFromFile(string file){
    string word;
    vector<string> vectorCommands;
    ifstream myFile;
    myFile.open(file);
    if(myFile.is_open()){
        while(myFile >> word){
            vectorCommands.push_back(word);
        }
    }
    return vectorCommands;

}

vector<string> lexerFromConsole(){
    string command;
    vector<string> vectorCommands;
    while(command != "print \"done\""){
        getline(cin, command);
        istringstream iss(command);
        vector<std::string> results(istream_iterator<std::string>{iss},
                                    istream_iterator<std::string>());
        copy(results.begin(), results.end(), back_inserter(vectorCommands));
    }
    return vectorCommands;

}


int main(int argc, char* argv[]) {
    vector<string> vec;
    if(argc == 2){
        vec = lexerFromFile(argv[1]);
    }else{
        vec = lexerFromConsole();
    }

    return 0;
}
