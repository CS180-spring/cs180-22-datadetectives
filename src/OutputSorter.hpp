/*
 * OutputSorter.hpp
 */

#ifndef MAPREDUCE_SRC_OUTPUTSORTER_H_
#define MAPREDUCE_SRC_OUTPUTSORTER_H_

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class OutputSorter {
 public:

  /*
   * Utility method to sort a map by key.
   */
  std::vector<std::pair<int, std::string>> sortByKey(const std::map<std::string, int>&);
};

/*
 * Implementation of sortByKey().
 */
std::vector<std::pair<int, std::string>> OutputSorter::sortByKey(const std::map<std::string, int>& my_map) {

  /*
   * Convert the map to a vector of pairs.
   */
  std::vector<std::pair<int, std::string>> pair_vec;
  std::copy(my_map.begin(), my_map.end(), std::back_inserter(pair_vec));

  /*
   * Sort the vector of pairs based on the first element of each pair.
   */
  std::sort(pair_vec.begin(), pair_vec.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {return a.first > b.first;});

  return pair_vec;
}

#endif