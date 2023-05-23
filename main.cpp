#include <gtest/gtest.h>

int main() {
    // Initializing of GoogleTest
    testing::InitGoogleTest();
    // Running all tests. It returns 0 if all tests are successful, or 1 otherwise
    if (!RUN_ALL_TESTS()) {
        std::cout << "All the FIPS-140-3 tests for randomly generated sequence of 20000 bits have been passed";
    } else {
        std::cout << "Randomly generated sequence of 20000 bits is not random according to FIPS-140-3 standard";
    }
    return 0;
}