// JsonReader.cpp
#include <iostream>
#include <fstream>
// https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
//#include <nlohmann/json.hpp>
#include "../lib/json.hpp"

using json = nlohmann::json;

class JsonReader {
 public:
  std::string ReadFile(std::string file_path);
};

std::string JsonReader::ReadFile(std::string file_path) {

  // Open provided JSON file
  std::ifstream f(file_path);
  json data = json::parse(f);

  // String to be returned
  std::string return_val = "";

  // Loop through values
  for (auto& element : data) {
    return_val += element;
    return_val += " ";
  }

  return return_val;
}