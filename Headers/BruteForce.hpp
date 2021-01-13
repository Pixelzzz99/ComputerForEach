#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "GeneratorTest.hpp"
#include "AlgorithmStrategy.hpp"


class BruteForce : public AlgorithmStrategy
{
private:
    std::vector<int> _studentsRoster_X;
    std::vector<std::pair<int, int>> _computersRoster_Y;
    std::vector<int> _global_answer_x;
    bool stoppedOtherTrees = false;
    int _answer;

    void setStudentsRoster_X(int *);
    std::vector<std::pair<int, int>> setComputersRoster_Y(int *);
    
    void recursion(int, std::vector<std::pair<int, int>>, std::vector<int>);
   
public:
    BruteForce(int, int, int *, int *);
    BruteForce(GeneratorTest *);
    ~BruteForce() = default;
    std::vector<int> getGlobalAnswer_X();
    int solve(std::vector<int> &) override;
};