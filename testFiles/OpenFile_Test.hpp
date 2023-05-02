#ifndef OPENFILE_TEST_HPP
#define OPENFILE_TEST_HPP

#include "gtest/gtest.h"
#include "../src/OpenFile.hpp"
#include <string>

TEST(OpenFile, RegularFile){
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/normal.csv";
    EXPECT_NO_THROW(openFile(csv_path));
}

TEST(OpenFile, EmptyFile){
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/blank.csv";
    EXPECT_ANY_THROW(openFile(csv_path));
}

TEST(OpenFile, DoesNotExist){
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/noFile.csv";
    EXPECT_ANY_THROW(openFile(csv_path));
}
#endif