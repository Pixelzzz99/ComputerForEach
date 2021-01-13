#pragma once
#include <vector>

class AlgorithmStrategy
{
private:
    int _countOfGroups_N;
    int _countOfAudiences_M;
public:
    int getCountOfGroups_N();
    void setCountOfGroups_N(int);

    int getCountOfAudiences_M();
    void setCountOfAudiences_M(int);

    virtual ~AlgorithmStrategy() = default;
    virtual int solve(std::vector<int> &) = 0;
};
