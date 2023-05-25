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

TEST(Filter, FilterValuesGreaterThan) {

  /*
   * Create a map with some dummy data.
   */
  std::map<std::string, int> my_map = {
    {"apple", 2},
    {"orange", 6},
    {"cherry", 4},
    {"grape", 9},
    {"mango", 8}
  };

  /*
   * Filter out all records with values greater than 7 and then filter out all
   * records with values greater than 3.
   */
  Filter f;
  f.FilterValuesGreaterThan(my_map, 7);
  int new_size1 = my_map.size();
  EXPECT_EQ(new_size1, 3) << "New length should be 3, is " << new_size1;
  f.FilterValuesGreaterThan(my_map, 3);
  int new_size2 = my_map.size();
  EXPECT_EQ(new_size2, 1) << "New length should be 1, is " << new_size2;
}

TEST(Filter, FilterValuesOutsideRange) {

  /*
   * Create a map with some dummy data.
   */
  std::map<std::string, int> my_map = {
    {"hector", 9},
    {"lalo", 1},
    {"gus", 2},
    {"jimmy", 4},
    {"mike", 7}
  };

  /*
   * Filter out all records with values outside the range 1 to 4. This operation
   * should leave 3 records in the map.
   */
  Filter f;
  f.FilterValuesOutsideRange(my_map, 1, 4);
  int new_size = my_map.size();
  EXPECT_EQ(new_size, 3) << "New length should be 3, is " << new_size;
}

#endif