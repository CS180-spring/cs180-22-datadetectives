#include <vector>
#include <fstream>
#include <string>

using namespace std;

class CSVLoader{
    public: 
    vector <string> loadCSV(ifstream &inputFile);
};

vector <string> loadCSV(ifstream &inputFile){
    string s;
    vector<string>lines;
    while(getline(inputFile,s)){
        if(s.length() != 0){
            lines.push_back(s);
        }
    }
    return lines;
}

