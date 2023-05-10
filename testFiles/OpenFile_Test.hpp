#ifndef OPENFILE_TEST_HPP
#define OPENFILE_TEST_HPP

#include "gtest/gtest.h"
#include "../src/OpenFile.hpp"
#include <string>

TEST(OpenFile, RegularFile){
    OpenFile of;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/normal.csv";
    EXPECT_NO_THROW(of.openFile(csv_path));
}

TEST(OpenFile, EmptyFile){
    OpenFile of;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/blank.csv";
    EXPECT_ANY_THROW(of.openFile(csv_path));
}

TEST(OpenFile, DoesNotExist){
    OpenFile of;
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/../data/noFile.csv";
    EXPECT_ANY_THROW(of.openFile(csv_path));
}
#endif