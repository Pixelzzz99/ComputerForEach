#pragma once
#include <algorithm>
#include "AlgorithmStrategy.hpp"


class SecondVersion : public AlgorithmStrategy
{
private:
    std::vector<std::pair<int, int>> _studentsRoster_X;
    std::vector<std::pair<int, int>> _computersRoster_Y;
    void setStudentsRoster_X(int *);
    void setComputersRoster_Y(int *);
    void SortStudentsAndComputersRosters();
public:
    SecondVersion(GeneratorTest *);
    SecondVersion(int, int, int *, int *);
    ~SecondVersion() = default;
    std::vector<int> getStudentsRoster_X();
    std::vector<int> getComputersRoster_Y();
    int solve(std::vector<int> &) override;
};
