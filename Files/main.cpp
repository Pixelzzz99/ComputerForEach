#include <iostream>
#include <vector>
#include "GeneratorTest.hpp"
#include "Tests.hpp"



int main()
{
    srand(time(nullptr));
    int arr1[] = {5, 3, 6};
    int arr2[] = {3, 5, 6, 7};

    int n_num = 10;
    int m_num = 12000;
    GeneratorTest * task1 = new GeneratorTest(12000, 12000, 20, 50);
    Tests *test1 = new Tests(task1);
    //test1->CompareFirstAndSecondVersionsWithConsoleTable();
    n_num += 2000;
    

    test1->CheckFirstVersion();
    test1->CheckSecondVersion();
    //test1->CompareFirstAndSecondVersionsWithConsoleTable();
    //test1->CompareFirstAndSecondDifferentWithOtherNAndMInPythonGraphs();
    system("pause>nul");
    return 0;
}
