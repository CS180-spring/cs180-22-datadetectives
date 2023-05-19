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
   * This function returns a vector of pairs with each element of the vector in the specified sort order.
   */
  std::vector<std::pair<std::string, int>> sortByKey(const std::map<std::string, int>&);
};

/*
 * Implementation of sortByKey().
 */
std::vector<std::pair<std::string, int>> OutputSorter::sortByKey(const std::map<std::string, int>& my_map) {

  /*
   * Convert the map to a vector of pairs.
   */
  std::vector<std::pair<std::string, int>> pair_vec;
  std::copy(my_map.begin(), my_map.end(), std::back_inserter(pair_vec));

  /*
   * Sort the vector of pairs based on the first element of each pair.
   */
  std::sort(pair_vec.begin(), pair_vec.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {return a.first.compare(b.first) < 0;});

  return pair_vec;
}

#endif