#pragma once
#include "AlgorithmStrategy.hpp"
#include "algorithm"
#include "GeneratorTest.hpp"

class BruteForceAlternative : public AlgorithmStrategy
{
private:
    std::vector<std::pair<int, int>> _studentsRoster_X;
    std::vector<std::pair<int, int>> _computersRoster_Y;
    void setStudentsRoster_X(int *);
    void setComputersRoster_Y(int *);
    void SortStudentsAndComputersRosters();
public:
    BruteForceAlternative(GeneratorTest *);
    BruteForceAlternative(int, int, int *, int *);
    ~BruteForceAlternative() = default;
    std::vector<int> getStudentsRoster_X();
    std::vector<int> getComputersRoster_Y();
    int solve(std::vector<int> &) override;
};
