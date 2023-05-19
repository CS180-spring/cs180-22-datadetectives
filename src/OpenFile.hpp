#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class OpenFile{
    public:
    ifstream openFile(string inputFile);
    void openFile(vector<string> inputFiles);  
};

ifstream OpenFile::openFile(std::string inputFile){
    ifstream iFile(inputFile);

    if(!iFile){
        throw runtime_error("Error: Unable to open file " +  inputFile);
    }

    if(iFile.peek() == ifstream::traits_type::eof()){
        throw runtime_error("Error: " +  inputFile + " is empty.");
    }
    else{
        return iFile;
    }
}

void openFile(vector<string> inputFiles){

    for (int i = 0; i < inputFiles.size(); i++){
        ifstream iFile(inputFiles[i]);

        if(!iFile){
            throw runtime_error("Error: Unable to open file " +  inputFiles[i]);
        }

        if(iFile.peek() == ifstream::traits_type::eof()){
            throw runtime_error("Error: " +  inputFiles[i] + " is empty.");
        }

    }
}