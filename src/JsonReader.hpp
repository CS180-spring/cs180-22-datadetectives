// JsonReader.cpp
#include <iostream>
#include <fstream>
#include <vector>
// https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
//#include <nlohmann/json.hpp>
#include "../lib/json.hpp"

using json = nlohmann::json;

class JsonReader {
 public:
  json ReadFile(std::string file_path);
};

json JsonReader::ReadFile(std::string file_path) {

  // Open provided JSON file
  std::ifstream f(file_path);
  json data = json::parse(f);

  // Vector to be returned
  std::vector<json> return_val;

  // Loop through values
  for (auto& element : data) {
    return_val.push_back(element);
  }

  return return_val;
}