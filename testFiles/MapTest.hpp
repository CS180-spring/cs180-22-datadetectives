/*
 * Test suite for the Map operation.
 */

#ifndef MAPREDUCE_TESTFILES_MAPTEST_H_
#define MAPREDUCE_TESTFILES_MAPTEST_H_

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

}

#endif