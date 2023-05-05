#ifndef LOADCSV_TEST_HPP
#define LOADCSV_TEST_HPP

#include "gtest/gtest.h"
#include "../src/CSVLoader.hpp"

TEST(CSVLoad, RegularFile){
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/normal.csv";
    ifstream file(csv_path);
    vector<string> contents = {"number,name,school,type,year,ending", 
                                "1,Jackie,UCR,Student one,final",
                                "2,Gary,UCI,Student two,start",
                                "3,test, space, before,2", 
                                "4,,,4"};

    vector<string> function = loadCSV(file);

    EXPECT_EQ(contents[0], function[0]);
    EXPECT_EQ(contents[1], function[1]);
    EXPECT_EQ(contents[2], function[2]);
    EXPECT_EQ(contents[3], function[3]);
}

TEST(CSVLoad, MultipleSpaces){
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/extraLines.csv";
    ifstream file(csv_path);
    vector<string> contents = {"number,name,school,type,year,ending", 
                                "1,Jackie,UCR,Student one,final",
                                "2,Gary,UCI,Student two,start",
                                "3,test, space, before,2", 
                                "4,,,4"};

    vector<string> function = loadCSV(file);

    EXPECT_EQ(contents[0], function[0]);
    EXPECT_EQ(contents[1], function[1]);
    EXPECT_EQ(contents[2], function[2]);
    EXPECT_EQ(contents[3], function[3]);
}


#endif