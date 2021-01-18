#include <iostream>
#include <vector>
#include "GeneratorTest.hpp"
#include "Tests.hpp"


int main()
{
    srand(time(nullptr));
    int arr1[] = {5, 3, 6};
    int arr2[] = {3, 5, 6, 7};
    Tests *test1 = new Tests(new GeneratorTest(15, 25));
    test1->CheckFirstVersion();
    test1->CheckSecondVersion();
    test1->CheckBruteForceVersion();
    system("pause>nul");
    return 0;
}
