#include "Tests.hpp"
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include "BruteForce.hpp"

Tests::Tests(GeneratorTest *test) : _tests(test)
{
}

void Tests::setTests(GeneratorTest *test)
{
    delete this->_tests;
    _tests = test;
}

int Tests::CheckFirstVersion()
{
    ComputersForEach *test1 = new ComputersForEach(new FirstVersion(_tests));
    std::vector<int> roster;

    std::cout << "Count of Groups: " << test1->getCountOfGroups_N() << std::endl;
    std::cout << "Count of Audiences: " << test1->getCountOfAudiences_M() << std::endl;

    unsigned int start_time = clock();
    int answer = test1->DoSolve(roster);
    unsigned int end_time = clock();

    std::cout << "Count who get audiences: " << answer << std::endl;
    std::cout << "Time of First Version :" << (end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    std::cout << "Groups\t"
              << "Audiences roster: " << std::endl;

    for (int i = 0; i < roster.size(); i++)
    {
        std::cout << "  " << i << "\t      " << roster[i] << std::endl;
    }
    return 1;
}

int Tests::CheckSecondVersion()
{
    ComputersForEach *test1 = new ComputersForEach(new SecondVersion(_tests));
    std::vector<int> roster;

    std::cout << "Count of Groups: " << test1->getCountOfGroups_N() << std::endl;
    std::cout << "Count of Audiences: " << test1->getCountOfAudiences_M() << std::endl;

    unsigned int start_time = clock();
    int answer = test1->DoSolve(roster);
    unsigned int end_time = clock();

    std::cout << "Count who get audiences: " << answer << std::endl;
    std::cout << "Time of First Version :" << (end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    std::cout << "Groups\t"
              << "Audiences roster: " << std::endl;

    for (int i = 0; i < roster.size(); i++)
    {
        std::cout << "  " << i << "\t      " << roster[i] << std::endl;
    }
    return 1;
}

int Tests::CheckBruteForceVersion()
{
    ComputersForEach *test1 = new ComputersForEach(new BruteForce(_tests));
    std::vector<int> roster;

    std::cout << "Count of Groups: " << test1->getCountOfGroups_N() << std::endl;
    std::cout << "Count of Audiences: " << test1->getCountOfAudiences_M() << std::endl;

    unsigned int start_time = clock();
    int answer = test1->DoSolve(roster);
    unsigned int end_time = clock();

    std::cout << "Count who get audiences: " << answer << std::endl;
    std::cout << "Time of First Version :" << (end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    std::cout << "Groups\t"
              << "Audiences roster: " << std::endl;

    for (int i = 0; i < roster.size(); i++)
    {
        std::cout << "  " << i << "\t      " << roster[i] << std::endl;
    }
    return 1;
}

int Tests::CompareFirstAndSecondVersionsWithConsoleTable()
{
    return 1;
}

int Tests::CompareFirstAndSecondVersionsWithPythonTable()
{
    return 1;
}