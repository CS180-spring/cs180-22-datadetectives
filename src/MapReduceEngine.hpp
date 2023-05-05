// MapReduceEngine.hpp

#ifndef MAPREDUCE_SRC_MAPREDUCEENGINE_H_
#define MAPREDUCE_SRC_MAPREDUCEENGINE_H_

#include "IMapReduce.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

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

    // Print map results
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }

    return map_outputs;
  }


  std::map<std::string, int> Reduce(const std::map<std::string, std::vector<int>> &pairedValues){
    std::string key = pairedValues.begin()->first;
    std::vector<int> values = pairedValues.at(key);

    int total = 0;
    for(int i = 0; i < values.size(); i++){
        total += values[i];
    }

    std::map<std::string, int> reducedKeyValue;
    reducedKeyValue[key] = total;
    return reducedKeyValue; 
  }
 private:
  IMapReduce& map_reduce_;
};

#endif