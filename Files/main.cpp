#include <iostream>
#include <vector>
#include "GeneratorTest.hpp"
#include "Tests.hpp"

int main()
{
    srand(time(nullptr));
    int arr1[] = {5, 3, 6};
    int arr2[] = {3, 5, 6, 7};

    int n_num = 1000;
    int m_num = 1000;
    
    Tests *test1 = new Tests();
    test1->CompareFirstAndSecondDifferentWithOtherNAndMInPythonGraphs();
       
    
    //test1->CheckFirstVersion();
    //test1->CheckSecondVersion();
    //test1->CompareFirstAndSecondVersionsWithConsoleTable();
    return 0;
}
