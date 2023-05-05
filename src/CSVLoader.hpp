#include <vector>
#include <fstream>
#include <string>

using namespace std;

class CSVLoader{
    public: 
    vector <string> loadCSV(ifstream &inputFile);
    vector<string> loadMulCSV(vector<string> v);
};

vector<string> CSVLoader::loadMulCSV(vector<string> v){
    string s;
    vector<string> lines;
    for(int i = 0; i < v.size(); i++){
        ifstream f(v.at(i));
        while(getline(f, s)){
            if(s.length() != 0){
                lines.push_back(s);
            }
        }
        f.close();
    }
    return lines;
}
// //single csv file
// vector <string> loadCSV(ifstream &inputFile){
//     string s;
//     vector<string>lines;
//     while(getline(inputFile,s)){
//         if(s.length() != 0){
//             lines.push_back(s);
//         }
//     }
//     return lines;
// }
