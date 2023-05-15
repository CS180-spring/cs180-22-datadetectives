#include <fstream>
#include <sstream>
#include "WriteJSON.hpp"
#include "WriteCSV.hpp"
#include "WriteTXT.hpp"

using namespace std;

class OutputJob{
    public:
    void writeFile(string fileName, map<string, int> solution);
};

void OutputJob::writeFile(string fileName, map <string,int> solution){
    ofstream outfile(fileName);
    stringstream ss;

    size_t dot = fileName.find_last_of(".");
    if(fileName.substr(dot + 1) == "txt"){
      ss = output_txt(solution);
    }
    else if(fileName.substr(dot + 1) == "csv"){
     ss =  output_csv(solution);
    }
    else if(fileName.substr(dot + 1) == "json"){
      ss = output_json(solution);
    }
    else{
      cout << "Invalid file type\n";
    }

    outfile << ss.str();
    outfile.close();
}