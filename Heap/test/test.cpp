#include <iostream>
#include "testMinMaxHeaps.h"

using namespace std;

int main()
{
    bool allTestsPassed = true;

    {
        allTestsPassed = (allTestsPassed && testMinHeap());

        allTestsPassed = (allTestsPassed && testMaxHeap());
    }

    ////////////////////////////////////////////////////////////////
    // Summary of all tests.
    ////////////////////////////////////////////////////////////////
    if (allTestsPassed)
    {
        std::cout << "All tests passed!!\n\n";
    }
    else
    {
        std::cout << "Not all tests passed!!\n\n";
    }
    ////////////////////////////////////////////////////////////////

    return 0;
}
