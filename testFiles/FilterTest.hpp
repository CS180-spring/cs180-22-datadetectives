/*
 * FilterTest.hpp
 */

#ifndef MAPREDUCE_FILTERTEST_H_
#define MAPREDUCE_FILTERTEST_H_

#include <map>
#include <string>

#include "../src/Filter.hpp"
#include "gtest/gtest.h"

TEST(Filter, FilterValuesLessThan) {

  /*
   * Create a test map with some dummy data.
   */
  std::map<std::string, int> my_map = {
    {"tim", 4},
    {"jane", 2},
    {"bob", 7},
    {"sally", 0},
    {"kim", 9}
  };

  /*
   * Filter out all records with values less than 3 and then filter out all
   * records with values less than 6.
   */
  Filter f;
  f.FilterValuesLessThan(my_map, 3);
  int new_size1 = my_map.size();
  EXPECT_EQ(new_size1, 3) << "New length should be 3, is " << new_size1;
  f.FilterValuesLessThan(my_map, 6);
  int new_size2 = my_map.size();
  EXPECT_EQ(new_size2, 2) << "New length should be 2, is " << new_size2;
}

#endif