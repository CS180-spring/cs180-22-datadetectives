

CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

project(CS180DataDetectivesMapReduce)

SET(CMAKE_CXX_STANDARD 17)
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(googletest)

#ADD_EXECUTABLE(run
#	main.cpp
#	src/CSVLoader.hpp
#    src/OpenFile.hpp
#	src/Job.hpp
#)

ADD_EXECUTABLE(test
	testFiles/testProg.cpp
)

ADD_EXECUTABLE(wordcount
	testFiles/WordCountMapReduce.cpp
	src/IMapReduce.hpp
	src/JsonReader.hpp
	src/MapReduceEngine.hpp
)

set_target_properties(wordcount PROPERTIES LINKER_LANGUAGE CXX)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)