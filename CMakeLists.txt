CMAKE_MINIMUM_REQUIRED(VERSION 3.26)
project(CppMapReduce)

SET(CMAKE_CXX_STANDARD 17)
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(tests
	test/test.cpp
)

TARGET_LINK_LIBRARIES(tests gtest)

SET(CMAKE_CXX_STANDARD 11)
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#[[ADD_SUBDIRECTORY(googletest)]]

#[[
ADD_EXECUTABLE(tests
	test/test.cpp
)
]]

ADD_EXECUTABLE(wordcount
	test/WordCountMapReduce.cpp
	src/IMapReduce.hpp
	src/JsonReader.hpp
	src/MapReduceEngine.hpp
)

set_target_properties(wordcount PROPERTIES LINKER_LANGUAGE CXX)

TARGET_LINK_LIBRARIES(tests gtest)
TARGET_COMPILE_DEFINITIONS(tests PRIVATE gtest_disable_pthreads=ON)