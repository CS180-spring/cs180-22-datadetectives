// JsonReaderTest.cpp

#include "../src/JsonReader.hpp"
#include <string>
#include <vector>

using json = nlohmann::json;

int main() {
    JsonReader my_json_reader = JsonReader();
    std::vector<std::string> v;
    v.push_back("../data/data.json");

    // v.push_back("../jsonTestFiles/blank.json");

    std::vector<std::string> data = my_json_reader.ReadFile(v);

    for(int i = 0; i < data.size(); i++){
        std::cout << data[i] << std::endl;
    }
}

// JsonReaderTest.cpp

// #include "../src/JsonReader.hpp"
// #include <string>
// #include <vector>
// #include "../lib/json.hpp"

// using json = nlohmann::json;

// int main() {
//     JsonReader my_json_reader = JsonReader();
//     std::vector<std::string> data = my_json_reader.ReadFile("../data/test.json");
//     std::cout << data[0] << std::endl;
//     std::cout << data[1] << std::endl;
// }

