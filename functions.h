#pragma once
#include <array>
#include <random>
const unsigned int MonoBitMinLimit = 9654,
                   MonoBitMaxLimit = 10346;

std::array<bool, 20000> generateRandom();

bool testMonoBit(std::array<bool, 20000> sequence);