#pragma once
#include <vector>
#include "AlgorithmStrategy.hpp"

class ComputersForEach
{
private:
    AlgorithmStrategy *_strategy;
    
public:
    ComputersForEach(AlgorithmStrategy *strategy = nullptr);
    ~ComputersForEach();
    
    int getCountOfGroups_N();
    void setCountOfGroups_N(int);

    int getCountOfAudiences_M();
    void setCountOfAudiences_M(int);

    void setStrategy(AlgorithmStrategy *);
    int getindex()
    {
        return _strategy->index;
    }
    int DoSolve(std::vector<int> &) const;
};

