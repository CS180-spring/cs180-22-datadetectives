#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TXTloader{
public:
    vector<string> loadTXT(vector<string> v){
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
};