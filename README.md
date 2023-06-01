# CS180 Data Detectives MapReduce Library

## Project Description

We have implemented a library of functions to help developers perform MapReduce
operations on unstructured, semi-structured, and structured data. Our MapReduce
library uses parallel processing to speed up execution times and scale well to
large amounts of data.

## Dependencies

This code was compiled and tested using C++ 17. We use CMake and GoogleTest to
test our code. Aside from the C++ standard library, we use
[nlohmann/json](https://github.com/nlohmann/json) as an external dependency.

## Tests

### GoogleTest

To run our full GoogleTest test suite, execute the following commands in the
terminal:

```
$ cd build
$ cmake ..
$ make
$ ./test
```

How to execute Word Counter test:

```
$ cd build
$ cmake ..
$ make
$ ./wordcount
```

## Developer Use

### Step by step guide

Override abstract class IMapReduce with user-defined map and reduce functions

```
std::pair<std::string, int> Map(const std::string& record)

int Reduce(const std::string& key, const std::vector<int>& values)
```

User may initialize Job object to establish configuration values:
mapper & reducer thread count, file count, and file paths
(or default values will be used)

User initializes user-defined IMapReduce and Concurrency objects

User can either use library methods to open and read file(s) or their own in order to return std::vector of strings

```
JsonReader::ReadFile(ifstream &inputFile)
TXTloader::loadTXT(ifstream &inputFile)
CSVLoader::loadCSV(ifstream &inputFile)
```

Calling `runMapReduce(IMapReduce& userMapReduce, const std::vector<std::string>& inputFiles)` will return the resulting std::map of designated <string, int> pairs

