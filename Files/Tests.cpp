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
    std::cout << "Time of First Version :" << (double)(end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    if (test1->getCountOfGroups_N() < 100 && test1->getCountOfAudiences_M() < 100)
    {
        std::cout << "Groups\t"
                  << "Audiences roster: " << std::endl;

        for (int i = 0; i < roster.size(); i++)
        {
            std::cout << "  " << i << "\t      " << roster[i] << std::endl;
        }
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
    std::cout << "Time of First Version :" << (double)(end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    if (test1->getCountOfGroups_N() < 100 && test1->getCountOfAudiences_M() < 100)
    {
        std::cout << "Group s\t"
                  << "Audiences roster: " << std::endl;

        for (int i = 0; i < roster.size(); i++)
        {
            std::cout << "  " << i << "\t      " << roster[i] << std::endl;
        }
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
    ComputersForEach *test1 = new ComputersForEach(new FirstVersion(_tests));
    ComputersForEach *test2 = new ComputersForEach(new SecondVersion(_tests));

    std::vector<int> roster1;
    std::vector<int> roster2;
    unsigned int start_time_test1 = clock();
    int answer1 = test1->DoSolve(roster1);
    unsigned int end_time_test1 = clock();

    unsigned int start_time_test2 = clock();
    int answer2 = test2->DoSolve(roster2);
    unsigned int end_time_test2 = clock();

    std::cout << "Count peoples in Groups:"
              << "\t"
              << "Seats in Audiences:"
              << "\t"
              << "How many people fit:"
              << "\t"
              << "Time of Algorithm:" << std::endl;
    std::cout << test1->getCountOfGroups_N() << "\t\t\t\t" << test1->getCountOfAudiences_M() << "\t\t\t\t" << answer1 << "\t\t\t" << (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC << std::endl;
    std::cout << test2->getCountOfGroups_N() << "\t\t\t\t" << test2->getCountOfAudiences_M() << "\t\t\t\t" << answer2 << "\t\t\t" << (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC << std::endl;
    return 1;
}

int Tests::CompareFirstAndSecondVersionsWithPythonTable()
{
    ComputersForEach *test1 = new ComputersForEach(new FirstVersion(_tests));
    ComputersForEach *test2 = new ComputersForEach(new SecondVersion(_tests));

    std::vector<int> roster1;
    std::vector<int> roster2;
    unsigned int start_time_test1 = clock();
    int answer1 = test1->DoSolve(roster1);
    unsigned int end_time_test1 = clock();

    unsigned int start_time_test2 = clock();
    int answer2 = test2->DoSolve(roster2);
    unsigned int end_time_test2 = clock();

    std::cout << "Count peoples in Groups:"
              << "\t"
              << "Seats in Audiences:"
              << "\t"
              << "How many people fit:"
              << "\t"
              << "Time of Algorithm:" << std::endl;
    double time1 = (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC;
    double time2 = (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC;
    std::cout << test1->getCountOfGroups_N() << "\t\t\t\t" << test1->getCountOfAudiences_M() << "\t\t\t\t" << answer1 << "\t\t\t" << (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC << std::endl;
    std::cout << test2->getCountOfGroups_N() << "\t\t\t\t" << test2->getCountOfAudiences_M() << "\t\t\t\t" << answer2 << "\t\t\t" << (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC << std::endl;

    std::ofstream out1;
    out1.open("D:\\projects\\ComputerForEach\\PyGraphs\\InformationFirstVersion.txt", std::ios::app);
    if (out1.is_open())
    {
        out1 << test1->getCountOfGroups_N() << std::endl;
        out1 << test1->getCountOfAudiences_M() << std::endl;
        out1 << time1 << std::endl;
    }
    std::ofstream out2;
    out2.open("D:\\projects\\ComputerForEach\\PyGraphs\\InformationSecondVersion.txt", std::ios::app);
    if (out2.is_open())
    {
        out2 << test2->getCountOfGroups_N() << std::endl;
        out2 << test2->getCountOfAudiences_M() << std::endl;
        out2 << time2 << std::endl;
    }

    return 1;
}

int Tests::CompareFirstAndSecondDifferentWithOtherNAndMInPythonGraphs()
{
    int n_num = 1000;
    int m_num = 1500;
    
    for (int i = 0; i < 100; i++)
    {
        ComputersForEach *test1 = new ComputersForEach(new FirstVersion(new GeneratorTest(n_num, m_num)));
        ComputersForEach *test2 = new ComputersForEach(new SecondVersion(new GeneratorTest(n_num, m_num)));

        std::vector<int> roster1;
        std::vector<int> roster2;
        unsigned int start_time_test1 = clock();
        int answer1 = test1->DoSolve(roster1);
        unsigned int end_time_test1 = clock();

        unsigned int start_time_test2 = clock();
        int answer2 = test2->DoSolve(roster2);
        unsigned int end_time_test2 = clock();

        std::cout << "Count peoples in Groups:"
                  << "\t"
                  << "Seats in Audiences:"
                  << "\t"
                  << "How many people fit:"
                  << "\t"
                  << "Time of Algorithm:" << std::endl;
        double time1 = (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC;
        double time2 = (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC;
        std::cout << test1->getCountOfGroups_N() << "\t\t\t\t" << test1->getCountOfAudiences_M() << "\t\t\t\t" << answer1 << "\t\t\t" << (double)(end_time_test1 - start_time_test1) / CLOCKS_PER_SEC << std::endl;
        std::cout << test2->getCountOfGroups_N() << "\t\t\t\t" << test2->getCountOfAudiences_M() << "\t\t\t\t" << answer2 << "\t\t\t" << (double)(end_time_test2 - start_time_test2) / CLOCKS_PER_SEC << std::endl;

        std::ofstream out1;
        out1.open("D:\\projects\\ComputerForEach\\PyGraphs\\FirstVersionDiffNAndM.txt", std::ios::app);
        if (out1.is_open())
        {
            out1 << test1->getCountOfGroups_N() << std::endl;
            out1 << test1->getCountOfAudiences_M() << std::endl;
            out1 << time1 << std::endl;
        }
        std::ofstream out2;
        out2.open("D:\\projects\\ComputerForEach\\PyGraphs\\SecondVersionDiffNAndM.txt", std::ios::app);
        if (out2.is_open())
        {
            out2 << test2->getCountOfGroups_N() << std::endl;
            out2 << test2->getCountOfAudiences_M() << std::endl;
            out2 << time2 << std::endl;
        }
        n_num += 500;
        m_num += 500;
    }
    return 1;
}