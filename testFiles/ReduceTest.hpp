/*
 * ReduceTest.hpp
 * This file contains a test suite for the Reduce operation.
 */

#ifndef MAPREDUCE_TESTFILES_REDUCETEST_H_
#define MAPREDUCE_TESTFILES_REDUCETEST_H_

#include "gtest/gtest.h"
#include "../src/MapReduceEngine.hpp"
#include <numeric>
#include <vector>
#include <string>
#include <map>

/*
 * Concrete implementation of the IMapReduce interface for testing Reduce
 * functionality.
 */
class ReduceTestMapReduce : public IMapReduce {
 public:

  // Concrete Map implementation
  std::pair<std::string, int> Map(const std::string& record) override {

    return std::make_pair(record, 1);
  }

  // Concrete Reduce implementation
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0);
  }
};

TEST(Reduce, ReduceBasic) {

  /*
   * Create a vector with some dummy data. This data simulates the output of a
   * shuffle operation.
   */
  std::map<std::string, std::vector<int>> dummy_data = {
    std::make_pair<std::string, std::vector<int>>("lalo", {2, 4, 7}),
    std::make_pair<std::string, std::vector<int>>("gus", {9, 3, 6}),
    std::make_pair<std::string, std::vector<int>>("kim", {0, 3, 5}),
    std::make_pair<std::string, std::vector<int>>("howard", {9, 1, 2}),
    std::make_pair<std::string, std::vector<int>>("chuck", {5, 3, 2})
  };

  /*
   * Create a MapReduce object and run the Reduce stage on the dummy data.
   */
  ReduceTestMapReduce reduce_test_map_reduce;
  MapReduceEngine engine(reduce_test_map_reduce);
  std::map<std::string, int> output = engine.Reduce(dummy_data);

  /*
   * Test the output of the reduce for correctness.
   */
  EXPECT_EQ(output["lalo"], 13);
  EXPECT_EQ(output["gus"], 18);
  EXPECT_EQ(output["kim"], 8);
  EXPECT_EQ(output["howard"], 12);
  EXPECT_EQ(output["chuck"], 10);
}

#endif