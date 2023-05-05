#include <iostream>
#include <vector>
#include <string>
#include "../src/CSVLoader.hpp"

using namespace std;


int main(){
    vector<string> v;
    v.push_back("../csvTestFiles/blank.csv");
    v.push_back("../csvTestFiles/extraLines.csv");
    v.push_back("../csvTestFiles/normal.csv");

    CSVLoader loader;
    
    vector<string> data = loader.loadMulCSV(v);

    for(int i = 0; i < data.size(); i++){
        cout << data[i] << endl;
    }
    return 0;
}