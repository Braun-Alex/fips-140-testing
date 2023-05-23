#include "tests.h"

void FunctionalFixture::SetUp() {
    // Instantiating of wrapper with testing function
    testingFunction = GetParam();
    // Instantiating of sequence with randomly generated sequence
    randomSequence = generateRandom();
}

TEST_P(FunctionalFixture, testingForFIPS140v3) {
    // Applying of FIPS-140-3 test for randomly generated sequence and expecting for success
    EXPECT_TRUE(testingFunction(randomSequence));
}

// Instantiating of parametrized test with FIPS-140-3 testing functions
INSTANTIATE_TEST_CASE_P(testingForFIPS140v3, FunctionalFixture,
                        testing::Values(testMonoBit, testLongRuns, testPoker, testRuns));