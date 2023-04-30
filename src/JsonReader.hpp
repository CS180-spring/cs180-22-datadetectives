// JsonReader.hpp

#ifndef MAPREDUCE_SRC_JSONREADER_H_
#define MAPREDUCE_SRC_JSONREADER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
// https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
//#include <nlohmann/json.hpp>
#include "../lib/json.hpp"

using json = nlohmann::json;

class JsonReader {
 public:
  std::vector<std::string> ReadFile(std::string file_path);
};

std::vector<std::string> JsonReader::ReadFile(std::string file_path) {

  // Open provided JSON file
  std::ifstream f(file_path);
  json data = json::parse(f);

  // Vector to be returned
  std::vector<std::string> return_val;

  // Loop through values
  for (auto& element : data) {

    std::stringstream ss;
    ss.str(element);
    std::string word;

    while (ss >> word) {
      word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());
      std::transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c); });
      return_val.push_back(word);
    }
  }

  return return_val;
}

#endif