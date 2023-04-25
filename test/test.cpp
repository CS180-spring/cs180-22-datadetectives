
#include "gtest/gtest.h"
#include "../test/loadCSV_Test.hpp"
#include "../test/OpenFile_Test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}