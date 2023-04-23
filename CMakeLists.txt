CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(CMAKE_CXX_STANDARD 17)

project(CppMapReduce)

ADD_EXECUTABLE(loader
	main.cpp
	CSVLoader.hpp
    OpenFile.hpp
)

ADD_EXECUTABLE(wordcount
	test/WordCountMapReduce.cpp
	src/IMapReduce.hpp
	src/JsonReader.hpp
	src/MapReduceEngine.hpp
)

set_target_properties(wordcount PROPERTIES LINKER_LANGUAGE CXX)