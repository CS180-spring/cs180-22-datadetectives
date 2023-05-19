#ifndef JOB_HPP
#define JOB_HPP

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Job{
    private: 
    int mappers = 2;
    int reducers = 1;
    int fileCount = 0;
    string outputName = "output.txt";
    vector <string> inputPaths;
    public:
    void setMappers(int m){mappers = m;};
    void setReducers(int r){reducers = r;};
    void addInputPath(string s){inputPaths.push_back(s); ++fileCount;};
    void setOutputPath(string s){outputName = s;};
    int getMappers(){return mappers;};
    int getReducers(){return reducers;};
    int getFileCount(){return fileCount;};
    string getOutputName(){return outputName;};
    vector< string> getPaths(){return inputPaths;};
};

#endif //JOB_HPP