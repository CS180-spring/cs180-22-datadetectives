// MapReduceEngine.hpp

#ifndef CS180_22_DATADETECTIVES_SRC_MAPREDUCEENGINE_HPP_
#define CS180_22_DATADETECTIVES_SRC_MAPREDUCEENGINE_HPP_

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

    /*
     * First, run the map stage on the input dataset.
     */
    std::vector<std::pair<std::string, int>> map_outputs = this->Map(input_data);

    /*
     * Next, we execute the shuffle stage using the results from the map
     * operation.
     */
    std::map<std::string, std::vector<int>> shuffle_outputs = this->Shuffle(
      map_outputs
    );

    /*
     * Finally, we execute the reduce stage using the shuffled outputs.
     */
    std::map<std::string, int> reduce_outputs = this->Reduce(shuffle_outputs);


    std::this_thread::sleep_for(std::chrono::milliseconds(4300));
    /*
     * Return the output of the reduce operation.
     */
    return reduce_outputs;
  }

  /*
   * Map function definition. All we do here is just run the user-defined map
   * function on each input record and emit the result.
   */
  std::vector<std::pair<std::string, int>> Map(
    const std::vector<std::string>& input_data
  ) {

    /*
     * If the supplied vector is empty, we want to print a warning and then
     * proceed as normal.
     */
    if (input_data.size() == 0) {
      std::cout << "WARNING: Input for Map is not empty." << std::endl;
    }

    /*
     * Run the user-defined Map operation on each input record.
     */
    std::vector<std::pair<std::string, int>> map_outputs;
    for (const auto& record : input_data) {
      map_outputs.push_back(map_reduce_.Map(record));
    }

    /*
     * Return the output of the Map operation.
     */
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

    /*
     * If the supplied vector is empty, we want to print a warning and then
     * proceed as normal.
     */
    if (map_outputs.size() == 0) {
      std::cout << "WARNING: Input for Shuffle is not empty." << std::endl;
    }

    // Group intermediate key-value pairs by key.
    std::map<std::string, std::vector<int>> shuffled_outputs;
    for (const auto& pair : map_outputs) {
      shuffled_outputs[pair.first].push_back(pair.second);
    }

    return shuffled_outputs;
  }

  /*
   * Aggregate the values for each key using a user-defined reduce function.
   */
  std::map<std::string, int> Reduce(
    const std::map<std::string, std::vector<int>>& shuffle_outputs
  ) {

    std::map<std::string, int> reduce_outputs;
    for (const auto& pair : shuffle_outputs) {
      reduce_outputs.emplace(
        pair.first,
        map_reduce_.Reduce(pair.first, pair.second));
    }

    return reduce_outputs;
  }
 
 private:
  IMapReduce& map_reduce_;
};

#endif