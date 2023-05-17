#ifndef CSVSPLIT_TEST_HPP
#define CSVSPLIT_TSET_HPP

#include "gtest/gtest.h"
#include "../src/csvSplitter.hpp"
#include <vector>
#include <string>

TEST(SplitTest, EmptyVector){
    vector<string> emptyVec;
    csvSplitter my_splitter(4,4);
    vector<vector<string>> testResult = my_splitter.splitCsv(emptyVec);

    EXPECT_TRUE(testResult.size() == 0);
}

TEST(SplitTest, DivisablySized){
    vector<string> testVec = {"0","1","2","3", "4","5","6","7", "8","9","10","11", "12","13","14","15"};
    csvSplitter my_splitter(4,4);
    vector<vector<string>> testResult = my_splitter.splitCsv(testVec);

    int i = 0;
    for(auto splits : testResult){
        for(auto str : splits){
            EXPECT_EQ(str, to_string(i));
            i++;
        }
    }
    EXPECT_EQ(testResult[2][0], "8");
    EXPECT_EQ(testResult.size(), 4);
    int sum = 0;
    for(auto sepVecs : testResult){
        sum += sepVecs.size();
    }
    //sum of sizes of internal vectors is the same as the orginal given vector
    EXPECT_EQ(testVec.size(), sum);
}

TEST(SplitTest, IndivisiblySized){
    vector<string> testVec = {"0","1","2","3", "4","5","6","7", "8","9","10","11", "12","13","14","15","16","17","18"};
    csvSplitter my_splitter(4,4);
    vector<vector<string>> testResult = my_splitter.splitCsv(testVec);

    EXPECT_EQ(testResult[0].size(), testResult[1].size());
    EXPECT_EQ(testResult[2][1], "9");
    EXPECT_EQ(testResult.size(), 4);
    //last sub-vector should have the extra strings
    EXPECT_EQ(testResult[3].size(), 7);

    int sum = 0;
    for(auto sepVecs : testResult){
        sum += sepVecs.size();
    }
    //sum of sizes of internal vectors is the same as the orginal given vector
    EXPECT_EQ(testVec.size(), sum);
}

TEST(splitMap, Divisible){
    map<string, vector<int> > mymap;

    vector<int> vect;
    vect.push_back(1);
    vect.push_back(1);

    mymap["a"] = vect;
    mymap["b"] = vect;
    mymap["c"] = vect;
    mymap["d"] = vect;
    mymap["e"] = vect;
    mymap["f"] = vect;
    mymap["g"] = vect;
    mymap["h"] = vect;
    csvSplitter splitter(4,4);
    vector<map<string, vector<int>>> result = splitter.splitMap(mymap);

    EXPECT_EQ(result[0].size(), result[1].size());
    EXPECT_EQ(result[2].size(), result[3].size());
}

TEST(splitMap, Indivisible){
    map<string, vector<int> > mymap;

    vector<int> vect;
    vect.push_back(1);
    vect.push_back(1);

    mymap["a"] = vect;
    mymap["b"] = vect;
    mymap["c"] = vect;
    mymap["d"] = vect;
    mymap["e"] = vect;
    mymap["f"] = vect;
    mymap["g"] = vect;
    mymap["h"] = vect;
    mymap["i"] = vect;
    csvSplitter splitter(4,4);
    vector<map<string, vector<int>>> result = splitter.splitMap(mymap);

    EXPECT_EQ(result[0].size(), result[1].size());
    EXPECT_EQ(result[3].size(), 3);
}

TEST(splitMap, EmptyInput){
    map<string, vector<int> > mymap;
    csvSplitter splitter(4,4);
    vector<map<string, vector<int>>> result = splitter.splitMap(mymap);

    //creates sub-maps
    EXPECT_EQ(result.size(), 4);
    //that are empty
    EXPECT_EQ(result[0].size(), 0);
}

#endif //CSVSPLIT_TEST_HPP