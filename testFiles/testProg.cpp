
#include "gtest/gtest.h"
#include "MapTest.hpp"
#include "ShuffleTest.hpp"
#include "ReduceTest.hpp"
#include "SequentialTempAvgTest.hpp"
#include "loadCSV_Test.hpp"
#include "OpenFile_Test.hpp"
#include "job_Test.hpp"
#include "FilterTest.hpp"
#include "csvSplit_Test.hpp"
#include "integrationTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}