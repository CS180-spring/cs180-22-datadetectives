#ifndef MAPREDUCE_SRC_JOB_H_
#define MAPREDUCE_SRC_JOB_H_

#include <fstream>
#include <iostream>
#include <vector>

/*
 * The Job class handles the number of threads to use, input/output file paths,
 * and other configuration parameters.
 */
class Job {
 private:

  /*
   * By default, there are 2 mapper threads and 1 reducer thread.
   */
  int mappers = 2;
  int reducers = 1;

  int fileCount = 0;
  string outputName = "output.txt";
  std::vector<string> inputPaths;
 public:

  /*
   * Set the number of threads to use when executing the Map operation.
   */
  void setMappers(int m) {

    /*
     * The number of mappers must be a positive number. If it is not, print an
     * error message and return early.
     */
    if (m <= 0) {
      std::cerr << "ERROR: # of mappers should be a positive number." << std::endl;
      return;
    }

    mappers = m;
  };

  /*
   * Set the number of threads to use when executing the Reduce operation.
   */
  void setReducers(int r) {
    reducers = r;
  };
  void addInputPath(string s){inputPaths.push_back(s); ++fileCount;};
  void setOutputPath(string s){outputName = s;};
  int getMappers(){return mappers;};
  int getReducers(){return reducers;};
  int getFileCount(){return fileCount;};
  string getOutputName(){return outputName;};
  vector<string> getPaths(){return inputPaths;};
};

#endif //MAPREDUCE_SRC_JOB_H_