// IMapReduce.hpp

#ifndef MAPREDUCE_SRC_IMAPREDUCE_H_
#define MAPREDUCE_SRC_IMAPREDUCE_H_

#include <vector>
#include <string>

// Define the MapReduce interface
class IMapReduce {
public:

  // Virtual mapper method.
  // It is up to the user to implement this method.
  virtual std::pair<std::string, int> Map(const std::string& record) = 0;

  // Virtual reduce method.
  // It is up to the user to implement this method.
  virtual int Reduce(const std::string& key, const std::vector<int>& values) = 0;
};

#endif