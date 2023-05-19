/*
 * MapSortTest.cpp
 * This file is just for testing how to sort a map in C++.
 * We don't need this file.
 * Should we let the user sort by key or by value? Both?
 * Can we put the reduce outputs in a vector of pairs instead of a map?
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {

    /*
     * Create a map with some sample data.
     */
    std::map<int, std::string> my_map = {
      {4, "apple"},
      {2, "banana"},
      {6, "orange"},
      {1, "mango"},
      {5, "grape"}
    };

    /*
     * Convert the map to a vector of pairs.
     */
    std::vector<std::pair<int, std::string>> pair_vec;
    std::copy(my_map.begin(), my_map.end(), std::back_inserter(pair_vec));

    /*
     * Sort the vector of pairs based on the first element of each pair.
     */
    std::sort(pair_vec.begin(), pair_vec.end(),
     [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
       return a.first > b.first;
     }
    );

    /*
     * Print the vector of pairs.
     */
    for (const auto& pair : pair_vec) {
      std::cout << pair.first << ": " << pair.second << std::endl;
    }
}