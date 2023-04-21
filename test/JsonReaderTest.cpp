// JsonReaderTest.cpp

#include "../src/JsonReader.hpp"
#include <string>
#include <vector>
#include "../lib/json.hpp"

using json = nlohmann::json;

int main() {
    JsonReader my_json_reader = JsonReader();
    std::vector<std::string> data = my_json_reader.ReadFile("/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/test.json");
    std::cout << data[0] << std::endl;
    std::cout << data[1] << std::endl;
}