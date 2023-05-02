#ifndef OPENFILE_TEST_HPP
#define OPENFILE_TEST_HPP

#include "gtest/gtest.h"
#include "../src/OpenFile.hpp"

TEST(OpenFile, RegularFile){
    EXPECT_NO_THROW(openFile("../normal.csv"));
}

TEST(OpenFile, EmptyFile){
    EXPECT_ANY_THROW(openFile("../data/blank.csv"));
}

TEST(OpenFile, DoesNotExist){
    EXPECT_ANY_THROW(openFile("../data/noFile.csv"));
}
#endif