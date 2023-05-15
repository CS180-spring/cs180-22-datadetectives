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
    //create Job to run with default values(M:2,R:1,F:0,O:"output.txt")
    Job mr;
    cout << "JOB CREATED\n";

    //display job info
    cout << "Mappers: " << mr.getMappers() << endl;
    cout << "Reducers: " << mr.getReducers() << endl;
    cout << "Default Output Path: " << mr. getOutputName() << endl << endl;

    //add inputfile to job (CSV & Json)
    string csv_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/data/normal.csv";
    string json_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/data/test.json";
    mr.addInputPath(csv_path);
    mr.addInputPath(json_path);
    cout << "Files Added\n";

    //update output path:
    mr.setOutputPath("mapReduce.txt");
    cout << "Output Path Updated\n\n";

    //ouput path info:
    vector <string> p = mr.getPaths();
    cout << "Total Input Paths: " << mr.getFileCount() << endl;
    for(int i = 0; i < p.size(); i++){
        cout << "Input Path " << i + 1 << ": " << p[i] << endl;
    }
    cout << "Output Path: " << mr.getOutputName() << endl << endl;

    //openFiles
    OpenFile of;
    ifstream csv = of.openFile(p[0]);
    ifstream json = of.openFile(p[1]);
    cout << "Input Files are open\n";

    //readfiles into job
    CSVLoader load;
    JsonReader my_json_reader = JsonReader();
    vector<string> csvContents = load.loadCSV(csv);
    //vector<string> jsonContents = my_json_reader.ReadFile(p[1]);
    cout << "Files have been read\n\n";

    //output contents for both files
    cout << "File contents for " << p[0] << ":\n";
    for(int i = 0; i < csvContents.size(); i++){
        cout << "Line " << i + 1 << ": " << csvContents[i]<< endl;
    }
    
    /*cout << "\nFile contents for " << p[1] << ":\n";
    for(int i = 0; i < jsonContents.size(); i++){
        cout << "Line " << i + 1 << ": " << jsonContents[i]<< endl;
    }*/

    return 0;
}