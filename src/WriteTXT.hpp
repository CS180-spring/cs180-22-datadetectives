#include <sstream>
#include <iostream>
#include <map> 

using namespace std;

class WriteTXT{
    public:
    stringstream output_txt(map<string, int> solution);
};

stringstream output_txt(map <string,int> solution){
    stringstream ss;
    map<string,int>::iterator it;
    for(it = solution.begin(); it != solution.end(); it++){
      ss << it->first << ',' << it->second << std::endl;
    }
    return ss;
}