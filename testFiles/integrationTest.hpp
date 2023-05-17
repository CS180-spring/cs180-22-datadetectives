#ifndef INTEGRATION_TEST_HPP
#define INTEGRATION_TEST_HPP

#include "gtest/gtest.h"
#include "../src/Concurrency.hpp"
#include "TempAvgMapReduce.cpp"

using namespace std;

//average temp with openfile and csvLoader
TEST(Integration, AvgTemp){
    Job config;
    config.setMappers(4);
    config.setReducers(4);

    TempAvgMapReduce userMapReduce;
    Concurrency avgtemp(config);

    OpenFile of;
    CSVLoader load;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/temp_data.txt";

    ifstream file = of.openFile(csv_path);
    map<string, int> results = avgtemp.runMapReduce(userMapReduce, load.loadCSV(file));
    
}

#endif //INTEGRATION_TEST_HPP