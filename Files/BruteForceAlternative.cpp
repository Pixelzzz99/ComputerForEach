#include "BruteForceAlternative.hpp"

BruteForceAlternative::BruteForceAlternative(GeneratorTest *test)
{
    setCountOfGroups_N(test->getCountOfGroups_N());
    setCountOfAudiences_M(test->getCountOfAudiences_M());
    setStudentsRoster_X(test->getStudents_X());
    setComputersRoster_Y(test->getComputers_Y());
}

BruteForceAlternative::BruteForceAlternative(int countGroups_N, int countOfAudiences_M, int *studentsRoster, int *computersRoster)
{
    setCountOfGroups_N(countGroups_N);
    setCountOfAudiences_M(countOfAudiences_M);
    setStudentsRoster_X(studentsRoster);
    setComputersRoster_Y(computersRoster);
}

std::vector<int> BruteForceAlternative::getStudentsRoster_X()
{
    std::vector<int> studentRosterWithoutIndex;
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        studentRosterWithoutIndex.push_back(_studentsRoster_X[i].first);
    }
    return studentRosterWithoutIndex;
}

std::vector<int> BruteForceAlternative::getComputersRoster_Y()
{
    std::vector<int> computerRosterWithoutIndex;
    for (int i = 0; i < getCountOfAudiences_M(); i++)
    {
        computerRosterWithoutIndex.push_back(_computersRoster_Y[i].first);
    }
    return computerRosterWithoutIndex;
}

void BruteForceAlternative::setStudentsRoster_X(int *newStudentsRoster)
{
    _studentsRoster_X.resize(getCountOfGroups_N());
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        _studentsRoster_X[i].first = newStudentsRoster[i];
        _studentsRoster_X[i].second = i;
    }
}

void BruteForceAlternative::setComputersRoster_Y(int *newComputersRoster)
{
    _computersRoster_Y.resize(getCountOfAudiences_M());
    for (int i = 0; i < getCountOfAudiences_M(); i++)
    {
        _computersRoster_Y[i].first = newComputersRoster[i];
        _computersRoster_Y[i].second = i;
    }
}

int BruteForceAlternative::solve(std::vector<int> &finalRoster)
{
    SortStudentsAndComputersRosters();
    int id = 0;
    int result = 0;
    std::vector<int> answer(getCountOfGroups_N(), -1);
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        while (id < getCountOfAudiences_M() && _studentsRoster_X[i].first >= _computersRoster_Y[id].first)
            id++;
        

        if (id == getCountOfAudiences_M()) 
            break;
        
        result++;
        answer[_studentsRoster_X[i].second] = _computersRoster_Y[id].second;
        id++;
    }

    for(int elem : answer)
    {
        finalRoster.push_back(elem + 1);
    }
    return result;
}

void BruteForceAlternative::SortStudentsAndComputersRosters()
{
    std::sort(_studentsRoster_X.begin(), _studentsRoster_X.end());
    std::sort(_computersRoster_Y.begin(), _computersRoster_Y.end());
}