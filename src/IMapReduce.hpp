// IMapReduce.hpp

#ifndef MAPREDUCE_SRC_IMAPREDUCE_H_
#define MAPREDUCE_SRC_IMAPREDUCE_H_

#include <vector>
#include <string>

// Define the MapReduce interface
class IMapReduce {
public:

  // Virtual mapper method
  virtual std::pair<std::string, int> Map(const std::string& record) = 0;
};

#endif