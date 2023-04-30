# Project-CS180 Map-Reduce Framework Library

## Dependencies

This code was compiled and tested using C++ 17.

## Tests

How to execute Word Counter test:

```
$ cd build
$ cmake ..
$ make
$ ./wordcount
```

Command to execute JSON reader test:

```
$ g++ test/JsonReaderTest.cpp -std=c++17 && ./a.out
```

Implementing a library of functions to perform Map-Reduce on unstructured data for developers. Functionality to read CSV and JSON files as well as determine the amount of bytes and time it takes to read these files and split them is currently implemented. 
