#include <iostream>
#include <vector>
#include "GeneratorTest.hpp"
#include "ComputersForEach.hpp"
#include "BruteForce.hpp"
#include "BruteForceAlternative.hpp"

int main()
{
    int arr1[] = {5, 3, 6};
    int arr2[] = {3, 5, 6, 7};
    //ComputersForEach *test1 = new ComputersForEach(new BruteForceAlternative(3, 4, arr1, arr2));
    ComputersForEach *test1 = new ComputersForEach(new BruteForce(new GeneratorTest(1, 50)));
    std::vector<int> roster;

    std::cout<<test1->getCountOfGroups_N()<<std::endl;
    std::cout<<test1->getCountOfAudiences_M()<<std::endl;

    int answer = test1->DoSolve(roster);
    
    std::cout << answer << std::endl;
    for (int i = 0; i < roster.size(); i++)
    {
        std::cout << roster[i] << " ";
    }

    system("pause>nul");
    return 0;
}
