#include <iostream>
#include "../src/TXTLoader.hpp"

using namespace std;

int main(){
    vector<string> temp;
    TXTloader txtload;

    temp.push_back("../data/example.txt");
    temp.push_back("../data/data1.txt");
    
    vector<string> data = txtload.loadTXT(temp);

    for(int i = 0; i < data.size(); i++){
        cout << data[i] << endl;
    }
    return 0;
}