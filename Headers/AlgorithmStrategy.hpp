#pragma once
#include <vector>
#include <algorithm>
#include "GeneratorTest.hpp"

class AlgorithmStrategy
{
private:
    int _countOfGroups_N;
    int _countOfAudiences_M;
public:
    int index = 0;
    int getCountOfGroups_N();
    void setCountOfGroups_N(int);

    int getCountOfAudiences_M();
    void setCountOfAudiences_M(int);

    virtual ~AlgorithmStrategy() = default;
    virtual int solve(std::vector<int> &) = 0;
};



