#ifndef INTEGRATION_TEST_HPP
#define INTEGRATION_TEST_HPP

#include "gtest/gtest.h"
#include "../src/Concurrency.hpp"
#include "TempAvgMapReduce.cpp"
#include "WordCountMapReduce.cpp"
#include "CarAvgPrice.cpp"
#include "TrafficAvg.cpp"

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
    
    EXPECT_EQ(results["5-12-23"], 77);
    EXPECT_EQ(results["5-13-23"], 84);
    EXPECT_EQ(results["5-14-23"], 82);
    EXPECT_EQ(results["5-17-23"], 82);
    EXPECT_EQ(results["5-19-23"], 77);
}

//word count with jsonReader and splitStr
TEST(Integration, WordCount){
    Job config;
    config.setMappers(4);
    config.setReducers(4);

    WordCountMapReduce userMapReduce;
    Concurrency count(config);

    JsonReader my_reader;
    string file = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/test.json";

    map<string, int> results = count.runMapReduce(userMapReduce, my_reader.splitStr(my_reader.ReadFile({file})));

    EXPECT_EQ(results["hello"], 5);
    EXPECT_EQ(results["i"], 3);
    EXPECT_EQ(results["hi"], 1);
}

//csvfile with 2.5 million lines ~223MB
TEST(Integration, LargeFileConc){

    Job config;
    config.setMappers(14);
    config.setReducers(4);

    CarAvgMapReduce userMapReduce;
    Concurrency avgprice(config);

    OpenFile of;
    CSVLoader load;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/car_sales_data.csv";

    ifstream file = of.openFile(csv_path);
    map<string, int> results;
    results = avgprice.runMapReduce(userMapReduce, load.loadCSV(file));

}

//same test but not concurrent
TEST(Integration, LargeFileSeq){

    CarAvgMapReduce userMapReduce;
    MapReduceEngine engine(userMapReduce);

    OpenFile of;
    CSVLoader load;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/car_sales_data.csv";

    ifstream file = of.openFile(csv_path);
    map<string, int> results;
    results = engine.Run( load.loadCSV(file));
    
}

//csv file ~90MB
TEST(Integration, MidSizedFileConc){

    Job config;
    config.setMappers(14);
    config.setReducers(12);

    TrafficAvgMapReduce userMapReduce;
    Concurrency avgprice(config);

    OpenFile of;
    CSVLoader load;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/yellow_tripdata_2016-03.csv";

    ifstream file = of.openFile(csv_path);
    map<string, int> results;
    results = avgprice.runMapReduce(userMapReduce, load.loadCSV(file));

}


//same test but not concurrent
TEST(Integration, MidSizedFileSeq){

    TrafficAvgMapReduce userMapReduce;
    MapReduceEngine engine(userMapReduce);

    OpenFile of;
    CSVLoader load;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/yellow_tripdata_2016-03.csv";

    ifstream file = of.openFile(csv_path);
    map<string, int> results;
    results = engine.Run( load.loadCSV(file));
    
}

/*
TEST(Integration, CSVSplit){
    Job config;
    config.setMappers(4);
    config.setReducers(4);

    WordCountMapReduce userMapReduce;
    Concurrency count(config);

    OpenFile of;
    CSVLoader load;
    string path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/temp_data.txt";

    ifstream file = of.openFile(path);
    map<string, int> results = count.runMapReduce(userMapReduce, load.splitStr(load.loadCSV(file)));

    EXPECT_EQ(results["saratoga"], 10);
    EXPECT_EQ(results["5-12-23"], 4);
}
*/
#endif //INTEGRATION_TEST_HPP