/*
 * Filter.hpp
 * A helper class to filter the output of a MapReduce job.
 */

#ifndef MAPREDUCE_SRC_FILTER_H_
#define MAPREDUCE_SRC_FILTER_H_

#include <map>
#include <string>

class Filter {
 public:

  /*
   * Filter out all records where the value is less than a given lower bound.
   */
  void FilterValuesLessThan(std::map<std::string, int>&, int);

  /*
   * Filter out all records where the value is greater than a given upper bound.
   */
  void FilterValuesGreaterThan(std::map<std::string, int>&, int);

  /*
   * Filter out all records that aren't within a given range. The first int
   * argument is the lower bound and the second int argument is the upper bound.
   */
  void FilterValuesOutsideRange(std::map<std::string, int>&, int, int);

  /*
   * Filter out all the keys present in the supplied vector.
   */
  void FilterKeys(std::map<std::string, int>&, std::vector<std::string>);

  /*
   * Keep all the keys present in the supplied vector and filter out the rest.
   */
  void KeepKeys(std::map<std::string, int>&, std::vector<std::string>);
};

void Filter::FilterValuesLessThan(
  std::map<std::string, int>& my_map,
  int lower_bound
) {

  /*
   * Iterate through the map and erase any records that don't satisfy the
   * condition.
   */
  for (auto my_iter = my_map.begin(); my_iter != my_map.end();) {
    if (my_iter->second < lower_bound) {
      my_iter = my_map.erase(my_iter);
    } else {
      my_iter++;
    }
  }
}

void Filter::FilterValuesGreaterThan(
  std::map<std::string, int>& my_map,
  int upper_bound
) {
  
  /*
   * Iterate through the map and erase any records that don't satisfy the
   * condition.
   */
  for (auto my_iter = my_map.begin(); my_iter != my_map.end();) {
    if (my_iter->second > upper_bound) {
      my_iter = my_map.erase(my_iter);
    } else {
      my_iter++;
    }
  }
}

void Filter::FilterValuesOutsideRange(
  std::map<std::string, int>& my_map,
  int lower_bound,
  int upper_bound
) {

  /*
   * Iterate through the map and erase any records that don't satisfy the
   * condition.
   */
  for (auto my_iter = my_map.begin(); my_iter != my_map.end();) {
    if (my_iter->second < lower_bound || my_iter->second > upper_bound) {
      my_iter = my_map.erase(my_iter);
    } else {
      my_iter++;
    }
  }
}

#endif