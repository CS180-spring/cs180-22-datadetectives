#include <sstream>
#include <iostream>
#include <map> 

using namespace std;

class WriteJSON{
    public:
    stringstream output_json(map<string, int> solution);
};

stringstream output_json(map <string,int> solution){
    stringstream ss;
    map<string,int>::iterator it;
    for(it = solution.begin(); it != solution.end(); it++){
            ss << "{\"" << it->first << "\": \"" << it->second << "\"}";
            if (std::next(it) != solution.end()) {
                ss << ",";
            }
            ss << endl;
    }
    return ss;
}