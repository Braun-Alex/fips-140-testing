#include "tests.h"

void FunctionalFixture::SetUp() {
    testingFunction = GetParam();
    randomSequence = generateRandom();
}

TEST_P(FunctionalFixture, testingForFIPS140v3) {
    EXPECT_TRUE(testingFunction(randomSequence));
}

INSTANTIATE_TEST_CASE_P(testingForFIPS140v3, FunctionalFixture,
                        testing::Values(testMonoBit, testLongRuns, testPoker, testRuns));