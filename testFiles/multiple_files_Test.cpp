#include <iostream>
#include <vector>
#include <string>
#include "../src/Concurrency.hpp"
#include "../src/TXTLoader.hpp"
#include "TempAvgMapReduce.cpp"
#include "WordCountMapReduce.cpp"


using namespace std;

int main(){
    Job job;
    job.setMappers(5);
    job.setReducers(5);

    TempAvgMapReduce userMapReduce;
    Concurrency avgtemp(job);

    TXTloader load;
    string path1 = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/data.json";
    string path2 = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/data.json";
    string path3  = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/data.json";
    vector<string> temp;
    temp.push_back(path1);
    temp.push_back(path2);
    temp.push_back(path3);

    map<string, int> results = avgtemp.runMapReduce(userMapReduce, load.loadTXT(temp));
  
    
}