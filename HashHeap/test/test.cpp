#include <iostream>
#include "testHashHeap.h"

using namespace std;

int main()
{
    bool allTestsPassed = true;

    {
        allTestsPassed = (allTestsPassed && testHashHeap());
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
