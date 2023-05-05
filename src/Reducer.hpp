#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Reducer{
public: 
    map<string, int> Reduce(const map<string, vector<int>> &pairedValues);
};

map<string, int> Reducer::Reduce(const map<string, vector<int>> &pairedValues){
    string key = pairedValues.begin()->first;
    vector<int> values = pairedValues.at(key);

    int total = 0;
    for(int i = 0; i < values.size(); i++){
        total += values[i];
    }

    map<string, int> reducedKeyValue;
    reducedKeyValue[key] = total;
    return reducedKeyValue;
}
