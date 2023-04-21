#ifndef OPENFILE_TEST_HPP
#define OPENFILE_TEST_HPP

#include "gtest/gtest.h"
#include "OpenFile.hpp"

TEST(OpenFile, RegularFile){
    EXPECT_NO_THROW(openFile("csvTestFiles/normal.csv"));
}

TEST(OpenFile, EmptyFile){
    EXPECT_ANY_THROW(openFile("csvTestFiles/blank.csv"));
}

TEST(OpenFile, DoesNotExist){
    EXPECT_ANY_THROW(openFile("csvTestFiles/noFile.csv"));
}
#endif