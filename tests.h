#pragma once
#include <gtest/gtest.h>
#include "functions.h"

// Fixture for testing of each function that describes FIPS-140-3 test with random sequence
class FunctionalFixture: public
        testing::TestWithParam<std::function<bool(std::array<bool, 20000>)>> {
protected:
    void SetUp() override;
    // Polymorphic function wrapper for testing function
    std::function<bool(std::array<bool, 20000>)> testingFunction;
    // Randomly generated sequence of 20000 bits
    std::array<bool, 20000> randomSequence;
};