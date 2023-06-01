#include <vector>
#include <fstream>
#include <string>
#include "OpenFile.hpp"

using namespace std;

class CSVLoader{
    public: 
    vector <string> loadCSV(ifstream &inputFile);
    vector<string> loadMulCSV(vector<string> v);
    vector<string> splitStr(vector<string>& file);
};

vector<string> CSVLoader::loadMulCSV(vector<string> v){
    string s;
    vector<string> lines;
    ifstream f;
    OpenFile fileopen;
    
    for(int i = 0; i < v.size(); i++){
        f = fileopen.openFile(v.at(i));
        while(getline(f, s)){
            if(s.length() != 0){
                lines.push_back(s);
            }
        }
        f.close();
    }
    return lines;
}
//single csv file
vector <string> CSVLoader::loadCSV(ifstream &inputFile){
     string s;
     vector<string>lines;
     while(getline(inputFile,s)){
         if(s.length() != 0){
             lines.push_back(s);
         }
     }
     return lines;
 }

vector<string> CSVLoader::splitStr(vector<string>& file){
  std::vector<std::string> temp;
  std::string word = "";
  auto it = file.begin();
  for(int i = 0; i < file.size(); i = it - file.begin()){
    for (auto x : file[i]){
      if (x == ','){
        temp.push_back(word);
        word = "";
      }
      else {
        word = word + x;
      }
    }
    temp.push_back(word);

    file.erase(it);
    file.insert(it, temp.begin(), temp.end());

    /*
     * Error here
     */
    //it = std::vector<std::string>::iterator(file[i]);
    it = file.begin() + i;
    advance(it, temp.size());

    temp.clear();
    word = "";
  }
  return file;
}