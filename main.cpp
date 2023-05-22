#include "functions.h"
#include <iostream>

int main() {
    auto randomValues = generateRandom();
    std::cout << testLongRuns(randomValues);
}