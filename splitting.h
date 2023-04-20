#ifndef SPLITTING_H
#define SPLITTING_H
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "lib/json.hpp"

using namespace std;
using json = nlohmann::json;

class splittingJSON{
public:
    splittingJSON(string filename);
    void printData();
private:
    
    vector<json> data;
};

splittingJSON::splittingJSON(string filename) {
    ifstream file(filename);

    json tokens;
    file >> tokens;

    for(auto& token : tokens){
        data.push_back(token);
    }

    file.close();
}

void splittingJSON::printData() {
    for (auto& token : data) {
        std::cout << token.dump() << std::endl;
    }
}



#endif