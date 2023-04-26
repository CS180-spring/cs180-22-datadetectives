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
  void Run(const std::vector<std::string>& input_data) {

    // Map phase
    std::vector<std::pair<std::string, int>> map_outputs;
    for (const auto& record : input_data) {
      map_outputs.push_back(map_reduce_.Map(record));
    }

    // Print map results
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }
  }

 private:
  IMapReduce& map_reduce_;
};

#endif