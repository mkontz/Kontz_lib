#include "testNode.h"
#include "testEdge.h"
#include "testGraph.h"

#include <iostream>

#define private public
#define protected public

int main()
{
	bool allTestsPassed = true;

	allTestsPassed &= testEdge();

	allTestsPassed &= testNode();

	allTestsPassed &= testGraph();


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




