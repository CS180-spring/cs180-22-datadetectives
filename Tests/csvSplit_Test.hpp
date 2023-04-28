#ifndef CSVSPLIT_TEST_HPP
#define CSVSPLIT_TSET_HPP

#include "gtest/gtest.h"
#include "csvSplitter.hpp"
#include <vector>
#include <string>

using namespace std;

TEST(SplitTest, EmptyVector){
    vector<string> emptyVec;
    csvSplitter my_splitter();
    vector<vector<string>> testResult = my_splitter.splitCsv(emptyVec);

    EXPECT_TRUE(testResult.size() == 0);
}

TEST(SplitTest, DivisablySized){
    vector<string> testVec = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
    csvSplitter my_splitter();
    vector<vector<string>> testResult = my_splitter.splitCsv(testVec);

    EXPECT_EQ(testResult[0].size(), testResult[1].size());
    EXPECT_EQ(testResult[6].size(), testResult[7].size());
    EXPECT_EQ(testResult[2], {"4","5"});
    EXPECT_EQ(testResult.size(), 8);
    int sum = 0;
    for(auto sepVecs : testResult){
        sum += sepVecs.size();
    }
    //sum of sizes of internal vectors is the same as the orginal given vector
    EXPECT_EQ(testVec.size(), sum);
}

TEST(SplitTest, IndivisiblySized){
    vector<string> testVec = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18"};
    csvSplitter my_splitter();
    vector<vector<string>> testResult = my_splitter.splitCsv(testVec);

    EXPECT_EQ(testResult[0].size(), testResult[1].size());
    EXPECT_EQ(testResult[2], {"4","5"});
    EXPECT_EQ(testResult.size(), 8);
    //last sub-vector should have the extra strings
    EXPECT_EQ(testResult[7].size(), 5);

    int sum = 0;
    for(auto sepVecs : testResult){
        sum += sepVecs.size();
    }
    //sum of sizes of internal vectors is the same as the orginal given vector
    EXPECT_EQ(testVec.size(), sum);
}

#endif //CSVSPLIT_TEST_HPP