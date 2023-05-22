#include "functions.h"

std::array<bool, 20000> generateRandom() {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, 1);
    std::array<bool, 20000> randomSequence {};
    for (bool& bit: randomSequence) {
        bit = distribution(generator);
    }
    return randomSequence;
}

bool testMonoBit(std::array<bool, 20000> sequence) {
    const int sum = std::accumulate(sequence.begin(), sequence.end(), 0);
    return sum > MonoBitMinLimit && sum < MonoBitMaxLimit;
}

bool testLongRuns(std::array<bool, 20000> sequence) {
    int falseLongRun = 0, trueLongRun = 0;
    for (bool bit: sequence) {
        if (bit) {
            ++trueLongRun;
            if (falseLongRun > 0) {
                falseLongRun = 0;
            }
        } else {
            ++falseLongRun;
            if (trueLongRun > 0) {
                trueLongRun = 0;
            }
        }
    }
    return falseLongRun <= 36 && trueLongRun <= 36;
}