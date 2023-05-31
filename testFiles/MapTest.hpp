/*
 * Test suite for the Map operation.
 */

#ifndef CS180_22_DATADETECTIVES_TESTFILES_MAPTEST_HPP_
#define CS180_22_DATADETECTIVES_TESTFILES_MAPTEST_HPP_

#include "gtest/gtest.h"
#include "../src/MapReduceEngine.hpp"
#include <numeric>
#include <vector>
#include <iostream>
#include <string>
#include <map>

/*
 * Concrete implementation of the IMapReduce interface for testing purposes.
 */
class MapTestMapReduce : public IMapReduce {
 public:

  /*
   * Define a concrete Map implementation. For each record, it just emits
   * (record, 1).
   */
  std::pair<std::string, int> Map(const std::string& record) override {

    return std::make_pair(record, 1);
  }

  // Concrete Reduce implementation
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0);
  }
};

TEST(Map, MapBasic) {

  /*
   * Create a vector with some test data.
   */
  std::vector<std::string> data = {
    "jimmy",
    "nacho",
    "kim",
    "chuck",
    "howard"
  };

  /*
   * Run the Map operation on the test data.
   */
  MapTestMapReduce map_test_map_reduce;
  MapReduceEngine engine(map_test_map_reduce);
  std::vector<std::pair<std::string, int>> output = engine.Map(data);

  /*
   * Test the output of the map for correctness.
   */
  EXPECT_EQ(output.size(), 5);
  EXPECT_EQ(output[0].first, "jimmy");
  EXPECT_EQ(output[0].second, 1);
  EXPECT_EQ(output[1].first, "nacho");
  EXPECT_EQ(output[1].second, 1);
  EXPECT_EQ(output[2].first, "kim");
  EXPECT_EQ(output[2].second, 1);
  EXPECT_EQ(output[3].first, "chuck");
  EXPECT_EQ(output[3].second, 1);
  EXPECT_EQ(output[4].first, "howard");
  EXPECT_EQ(output[4].second, 1);
}

TEST(Map, MapEmpty) {

  /*
   * Create an empty vector.
   */
  std::vector<std::string> empty = {};

  /*
   * Run the map operation on the empty vector.
   */
  MapTestMapReduce map_test_map_reduce;
  MapReduceEngine engine(map_test_map_reduce);
  std::vector<std::pair<std::string, int>> output = engine.Map(empty);

  /*
   * If an empty vector is passed into the map function, we don't want to throw
   * an error. We just want to print a warning and return an empty vector.
   */
  EXPECT_EQ(output.size(), 0);
}

#endif