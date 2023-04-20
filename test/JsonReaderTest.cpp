// JsonReaderTest.cpp

#include "../src/JsonReader.hpp"
#include <string>

using namespace std;

int main() {
    JsonReader my_json_reader = JsonReader();
    string data = my_json_reader.ReadFile("/Users/vinayakgajjewar/Documents/Schoolwork/CS180/cs180-22-datadetectives/data/test.json");
    cout << data << endl;
}