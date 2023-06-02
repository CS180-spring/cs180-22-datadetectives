/*
 * OutputSorterTest.cpp
 * Test harness for the OutputSorter class
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../src/OutputSorter.hpp"

int main() {

  /*
   * Initialize a test map.
   */
  std::map<std::string, int> my_map = {
    {"apple", 4},
    {"banana", 2},
    {"orange", 6},
    {"mango", 1},
    {"grape", 5}
  };

  /*
   * Initialize OutputSorter class and sort by key.
   */
  OutputSorter os = OutputSorter();
  std::vector<std::pair<std::string, int>> sorted_vec = os.sortByValue(my_map, true);

  /*
   * Print vector contents.
   */
  for (const auto& pair: sorted_vec) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}