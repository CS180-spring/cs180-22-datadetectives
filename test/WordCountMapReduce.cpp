// WordCountMapReduce.hpp

#include <vector>
#include "../src/IMapReduce.hpp"
#include "../src/JsonReader.hpp"
#include "../src/MapReduceEngine.hpp"

// Concrete implementation of the IMapReduce interface
class WordCountMapReduce : public IMapReduce {
 public:

  // Concrete Map implementation
  std::vector<std::pair<std::string, int>> Map(const std::string& filename) override {

    // To store the results of the Map operation
    std::vector<std::pair<std::string, int>> result;

    // Read data from the provided JSON file
    JsonReader my_json_reader = JsonReader();
    std::vector<std::string> data = my_json_reader.ReadFile(filename);

    for (auto& record : data) {
      result.emplace_back(record, 1);
    }

    return result;
  }
};

// Main function
int main() {
  std::vector<std::string> input_files = {"/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/test.json"};

  // Create MapReduce implementation
  WordCountMapReduce word_count_map_reduce;

  // Create MapReduce engine
  MapReduceEngine engine(word_count_map_reduce);

  // Run engine
  engine.Run(input_files);

  return 0;
}