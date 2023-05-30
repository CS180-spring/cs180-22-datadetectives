/*
 * MapReduceEngine.cpp
 */

#include "src/MapReduceEngine.hpp"

#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <map>

std::map<std::string, int> MapReduceEngine::Run(
  const std::vector<std::string>& input_data
) {

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

  /*
   * Return the output of the reduce operation.
   */
  return reduce_outputs;
}