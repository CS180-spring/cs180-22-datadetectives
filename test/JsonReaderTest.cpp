// JsonReaderTest.cpp

#include "../src/JsonReader.hpp"
#include <string>

int main() {
    JsonReader my_json_reader = JsonReader();
    std::string data = my_json_reader.ReadFile("/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/test.json");
    std::cout << data << std::endl;
}