#include "GeneratorTest.hpp"

GeneratorTest::GeneratorTest(int min_count, int max_count)
{
    this->MIN_COUNT = min_count;
    this->MAX_COUNT = max_count;
    _countOfAudiences_M = Randomizator(MIN_COUNT, MAX_COUNT);
    _countOfGroups_N = Randomizator(MIN_COUNT, _countOfAudiences_M);
    _students_X = AddStudents(_countOfGroups_N);
    _computers_Y = AddComputers(_countOfAudiences_M);
}

GeneratorTest::GeneratorTest(int new_n, int new_m, int min_count, int max_count)
{
    this->MIN_COUNT = min_count;
    this->MAX_COUNT = max_count;
    _countOfAudiences_M = new_m;
    _countOfGroups_N = new_n;
    _students_X = AddStudents(_countOfGroups_N);
    _computers_Y = AddComputers(_countOfAudiences_M);
}

int GeneratorTest::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int* GeneratorTest::AddStudents(int sizeOfGroups)
{
    _students_X = (int *)malloc(sizeOfGroups * sizeof(int));
    for (int i = 0; i < sizeOfGroups; i++)
    {
        _students_X[i] = Randomizator(MIN_COUNT, MAX_COUNT);
    }
    return _students_X;
}

int* GeneratorTest::AddComputers(int sizeOfAudiences)
{
    _computers_Y = (int *)malloc(sizeOfAudiences * sizeof(int));
    for (int i = 0; i < sizeOfAudiences; i++)
    {
        _computers_Y[i] = Randomizator(MIN_COUNT, MAX_COUNT);
    }
    return _computers_Y;
}

int GeneratorTest::getCountOfAudiences_M()
{
    return _countOfAudiences_M;
}

int GeneratorTest::getCountOfGroups_N()
{
    return _countOfGroups_N;
}

int *GeneratorTest::getStudents_X()
{
    return _students_X;
}

int *GeneratorTest::getComputers_Y()
{
    return _computers_Y;
}
