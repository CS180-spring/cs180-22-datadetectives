// WordCountMapReduce.cpp

#include <vector>
#include <utility>  // For std::make_pair()
#include "../src/IMapReduce.hpp"
#include "../src/JsonReader.hpp"
#include "../src/MapReduceEngine.hpp"
#include "../src/JsonReader.hpp"

// Concrete implementation of the IMapReduce interface
class WordCountMapReduce : public IMapReduce {
 public:

  // Concrete Map implementation
  std::pair<std::string, int> Map(const std::string& record) override {

    return std::make_pair(record, 1);
  }

  // Concrete Reduce implementation
  int Reduce(const std::string& key, const std::vector<int>& values) override {
    return std::accumulate(values.begin(), values.end(), 0);
  }
};

// Main function
int main() {

  // Read data from JSON
  std::string input_file = "/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/test.json";
  JsonReader wc_json_reader = JsonReader();
  std::vector<std::string> data = wc_json_reader.ReadFile({input_file});

  // Create MapReduce implementation
  WordCountMapReduce word_count_map_reduce;

  // Create MapReduce engine
  MapReduceEngine engine(word_count_map_reduce);

  // Run engine
  engine.Run(data);

  return 0;
}