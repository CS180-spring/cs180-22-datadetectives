CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 17)
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(run
	main.cpp
	src/CSVLoader.hpp
    src/OpenFile.hpp
	src/Job.hpp
)

ADD_EXECUTABLE(test
	testFiles/testProg.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)