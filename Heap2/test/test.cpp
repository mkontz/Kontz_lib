#include <iostream>
#include "testKVHeap.h"

using namespace std;

int main()
{
    bool allTestsPassed = true;

    {
        allTestsPassed = (allTestsPassed && testKVHeap());
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
