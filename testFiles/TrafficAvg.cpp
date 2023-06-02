#include <vector>
#include <utility>  // For std::make_pair()
#include <sstream>
#include <fstream>
#include "../src/IMapReduce.hpp"
#include "../src/MapReduceEngine.hpp"

// Concrete implementation of the IMapReduce interface.
class TrafficAvgMapReduce : public IMapReduce {
 public:

  // Concrete Map implementation.
  std::pair<std::string, int> Map(const std::string& record) override {
    std::stringstream ss(record);
    std::vector<std::string> fields;
    std::string field;
    while (std::getline(ss, field, ',')) {
      fields.push_back(field);
    }

    std::string key = fields[3];  // Modify this line to average over different keys. Using passenger count
    double price = std::stod(fields[4]);  // Using trip distance miles
    int price2 = int(price);
    return std::make_pair(key, price2);
  }

  // Concrete Reduce implementation.
  // Calculate average price for each key.
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    unsigned long int sum = 0;
    for(auto num : values)
     sum += num;
    int size = values.size();
    sum =  (unsigned long int)(sum / size);
    return sum;
  }
};