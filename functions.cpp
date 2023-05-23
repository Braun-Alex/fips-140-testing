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

bool testPoker(std::array<bool, 20000> sequence) {
    int index, buffer;
    std::array<int, 16> blocks {};
    blocks.fill(0);
    for (int i = 0; i < 20000; i += 4) {
        index = 0;
        buffer = 1;
        for (int j = 0; j < 4; j++) {
            index += sequence[i + j] * buffer;
            buffer *= 2;
        }
        ++blocks[index];
    }
    double X = 0;
    for (int i = 0; i < 16; i++) {
        X += blocks[i] * blocks[i];
    }
    X *= 16;
    X /= 5000;
    X -= 5000;
    return X > pokerParameterMinLimit && X < pokerParameterMaxLimit;
}

bool testRuns(std::array<bool, 20000> sequence) {
    int falseLongRun = 0, trueLongRun = 0;
    std::array<int, 6> runs {};
    runs.fill(0);
    for (bool bit: sequence) {
        if (bit) {
            ++trueLongRun;
            if (falseLongRun > 0) {
                if (falseLongRun >= 6) {
                    ++runs[5];
                } else {
                    ++runs[falseLongRun - 1];
                }
                falseLongRun = 0;
            }
        } else {
            ++falseLongRun;
            if (trueLongRun > 0) {
                trueLongRun = 0;
            }
        }
    }
    bool check;
    for (int i = 0; i < 6; i++) {
        check = runs[i] > runsLimits[i].first && runs[i] < runsLimits[i].second;
        if (!check) {
            return false;
        }
    }
    return true;
}