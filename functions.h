#pragma once
#include <array>
#include <random>
const unsigned int MonoBitMinLimit = 9654,
                   MonoBitMaxLimit = 10346,
                   maxLongRunSize = 36;
const double pokerParameterMinLimit = 1.03,
             pokerParameterMaxLimit = 57.4;

std::array<bool, 20000> generateRandom();

bool testMonoBit(std::array<bool, 20000> sequence);

bool testLongRuns(std::array<bool, 20000> sequence);

bool testPoker(std::array<bool, 20000> sequence);