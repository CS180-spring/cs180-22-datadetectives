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
   * This function returns a vector of pairs with each element of the vector in
   * the specified sort order. If the boolean value is true, it will sort in
   * ascending order. If it is false, it will sort in descending order.
   */
  std::vector<std::pair<std::string, int>> sortByKey(
    const std::map<std::string, int>&,
    bool
  );

  /*
   * Utility method to sort a map by value.
   */
  std::vector<std::pair<std::string, int>> sortByValue(
    const std::map<std::string, int>&,
    bool
  );
};

/*
 * Implementation of sortByKey().
 */
std::vector<std::pair<std::string, int>> OutputSorter::sortByKey(
  const std::map<std::string, int>& my_map,
  bool ascending
) {

  /*
   * Convert the map to a vector of pairs.
   */
  std::vector<std::pair<std::string, int>> pair_vec;
  std::copy(my_map.begin(), my_map.end(), std::back_inserter(pair_vec));

  /*
   * Sort the vector of pairs based on the first element of each pair.
   * This is lazy coding but I am tired.
   */
  if (ascending) {
    std::sort(pair_vec.begin(), pair_vec.end(), [](
      const std::pair<std::string, int>& a,
      const std::pair<std::string, int>& b
      ) {
        return a.first.compare(b.first) < 0;
      });
  } else {
    std::sort(pair_vec.begin(), pair_vec.end(), [](
      const std::pair<std::string, int>& a,
      const std::pair<std::string, int>& b
      ) {
        return b.first.compare(a.first) < 0;
      });
  }
  return pair_vec;
}

/*
 * Implementation of sortByValue().
 */
std::vector<std::pair<std::string, int>> OutputSorter::sortByValue(
  const std::map<std::string, int>& my_map,
  bool ascending
) {

  /*
   * Convert the map to a vector of pairs.
   */
  std::vector<std::pair<std::string, int>> pair_vec;
  std::copy(my_map.begin(), my_map.end(), std::back_inserter(pair_vec));

  /*
   * Sort the vector of pairs based on the first element of each pair.
   * This is lazy coding but I am tired.
   */
  if (ascending) {
    std::sort(pair_vec.begin(), pair_vec.end(), [](
      const std::pair<std::string, int>& a,
      const std::pair<std::string, int>& b
      ) {
        return a.second < b.second;
      });
  } else {
    std::sort(pair_vec.begin(), pair_vec.end(), [](
      const std::pair<std::string, int>& a,
      const std::pair<std::string, int>& b
    ) {
      return b.second < a.second;
    });
  }
  return pair_vec;
}
#endif