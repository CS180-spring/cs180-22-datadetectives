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
    void splittingJSONMapSize(int amount);
    void printData();
    void printDataMap();
private:
    vector<vector<json>> mapperSized;
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

void splittingJSON::splittingJSONMapSize(int amount){
    int size = data.size()/amount;
    vector<json> temp;
    int counter = 0;

    for(int i = 0; i < data.size(); i++){
        temp.push_back(data[i]);
        counter++;
        if(counter == size){
            counter = 0;
            mapperSized.push_back(temp);
            temp.clear();
        }
    }
    if(!temp.empty()){
        mapperSized.push_back(temp);
    }
}

void splittingJSON::printDataMap(){
    for (auto& tokens : mapperSized) {
        for(auto& token : tokens)
            std::cout << token.dump() << std::endl;
    }
}


#endif