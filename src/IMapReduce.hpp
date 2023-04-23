// IMapReduce.hpp
#pragma once

#include <vector>
#include <string>

// Define the MapReduce interface
class IMapReduce {
public:

  // Virtual mapper method
  virtual std::vector<std::pair<std::string, int>> Map(const std::string& filename) = 0;
};