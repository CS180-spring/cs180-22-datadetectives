#ifndef JOB_TEST_HPP
#define JOB_TEST_HPP

#include "gtest/gtest.h"
#include "../src/Job.hpp"

TEST(JobConfig, DefaultValues){
    Job j;
    EXPECT_EQ(j.getMappers(), 2);
    EXPECT_EQ(j.getReducers(), 1);
    EXPECT_EQ(j.getFileCount(), 0);
    EXPECT_EQ(j.getOutputName(), "output.txt");
}

TEST(JobConfig, UpdateMappers){
    Job j;
    j.setMappers(10);
    EXPECT_EQ(j.getMappers(), 10);
}

TEST(JobConfig, UpdateReducers){
    Job j;
    j.setReducers(5);
    EXPECT_EQ(j.getReducers(), 5);
}

TEST(JobConfig, SetOutputPath){
    Job j;
    j.setOutputPath("updatedPath.txt");
    EXPECT_EQ(j.getOutputName(), "updatedPath.txt");
}

TEST(JobConfig, InputPathsSaved){
    Job j;
    string path = "./normal.csv";
    j.addInputPath(path);
    j.addInputPath("./normal1.csv");
    string path2 = "./normal2.json";
    j.addInputPath(path2);
    vector <string> updated = j.getPaths();
    EXPECT_EQ(updated[0], path);
    EXPECT_EQ(updated[1], "./normal1.csv");
    EXPECT_EQ(updated[2], path2);
}

TEST(JobConfig, FileCountEQInputSize){
    Job j;
    string path = "./normal.csv";
    j.addInputPath(path);
    j.addInputPath("./normal1.csv");
    string path2 = "./normal2.json";
    j.addInputPath(path2);

    vector <string> updated = j.getPaths();
    EXPECT_EQ(updated.size(), 3);
}
#endif