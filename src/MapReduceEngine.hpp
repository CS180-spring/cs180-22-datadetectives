// MapReduceEngine.hpp

#ifndef MAPREDUCE_SRC_MAPREDUCEENGINE_H_
#define MAPREDUCE_SRC_MAPREDUCEENGINE_H_

#include "IMapReduce.hpp"
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
  std::vector<std::pair<std::string, int>> Run(const std::vector<std::string>& input_data) {

    // Run the map stage.
    std::vector<std::pair<std::string, int>> map_outputs = this->Map(input_data);

    // Execute the shuffle stage.
    std::map<std::string, std::vector<int>> shuffle_outputs = this->Shuffle(map_outputs);

    // Execute the reduce stage.
    std::map<std::string, int> reduce_outputs = this->Reduce(shuffle_outputs);
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

    // Print map results.
    /*
    std::cout << "---------------" << std::endl;
    std::cout << "| MAP OUTPUTS |" << std::endl;
    std::cout << "---------------" << std::endl;
    for (const auto& record : map_outputs) {
      std::cout << record.first << ": " << record.second << std::endl;
    }
    */
/*
    // This line waits for 1 second.
    // For testing purposes only.
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(1405619385));

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Map stage duration: " << duration.count() << " ms" << std::endl;
*/
    return map_outputs;
  }

  // Shuffle function.
  // This function takes in a std::vector<std::pair<std::string, int>> of map outputs.
  // It outputs a std::map<std::string, std::vector<int>> to be reduced.
  std::map<std::string, std::vector<int>> Shuffle(const std::vector<std::pair<std::string, int>>& map_outputs) {

    auto start_time = std::chrono::high_resolution_clock::now();

    // Group intermediate key-value pairs by key.
    std::map<std::string, std::vector<int>> shuffled_outputs;
    for (const auto& pair : map_outputs) {
      shuffled_outputs[pair.first].push_back(pair.second);
    }

    // Print shuffle phase outputs.
    /*
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
    */

/*
    // This line waits for 1 second.
    // For testing purposes only.
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(9481958320));

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Shuffle stage duration: " << duration.count() << " ms" << std::endl;
*/
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

    // Print reduce outputs.
    std::cout << "------------------" << std::endl;
    std::cout << "| REDUCE OUTPUTS |" << std::endl;
    std::cout << "------------------" << std::endl;
    for (const auto& [key, value] : reduce_outputs) {
      std::cout << key << std::endl;
      std::cout << "\t" << value << std::endl;
      std::cout << std::endl;
    }
/*
    // This line waits for 1 second.
    // For testing purposes only.
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(3912093476));

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Reduce stage duration: " << duration.count() << " ms" << std::endl;
*/
    return reduce_outputs;
  }
 
 private:
  IMapReduce& map_reduce_;
};

#endif