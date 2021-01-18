#include "BruteForce.hpp"

BruteForce::BruteForce(GeneratorTest *test)
{
    setCountOfGroups_N(test->getCountOfGroups_N());
    setCountOfAudiences_M(test->getCountOfAudiences_M());

    setStudentsRoster_X(test->getStudents_X());
    _computersRoster_Y = setComputersRoster_Y(test->getComputers_Y());
}

BruteForce::BruteForce(int countGroupsN, int countAudiencesM, int students[], int computers[])
{
    setCountOfGroups_N(countGroupsN);
    setCountOfAudiences_M(countAudiencesM);
    
    setStudentsRoster_X(students);
    _computersRoster_Y = setComputersRoster_Y(computers);
}

void BruteForce::setStudentsRoster_X(int students[])
{
    for (int i = 0; i < getCountOfGroups_N(); i++)
    {
        _studentsRoster_X.push_back(students[i]);
    }
}

std::vector<std::pair<int, int>> BruteForce::setComputersRoster_Y(int computers[])
{
    int size = getCountOfAudiences_M();
    std::vector<std::pair<int, int>> y_Roster(size);
    for (int i = 0; i < getCountOfAudiences_M(); i++)
    {
        y_Roster[i].first = computers[i];
        y_Roster[i].first--;
        y_Roster[i].second = i;
    }
    return y_Roster;
}

int BruteForce::solve(std::vector<int> &finalRoster)
{
    
    std::sort(_studentsRoster_X.begin(), _studentsRoster_X.end());
    std::vector<int> answer_x(getCountOfGroups_N() + 1, 0);
    recursion(0, _computersRoster_Y, answer_x);
    
    for (int i = 0; i < _global_answer_x.size(); i++)
    {
        if (_global_answer_x.at(i) != 0)
        {
            _global_answer_x.at(i)++;
        }
        finalRoster.push_back(_global_answer_x[i]);
    }
    finalRoster.pop_back();
    return _answer;
}

void BruteForce::recursion(int index, std::vector<std::pair<int, int>> other_y, std::vector<int> answer_x)
{
    if (index > getCountOfGroups_N())
    {
        stoppedOtherTrees = true;
    }

    if ((index > getCountOfGroups_N()) || (int)other_y.size() == 0 || stoppedOtherTrees)
    {
        return;
    }

    if (_answer < index-1)
    {
        _answer = index-1;
        _global_answer_x = answer_x;
    }
    
    std::vector<std::pair<int, int>> newComputerRoster_Y;
    
    for (int i = 0; i < other_y.size(); i++)
    {
        if (other_y[i].first >= _studentsRoster_X[index])
        {
            newComputerRoster_Y.push_back(other_y[i]);
        }   
    }

    for (int i = 0; i < newComputerRoster_Y.size(); i++)
    {
        newComputerRoster_Y[i].first -= _studentsRoster_X[index];
        answer_x[index] = newComputerRoster_Y[i].second;
        recursion(index + 1, newComputerRoster_Y ,answer_x);
        newComputerRoster_Y[i].first += _studentsRoster_X[index];
        answer_x[index] = 0;
    }
}

std::vector<int> BruteForce::getGlobalAnswer_X()
{
    return _global_answer_x;
}
