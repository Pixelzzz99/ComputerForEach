#include "FirstVersion.hpp"

FirstVersion::FirstVersion(GeneratorTest *test)
{
    setCountOfGroups_N(test->getCountOfGroups_N());
    setCountOfAudiences_M(test->getCountOfAudiences_M());
    setStudentsRoster_X(test->getStudents_X());
    setComputersRoster_Y(test->getComputers_Y());
}

FirstVersion::FirstVersion(int countGroups_N, int countOfAudiences_M, int *studentsRoster, int *computersRoster)
{
    setCountOfGroups_N(countGroups_N);
    setCountOfAudiences_M(countOfAudiences_M);
    setStudentsRoster_X(studentsRoster);
    setComputersRoster_Y(computersRoster);
}

void FirstVersion::setStudentsRoster_X(int *newStudentsRoster_X)
{
    _studentsRoster_X.resize(getCountOfGroups_N());
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        _studentsRoster_X[i].first = newStudentsRoster_X[i];
        _studentsRoster_X[i].second = i;
    }
}

void FirstVersion::setComputersRoster_Y(int *newComputerRoster_Y)
{
    _computersRoster_Y.resize(getCountOfAudiences_M());
    for (int i = 0; i < getCountOfAudiences_M(); i++)
    {
        _computersRoster_Y[i].first = newComputerRoster_Y[i];
        _computersRoster_Y[i].first--;
        _computersRoster_Y[i].second = i;
    }
}

int FirstVersion::solve(std::vector<int> &finalRoster)
{
    SortStudentsAndComputersRosters();
    int result = 0;
    int *answer = new int[getCountOfGroups_N()];
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        answer[i] = -1;
    }

    bool *used = new bool[getCountOfAudiences_M()];
    for (int i = 0; i < getCountOfAudiences_M(); i++)
    {
        used[i] = false;
    }

    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        for (int j = 0; j < getCountOfAudiences_M(); j++)
        {
            index++;
            if (used[j])
                continue;
            if (_studentsRoster_X[i].first < _computersRoster_Y[j].first)
            {
                result++;
                answer[_studentsRoster_X[i].second] = _computersRoster_Y[j].second;
                used[j] = true;
                break;
            }
        }
    }

    /*for(int element : answer)
    {
        finalRoster.push_back(element + 1);
    }*/

    return result;
}

void FirstVersion::SortStudentsAndComputersRosters()
{
    std::sort(_studentsRoster_X.begin(), _studentsRoster_X.end());
    std::sort(_computersRoster_Y.begin(), _computersRoster_Y.end());
}

std::vector<int> FirstVersion::getStudentsRoster_X() const
{
    std::vector<int> studentsRosterWithoutIndex;
    for (std::pair<int, int> pairOfStudentsRoster : _studentsRoster_X)
        studentsRosterWithoutIndex.push_back(pairOfStudentsRoster.first);

    return studentsRosterWithoutIndex;
}

std::vector<int> FirstVersion::getComputersRoster_Y() const
{
    std::vector<int> computerRosterWithoutIndex;
    for (std::pair<int, int> pairOfComputersRoster : _computersRoster_Y)
        computerRosterWithoutIndex.push_back(pairOfComputersRoster.first);

    return computerRosterWithoutIndex;
}
