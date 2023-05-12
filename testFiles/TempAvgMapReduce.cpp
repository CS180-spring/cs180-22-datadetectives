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

    std::string date = fields[0];
    int temperature = std::stoi(fields[3]);
    return std::make_pair(date, temperature);
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
    std::cout << x << std::endl;
    data.push_back(x);
  }
  in_file.close();

  // Create MapReduce implementation
  TempAvgMapReduce temp_avg_map_reduce;

  // Create MapReduce engine
  MapReduceEngine engine(temp_avg_map_reduce);

  // Run engine
  engine.Run(data);

  return 0;
}