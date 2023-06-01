#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class WriteFormat{
  public:
    virtual void writeFile(string fileName, map<string, int>& solution) const = 0;
};

class WriteCSV : public WriteFormat{
  public:
    void writeFile(string fileName, map<string, int>& solution) const override{
      ofstream outFile(fileName);
      if(!outFile){
        cout << fileName << " could not be opened.\n";
      }
      map<string,int>::iterator it;
      for(it = solution.begin(); it != solution.end(); it++){
        outFile << it->first << ',' << it->second << endl;
      }
      outFile.close();
    }
};

class WriteJSON : public WriteFormat{
  public:
    void writeFile(string fileName, map<string, int>& solution) const override{
      ofstream outFile(fileName);
      if(!outFile){
        cout << fileName << " could not be opened.\n";
      }
      map<string,int>::iterator it;
      for(it = solution.begin(); it != solution.end(); it++){
            outFile << "{\"" << it->first << "\": \"" << it->second << "\"}";
            if (std::next(it) != solution.end()) {
                outFile << ",";
            }
            outFile << endl;
      }
      outFile.close();
    }
};

class WriteTXT : public WriteFormat{
  public:
    void writeFile(string fileName, map<string, int>& solution) const override{
      ofstream outFile(fileName);
      if(!outFile){
        cout << fileName << " could not be opened.\n";
      }
      map<string,int>::iterator it;
      for(it = solution.begin(); it != solution.end(); it++){
        outFile << it->first << ',' << it->second << endl;
      }
      outFile.close();
    }
};

class Printer{
  private:
    WriteFormat* writer;
  public:
    Printer(WriteFormat* format): writer(format){};
    void output(string fileName, map<string, int>& solution){
      writer->writeFile(fileName, solution);
    }
};