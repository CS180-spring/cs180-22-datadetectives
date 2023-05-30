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

#define library
ADD_LIBRARY(mylibrary STATIC
	src/CSVLoader.hpp
	src/IMapReduce.hpp
	src/JsonReader.hpp
	src/MapReduceEngine.hpp
	src/TXTLoader.hpp
	src/ReadBytes.h
	src/OutputJob.hpp
	src/WriteCSV.hpp
	src/WriteJSON.hpp
	src/WriteTXT.hpp
	src/Job.hpp
	src/Concurrency.hpp
	src/csvSplitter.hpp
	src/OpenFile.hpp
)

#specifying directories
target_include_directories(mylibrary
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#install library
install(TARGETS mylibrary
    EXPORT MyLibraryTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

#instill header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/ DESTINATION include)

#cmake export
install(EXPORT mylibraryTargets
    FILE mylibraryTargets.cmake
    DESTINATION lib/cmake/mylibrary
)


#ADD_EXECUTABLE(wordcount
#	testFiles/WordCountMapReduce.cpp
#	src/IMapReduce.hpp
#	src/JsonReader.hpp
#	src/MapReduceEngine.hpp
#)

#ADD_EXECUTABLE(tempavg
#	testFiles/TempAvgMapReduce.cpp
#	src/IMapReduce.hpp
#	src/JsonReader.hpp
#	src/MapReduceEngine.hpp
#)

#set_target_properties(wordcount PROPERTIES LINKER_LANGUAGE CXX)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)