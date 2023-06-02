#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "OpenFile.hpp"

using namespace std;

class TXTloader{
public:
    vector<string> loadTXT(vector<string> v);
};

vector<string> TXTloader::loadTXT(vector<string> v){
        string s;
        vector<string> lines; 
        ifstream f;
        OpenFile fileopen;

        for(int i = 0; i < v.size(); i++){
            ifstream f = fileopen.openFile(v.at(i));
            while(getline(f, s)){
                if(s.length() != 0){
                    lines.push_back(s);
                }
            }
            f.close();
        }
        return lines;
    }