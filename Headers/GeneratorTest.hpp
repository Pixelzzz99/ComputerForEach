#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class GeneratorTest
{
private:
    
    int MIN_COUNT = 1;
    int MAX_COUNT = 20;
    
    int _countOfGroups_N;
    int _countOfAudiences_M;
    int *_students_X;
    int *_computers_Y;
    
    int Randomizator(int min, int max);
    int* AddStudents(int);
    int* AddComputers(int);


public:
    GeneratorTest(int min_count, int max_count);
    //GeneratorTest(int new_n, int new_m, std::vector<int> countStudents, std::vector<int> countComputers );
    GeneratorTest(int new_n, int new_m, int min_count, int max_count);
    ~GeneratorTest() = default;
    
    int getCountOfGroups_N();
    int getCountOfAudiences_M();
    int *getStudents_X();
    int *getComputers_Y();
};