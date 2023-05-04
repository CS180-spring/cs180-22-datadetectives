// MapReduceEngine.hpp

#ifndef MAPREDUCE_SRC_MAPREDUCEENGINE_H_
#define MAPREDUCE_SRC_MAPREDUCEENGINE_H_

#include "IMapReduce.hpp"
#include <iostream>
#include <vector>
#include <string>

class MapReduceEngine {
 public:

  // Constructor
  MapReduceEngine(IMapReduce& map_reduce) : map_reduce_(map_reduce) {}

  // Run function
  std::vector<std::pair<std::string, int>> Run(const std::vector<std::string>& input_data) {

    // Map phase
    std::vector<std::pair<std::string, int>> map_outputs;
    for (const auto& record : input_data) {
      map_outputs.push_back(map_reduce_.Map(record));
    }

    // Print map results.
    std::cout << "MAP OUTPUTS" << std::endl;
    std::cout << "--------" << std::endl;
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }

    // Perform shuffle phase.
    // Here, we group intermediate key-value pairs by key.
    std::map<std::string, std::vector<int>> shuffled_outputs;
    for (const auto& pair : map_outputs) {
      shuffled_outputs[pair.first].push_back(pair.second);
    }

    // Print shuffle phase outputs.
    std::cout << "SHUFFLE OUTPUTS" << std::endl;
    std::cout << "--------" << std::endl;
    for (const auto& [key, value] : shuffled_outputs) {
      std::cout << key << std::endl;
      for (const auto& elem : value) {
        std::cout << "\t" << elem << std::endl;
      }
    }

    return map_outputs;
  }

  // Map function.
  // TODO: write a good description.
  std::vector<std::pair<std::string, int>> Map(const std::vector<std::string>& input_data) {

    // Map phase
    std::vector<std::pair<std::string, int>> map_outputs;
    for (const auto& record : input_data) {
      map_outputs.push_back(map_reduce_.Map(record));
    }

    // Print map results.
    std::cout << "MAP OUTPUTS" << std::endl;
    std::cout << "--------" << std::endl;
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }

    return map_outputs;
  }

  // Shuffle function.
  // This function takes in a std::vector<std::pair<std::string, int>> of map outputs.
  // It outputs a std::map<std::string, std::vector<int>> to be reduced.
  std::map<std::string, std::vector<int>> Shuffle(const std::vector<std::pair<std::string, int>>& map_outputs) {

    // Group intermediate key-value pairs by key.
    std::map<std::string, std::vector<int>> shuffled_outputs;
    for (const auto& pair : map_outputs) {
      shuffled_outputs[pair.first].push_back(pair.second);
    }

    // Print shuffle phase outputs.
    std::cout << "SHUFFLE OUTPUTS" << std::endl;
    std::cout << "--------" << std::endl;
    for (const auto& [key, value] : shuffled_outputs) {
      std::cout << key << std::endl;
      for (const auto& elem : value) {
        std::cout << "\t" << elem << std::endl;
      }
    }

    return shuffled_outputs;
  }

 private:
  IMapReduce& map_reduce_;
};

#endif