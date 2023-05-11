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

    // Run the map stage.
    std::vector<std::pair<std::string, int>> map_outputs = this->Map(input_data);

    // Print map results
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }

    // Execute the shuffle stage.
    std::map<std::string, std::vector<int>> shuffle_outputs = this->Shuffle(map_outputs);

    // Execute the reduce stage.
    std::map<std::string, int> reduce_outputs = this->Reduce(shuffle_outputs);

    // Print reduce outputs.
    std::cout << "------------------" << std::endl;
    std::cout << "| REDUCE OUTPUTS |" << std::endl;
    std::cout << "------------------" << std::endl;
    for (const auto& [key, value] : reduce_outputs) {
      std::cout << key << std::endl;
      std::cout << "\t" << value << std::endl;
      std::cout << std::endl;
    }
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
    std::cout << "---------------" << std::endl;
    std::cout << "| MAP OUTPUTS |" << std::endl;
    std::cout << "---------------" << std::endl;
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
    std::cout << "-------------------" << std::endl;
    std::cout << "| SHUFFLE OUTPUTS |" << std::endl;
    std::cout << "-------------------" << std::endl;
    for (const auto& [key, value] : shuffled_outputs) {
      std::cout << key << std::endl;
      std::cout << "\t";
      for (const auto& elem : value) {
        std::cout << elem << " ";
      }
      std::cout << std::endl;
    }

    return shuffled_outputs;
  }

  // Reduce function.
  // Aggregate the values for each key using a user-define reduce function.
  // TODO we need to let the user specify this!
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