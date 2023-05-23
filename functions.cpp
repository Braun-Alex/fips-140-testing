#include "functions.h"

// Generating of random sequence using std::random from STL
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
    // Numeric iterator-based function from STL. Calculates sum of digits of binary number
    const int sum = std::accumulate(sequence.begin(), sequence.end(), 0);
    return sum > MonoBitMinLimit && sum < MonoBitMaxLimit;
}

bool testLongRuns(std::array<bool, 20000> sequence) {
    int falseLongRun = 0, trueLongRun = 0;
    for (bool bit: sequence) {
        if (bit) {
            ++trueLongRun;
            // Conditional resetting of run of false values
            if (falseLongRun > 0) {
                falseLongRun = 0;
            }
        } else {
            ++falseLongRun;
            // Conditional resetting of run of true values
            if (trueLongRun > 0) {
                trueLongRun = 0;
            }
        }
    }
    return falseLongRun <= maxLongRunSize && trueLongRun <= maxLongRunSize;
}

bool testPoker(std::array<bool, 20000> sequence) {
    int index, buffer;
    // Using of std::array<int, 16> for counting 4-bit runs in Poker blocks
    std::array<int, 16> blocks {};
    blocks.fill(0);
    // Converting of 4-bit sequences to decimal values to increment necessary indices in Poker blocks
    for (int i = 0; i < 20000; i += 4) {
        index = 0;
        buffer = 1;
        for (int j = 0; j < 4; j++) {
            index += sequence[i + j] * buffer;
            buffer *= 2;
        }
        ++blocks[index];
    }
    // Computing of X-parameter
    double X = 0;
    for (int i = 0; i < 16; i++) {
        X += blocks[i] * blocks[i];
    }
    X *= 16;
    X /= 5000;
    X -= 5000;
    return X > pokerParameterMinLimit && X < pokerParameterMaxLimit;
}

// Modification of testLongRuns function
bool testRuns(std::array<bool, 20000> sequence) {
    int falseLongRun = 0, trueLongRun = 0;
    // Using of std::array<int, 6> for counting runs in intervals
    std::array<int, 6> falseRuns {}, trueRuns {};
    falseRuns.fill(0);
    trueRuns.fill(0);
    for (bool bit: sequence) {
        if (bit) {
            ++trueLongRun;
            if (falseLongRun > 0) {
                if (falseLongRun >= 6) {
                    ++falseRuns[5];
                } else {
                    ++falseRuns[falseLongRun - 1];
                }
                falseLongRun = 0;
            }
        } else {
            ++falseLongRun;
            if (trueLongRun > 0) {
                if (trueLongRun >= 6) {
                    ++trueRuns[5];
                } else {
                    ++trueRuns[trueLongRun - 1];
                }
                trueLongRun = 0;
            }
        }
    }
    // Checking of each count of size of runs for FIPS-140-3 interval constants
    bool check;
    for (int i = 0; i < 6; i++) {
        check = falseRuns[i] > runsLimits[i].first && falseRuns[i] < runsLimits[i].second;
        check &= trueRuns[i] > runsLimits[i].first && trueRuns[i] < runsLimits[i].second;
        if (!check) {
            return false;
        }
    }
    return true;
}