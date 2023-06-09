// JsonReader.cpp

#ifndef CS180_22_DATADETECTIVES_SRC_JSONREADER_HPP_
#define CS180_22_DATADETECTIVES_SRC_JSONREADER_HPP_

#include <iostream>
#include <fstream>
#include <vector>
// https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
//#include <nlohmann/json.hpp>
#include "../lib/json.hpp"
#include "OpenFile.hpp"

using json = nlohmann::json;

class JsonReader {
 public:
  std::vector<std::string> ReadFile(std::vector<std::string> v);
  void TraverseJson(json data, std::vector<std::string>& temp);
  std::vector<std::string> splitStr(std::vector<std::string> file);
};

std::vector<std::string> JsonReader::ReadFile(std::vector<std::string> v) {

  std::vector<std::string> return_val;
  OpenFile fileopen;
  
  for(int i = 0; i < v.size(); i++){
    //read through the vector for filenames
    std::ifstream f = fileopen.openFile(v.at(i));
    json data = json::parse(f);

    //traverse through one json file and hold values
    // from the file and append to total vector string
    std::vector<std::string> temp;
    TraverseJson(data, temp);
    return_val.insert(return_val.end(), temp.begin(), temp.end());

    f.close();
  }
  return return_val;

  // single file 

  // // Open provided JSON file
  // std::ifstream f(file_path);
  // json data = json::parse(f);

  // // Vector to be returned
  // std::vector<std::string> return_val;

  // // Loop through values
  // for (auto& element : data) {
  //   return_val.push_back(element);
  // }

  // return return_val;
}

void JsonReader::TraverseJson(json data, std::vector<std::string>& temp){
  for(auto& element : data.items()){
    if(element.value().is_object()){
      TraverseJson(element.value(), temp);
    }
    else if(element.value().is_array()){
      for(auto& item : element.value()){
        if(item.is_object()){
          TraverseJson(item, temp);
        }
        else if(item.is_array()){
          TraverseJson(item, temp);
        }
        else if(item.is_number()){
          temp.push_back(std::to_string(static_cast<int>(item)));
        }
        else if(item.is_string()){
          temp.push_back(item);
        }
      }
    }
    else{
      if(element.value().is_number()){
        temp.push_back(std::to_string(static_cast<int>(element.value())));
      }
      else if(element.value().is_string()){
        temp.push_back(element.value());
      }
    }
  }
}

std::vector<std::string> JsonReader::splitStr(std::vector<std::string> file){
  std::vector<std::string> temp;
  std::string word = "";
  auto it = file.begin();
  for(int i = 0; i < file.size(); i = it - file.begin()){
    for (auto x : file[i]){
      if (x == ' '){
        temp.push_back(word);
        word = "";
      }
      else {
        word = word + x;
      }
    }
    temp.push_back(word);

    file.erase(it);
    file.insert(it, temp.begin(), temp.end());

    /*
     * Error here
     */
    //it = std::vector<std::string>::iterator(file[i]);
    it = file.begin() + i;
    advance(it, temp.size());

    temp.clear();
    word = "";
  }
  return file;
}

#endif