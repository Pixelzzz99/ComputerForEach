#pragma once
#include "GeneratorTest.hpp"
#include "ComputersForEach.hpp"
#include <ctime>
#include <chrono>
#include <fstream>
class Tests
{
private:
    virtual ~Tests() = default;
    
    GeneratorTest * _tests;
public:
    Tests(GeneratorTest * test = nullptr);
    void setTests(GeneratorTest *);
    int SimpleTest();
    
    int CheckFirstVersion();
    int CheckSecondVersion();
    int CheckBruteForceVersion();
    
    int CompareFirstAndSecondVersionsWithConsoleTable();
    int CompareFirstAndSecondVersionsWithPythonTable();
    int CompareFirstAndSecondDifferentWithOtherNAndMInPythonGraphs();
};

