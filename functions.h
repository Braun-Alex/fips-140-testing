#pragma once
#include <array>
#include <random>
const unsigned int MonoBitMinLimit = 9654,
                   MonoBitMaxLimit = 10346,
                   maxLongRunSize = 36;
const double pokerParameterMinLimit = 1.03,
             pokerParameterMaxLimit = 57.4;
const std::array<std::pair<int, int>, 6> runsLimits = {
        std::make_pair(2267, 2733),
        std::make_pair(1079, 1421),
        std::make_pair(502, 748),
        std::make_pair(223, 402),
        std::make_pair(90, 223),
        std::make_pair(90, 223)
};

std::array<bool, 20000> generateRandom();

bool testMonoBit(std::array<bool, 20000> sequence);

bool testLongRuns(std::array<bool, 20000> sequence);

bool testPoker(std::array<bool, 20000> sequence);

bool testRuns(std::array<bool, 20000> sequence);