/*
 * SequentialTempAvgTest.hpp
 * End-to-end testing for our MapReduce framework without multiprocessing.
 */

#ifndef CS180_22_DATADETECTIVES_TESTFILES_SEQUENTIALTEMPAVGTEST_HPP_
#define CS180_22_DATADETECTIVES_TESTFILES_SEQUENTIALTEMPAVGTEST_HPP_

#include "gtest/gtest.h"

#include <vector>
#include <utility>
#include <sstream>
#include <fstream>
#include "../src/IMapReduce.hpp"
#include "../src/JsonReader.hpp"
#include "../src/MapReduceEngine.hpp"
#include "../src/JsonReader.hpp"

/*
 * Define a concrete MapReduce implementation that averages over date.
 */
class TempAvgMapReduceTestOverDate : public IMapReduce {
 public:

  // Concrete Map implementation.
  std::pair<std::string, int> Map(const std::string& record) override {
    std::stringstream ss(record);
    std::vector<std::string> fields;
    std::string field;
    while (std::getline(ss, field, ',')) {
      fields.push_back(field);
    }

    std::string key = fields[1];  // Modify this line to average over different keys.
    int temperature = std::stoi(fields[3]);  // Modify this line to average highest or lowest temp.
    return std::make_pair(key, temperature);
  }

  /*
   * Define a concrete Reduce implementation. This function calculates the
   * average temperature for each key.
   */
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0) / values.size();
  }
};

/*
 * Define a concrete MapReduce implementation that averages over location.
 */
class TempAvgMapReduceTestOverLoc : public IMapReduce {
 public:

  // Concrete Map implementation.
  std::pair<std::string, int> Map(const std::string& record) override {
    std::stringstream ss(record);
    std::vector<std::string> fields;
    std::string field;
    while (std::getline(ss, field, ',')) {
      fields.push_back(field);
    }

    std::string key = fields[0];  // Modify this line to average over different keys.
    int temperature = std::stoi(fields[3]);  // Modify this line to average highest or lowest temp.
    return std::make_pair(key, temperature);
  }

  // Concrete Reduce implementation.
  // Calculate average temperature for each key.
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0) / values.size();
  }
};

TEST(SequentialTempAvgTest, AvgOverDate) {

  // Read data from JSON
  std::string data_path = "../data/temp_data.txt";
  std::ifstream in_file;
  in_file.open(data_path);
  if (!in_file) {
    std::cerr << "ERROR: Unable to open data file." << std::endl;
    exit(1);
  }
  std::string x;
  std::vector<std::string> data;
  while (in_file >> x) {
    //std::cout << x << std::endl;
    data.push_back(x);
  }
  in_file.close();

  // Create MapReduce implementation
  TempAvgMapReduceTestOverDate temp_avg_map_reduce;

  // Create MapReduce engine
  MapReduceEngine engine(temp_avg_map_reduce);

  /*
   * Run MapReduce sequentially and collect the results.
   */
  std::map<std::string, int> mr_results = engine.Run(data);

  /*
   * Test output map for correctness.
   */
  EXPECT_EQ(mr_results["5-12-23"], 77);
  EXPECT_EQ(mr_results["5-13-23"], 84);
  EXPECT_EQ(mr_results["5-14-23"], 82);
  EXPECT_EQ(mr_results["5-15-23"], 81);
  EXPECT_EQ(mr_results["5-16-23"], 82);
  EXPECT_EQ(mr_results["5-17-23"], 82);
  EXPECT_EQ(mr_results["5-18-23"], 78);
  EXPECT_EQ(mr_results["5-19-23"], 77);
  EXPECT_EQ(mr_results["5-20-23"], 79);
  EXPECT_EQ(mr_results["5-21-23"], 82);
}

TEST(SequentialTempAvgTest, AvgOverLoc) {

  // Read data from JSON
  std::string data_path = "../data/temp_data.txt";
  std::ifstream in_file;
  in_file.open(data_path);
  if (!in_file) {
    std::cerr << "ERROR: Unable to open data file." << std::endl;
    exit(1);
  }
  std::string x;
  std::vector<std::string> data;
  while (in_file >> x) {
    //std::cout << x << std::endl;
    data.push_back(x);
  }
  in_file.close();

  // Create MapReduce implementation
  TempAvgMapReduceTestOverLoc temp_avg_map_reduce;

  /*
   * Create an instance of the MapReduce engine.
   */
  MapReduceEngine engine(temp_avg_map_reduce);

  /*
   * Run the sequential MapReduce engine and collect the results.
   */
  std::map<std::string, int> mr_results = engine.Run(data);

  /*
   * Test the MapReduce output for correctness.
   */
  EXPECT_EQ(mr_results["goleta"], 76);
  EXPECT_EQ(mr_results["riverside"], 86);
  EXPECT_EQ(mr_results["saratoga"], 81);
  EXPECT_EQ(mr_results["sunnyvale"], 79);
}

#endif