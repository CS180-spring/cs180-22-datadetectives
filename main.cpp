#include <iostream>
#include "splitting.h"

using namespace std;

int main(){
    splittingJSON testCorrect("test/splittingCorrect.json");
    testCorrect.printData();

    // splittingJSON testEmpty("test/splittingEmpty.json");
    // testEmpty.printData();

    splittingJSON testWhatJsonFile("test/splittingWhatJsonFile.json");
    
}