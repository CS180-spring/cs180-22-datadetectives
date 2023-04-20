// JsonReader.cpp
#include <iostream>
#include <fstream>
// https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
//#include <nlohmann/json.hpp>
#include "../lib/json.hpp"

using namespace std;
using json = nlohmann::json;

class JsonReader {
 public:
  string ReadFile(string file_path);
};

string JsonReader::ReadFile(string file_path) {

  // Open provided JSON file
  ifstream f(file_path);
  json data = json::parse(f);

  // String to be returned
  string return_val = "";

  // Loop through keys
  for (auto& element : data) {
    cout << element << endl;
    return_val += element;
  }

  return return_val;
}