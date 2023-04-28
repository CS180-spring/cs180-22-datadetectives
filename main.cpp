#include "src/CSVLoader.hpp"
#include "src/OpenFile.hpp"
#include "src/Job.hpp"
#include "src/JsonReader.hpp"
#include "src/ReadBytes.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main(){
    string file = "normal.csv";
    Job j;

    j.addInputPath(file);
    j.setMappers(4);
    j.setReducers(2);
    j.setOutputPath("jobOutput.txt");


    return 0;
}