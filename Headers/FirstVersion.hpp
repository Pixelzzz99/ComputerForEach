#pragma once
#include "AlgorithmStrategy.hpp"

class FirstVersion : public AlgorithmStrategy
{
private:
    std::vector<std::pair<int, int>> _studentsRoster_X;
    std::vector<std::pair<int, int>> _computersRoster_Y;

    void setStudentsRoster_X(int *);
    void setComputersRoster_Y(int *);
    void SortStudentsAndComputersRosters();


public:
    FirstVersion(GeneratorTest *);
    FirstVersion(int, int, int*, int*);
    ~FirstVersion() = default;
    std::vector<int> getStudentsRoster_X() const;
    std::vector<int> getComputersRoster_Y() const;
    int solve(std::vector<int> &) override;
};