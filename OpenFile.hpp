#include <fstream>
#include <iostream>

using namespace std;

class OpenFile{
    public:
    ifstream openFile(string inputFile);
};

ifstream openFile(std::string inputFile){
    ifstream iFile(inputFile);
    string s;

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