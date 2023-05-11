#include <iostream>
#include "../src/Reducer.hpp"
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    map<string, vector<int>> temp;    
    vector<int> vTemp;
    vTemp.push_back(1);
    vTemp.push_back(2);
    vTemp.push_back(1);

    temp["key"] = vTemp;

    Reducer reduceMe;
    map<string, int> save = reduceMe.Reduce(temp);

    cout << save.begin()->first << " " << save.begin()->second << endl;
}