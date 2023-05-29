/*
 * Test suite for the Shuffle operation.
 */

#ifndef MAPREDUCE_SHUFFLETEST_H_
#define MAPREDUCE_SHUFFLETEST_H_

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
class ShuffleTestMapReduce : public IMapReduce {
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

TEST(Shuffle, ShuffleBasic) {
  
  /*
   * Create a vector with some dummy data.
   */
  std::vector<std::pair<std::string, int>> dummy_data = {
    std::make_pair<std::string, int>("lalo", 2),
    std::make_pair<std::string, int>("gus", 6),
    std::make_pair<std::string, int>("kim", 8),
    std::make_pair<std::string, int>("howard", 3),
    std::make_pair<std::string, int>("howard", 5),
    std::make_pair<std::string, int>("gus", 9)
  };

  /*
   * Create a MapReduce object and run the shuffle stage.
   */
  ShuffleTestMapReduce shuffle_test_map_reduce;
  MapReduceEngine engine(shuffle_test_map_reduce);
  std::map<std::string, std::vector<int>> output = engine.Shuffle(dummy_data);

  /*
   * Test the output of the shuffle for correctness.
   */
  EXPECT_EQ(output["lalo"][0], 2);
  EXPECT_EQ(output["gus"][0], 6);
  EXPECT_EQ(output["gus"][1], 9);
  EXPECT_EQ(output["kim"][0], 8);
  EXPECT_EQ(output["howard"][0], 3);
  EXPECT_EQ(output["howard"][1], 5);
}

#endif