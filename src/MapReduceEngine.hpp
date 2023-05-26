// MapReduceEngine.hpp

#ifndef MAPREDUCE_SRC_MAPREDUCEENGINE_H_
#define MAPREDUCE_SRC_MAPREDUCEENGINE_H_

#include "IMapReduce.hpp"
#include "OutputSorter.hpp"

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <map>

class MapReduceEngine {
 public:

  // Constructor
  MapReduceEngine(IMapReduce& map_reduce) : map_reduce_(map_reduce) {}

  // Run function
  std::map<std::string, int> Run(const std::vector<std::string>& input_data) {

    // Run the map stage.
    std::vector<std::pair<std::string, int>> map_outputs = this->Map(input_data);

    // Execute the shuffle stage.
    std::map<std::string, std::vector<int>> shuffle_outputs = this->Shuffle(map_outputs);

    // Execute the reduce stage.
    std::map<std::string, int> reduce_outputs = this->Reduce(shuffle_outputs);

    /*
     * Return the output of the reduce operation.
     */
    return reduce_outputs;
  }

  // Map function.
  // TODO: write a good description.
  std::vector<std::pair<std::string, int>> Map(const std::vector<std::string>& input_data) {

    auto start_time = std::chrono::high_resolution_clock::now();

    // Map phase
    std::vector<std::pair<std::string, int>> map_outputs;
    for (const auto& record : input_data) {
      map_outputs.push_back(map_reduce_.Map(record));
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Map stage duration: " << duration.count() << " ms" << std::endl;

    return map_outputs;
  }

  /*
   * This shuffle function takes in a vector<pair<string, int>> and outputs a
   * map<string, vector<int>> to be reduced. In the shuffle stage, we group each
   * record by key.
   */
  std::map<std::string, std::vector<int>> Shuffle(
    const std::vector<std::pair<std::string, int>>& map_outputs
  ) {

    auto start_time = std::chrono::high_resolution_clock::now();

    // Group intermediate key-value pairs by key.
    std::map<std::string, std::vector<int>> shuffled_outputs;
    for (const auto& pair : map_outputs) {
      shuffled_outputs[pair.first].push_back(pair.second);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Shuffle stage duration: " << duration.count() << " ms" << std::endl;

    return shuffled_outputs;
  }

  // Reduce function.
  // Aggregate the values for each key using a user-define reduce function.
  std::map<std::string, int> Reduce(const std::map<std::string, std::vector<int>>& shuffle_outputs) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::map<std::string, int> reduce_outputs;
    for (const auto& pair : shuffle_outputs) {
      reduce_outputs.emplace(pair.first, map_reduce_.Reduce(pair.first, pair.second));
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Reduce stage duration: " << duration.count() << " ms" << std::endl;

    return reduce_outputs;
  }
 
 private:
  IMapReduce& map_reduce_;
};

#endif