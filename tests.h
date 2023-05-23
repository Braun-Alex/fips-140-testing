#pragma once
#include <gtest/gtest.h>
#include "functions.h"

class FunctionalFixture: public
        testing::TestWithParam<std::function<bool(std::array<bool, 20000>)>> {
protected:
    void SetUp() override;
    std::function<bool(std::array<bool, 20000>)> testingFunction;
    std::array<bool, 20000> randomSequence;
};