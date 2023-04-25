#include "../src/CSVLoader.hpp"
#include "../src/OpenFile.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main(){
    ifstream input = openFile("extraLines.csv");
    vector<string> contents = loadCSV(input);

    for(int i = 0; i < contents.size(); i++){
        cout << "Line: " << i << " " << contents[i] << endl;
    }

    return 0;
}