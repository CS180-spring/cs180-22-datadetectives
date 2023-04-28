#ifndef CRV_SPLITTER_H
#define CRV_SPLITTER_H

#include <vector>
#include <string>
#include <thread>
#include <iostream>
using namespace std;

class csvSplitter{
    public:
        vector<vector<string>> splitCsv(vector<string> csvFile);
    private:
        //temporary # of threads to split into
        int threadCount();
};

int threadCount(){
    //temp
    return 8;
}

vector<vector<string>> csvSplitter::splitCsv(vector<string> csvFile){
    vector<vector<string>> vect;

    //Checking for an empty input file/vector
    if(csvFile.size() == 0){
        cout << "ERROR: _EMPTY_ARGUMENT" << endl;
        return vect;
    } 
    
    //creates "equal" sized subvectors depending on # of threads in use
    int intervals = threadCount();
    for(int i = 0; i < csvFile.size(); i += int(csvFile.size()/intervals)){
        //last thread would handle lines(modulos threadCount) extra 
        if (vect.size() >= intervals-1) {
            vect.push_back(vector<string>(csvFile.begin() + i, csvFile.end()));
            break;
        }
        vect.push_back(vector<string>(csvFile.begin() + i, csvFile.begin() + csvFile.size()/8));
    }

    return vect;
}

#endif //CRV_SPLITTER_H