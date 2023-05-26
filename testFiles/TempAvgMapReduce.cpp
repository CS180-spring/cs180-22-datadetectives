/*
 * TempAvgMapReduce.cpp
 * This file contains an implementation of the IMapReduce interface.
 */

#include <vector>
#include <utility>  // For std::make_pair()
#include <sstream>
#include <fstream>
#include "../src/IMapReduce.hpp"
#include "../src/JsonReader.hpp"
#include "../src/MapReduceEngine.hpp"
#include "../src/JsonReader.hpp"

// Concrete implementation of the IMapReduce interface.
class TempAvgMapReduce : public IMapReduce {
 public:

  // Concrete Map implementation.
  std::pair<std::string, int> Map(const std::string& record) override {
    std::stringstream ss(record);
    std::vector<std::string> fields;
    std::string field;
    while (std::getline(ss, field, ',')) {
      fields.push_back(field);
    }

    std::string key = fields[1];  // Modify this line to average over different keys.
    int temperature = std::stoi(fields[3]);  // Modify this line to average highest or lowest temp.
    return std::make_pair(key, temperature);
  }

  // Concrete Reduce implementation.
  // Calculate average temperature for each key.
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0) / values.size();
  }
};

// Main function
int main() {

  // Read data from JSON
  std::string data_path = "/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/temp_data.txt";
  std::ifstream in_file;
  in_file.open(data_path);
  if (!in_file) {
    std::cerr << "ERROR: Unable to open data file." << std::endl;
    exit(1);
  }
  std::string x;
  std::vector<std::string> data;
  while (in_file >> x) {
    //std::cout << x << std::endl;
    data.push_back(x);
  }
  in_file.close();

  // Create MapReduce implementation
  TempAvgMapReduce temp_avg_map_reduce;

  // Create MapReduce engine
  MapReduceEngine engine(temp_avg_map_reduce);

  /*
   * Run MapReduce engine and print outputs.
   */
  std::map<std::string, int> mr_results = engine.Run(data);
  for (auto& record : mr_results) {
    std::cout << record.first << ": " << record.second << std::endl;
  }

  return 0;
}