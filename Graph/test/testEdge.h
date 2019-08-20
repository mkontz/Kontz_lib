#ifndef TEST_EDGE_CLASS_HEADER_H__
#define TEST_EDGE_CLASS_HEADER_H__

#include "../edge.h"
#include <iostream>
#include <string>

#define private public
#define protected public

bool check(int expected, int recieved, std::string str)
{
	bool passed = true;

	std::cout << "        "<< str;
	if (expected == recieved)
	{
		std::cout << ": expected/recieved: "<< expected << " - Passed" << std::endl;
	}
	else
	{
		std::cout << ": expected: "<< expected << ", recieved: "<< recieved << " - Failed" << std::endl;
		passed = false;
	}

	return passed;
}

bool testEdge()
{
	bool passed = true;
	bool allTestsPassed = true;

	using std::cout;
	using std::endl;
	using std::string;
	using MEK::Edge;

	int node1 = 1;
	int node2 = 2;
	int node3 = 3;

	{
		cout << "Testing Edge class using set and get methods." << endl;
		passed = true;

		cout << "   Check constructor, get and set IDs." << endl;

		Edge<int> edge12(1);

		passed &= check(1, edge12.getIdx(), "Edge12 IDs = 1");
		passed &= check(0, edge12.getNode1(), "Node #1 = 0, edge12");
		passed &= check(0, edge12.getNode2(), "Node #2 = 0, edge12");


		edge12.setNodes(node1, node2);

		passed &= check(node1, edge12.getNode1(), "Node #1, edge12");
		passed &= check(node2, edge12.getNode2(), "Node #2, edge12");

		Edge<uint16_t> edge23(2,5,6);

		passed &= check(2, edge23.getIdx(), "Edge23 IDs = 2");
		passed &= check(5, edge23.getNode1(), "Node #1 = 5, edge23");
		passed &= check(6, edge23.getNode2(), "Node #2 = 6, edge23");
		
		edge23.setNode1(node2);
		edge23.setNode2(node3);

		passed &= check(node2, edge23.getNode1(), "Node #1 edge23");
		passed &= check(node3, edge23.getNode2(), "Node #2, edge23");
		
		cout << "   Check ''='' overload." << endl;

		Edge<uint16_t> copy = edge23;

		passed &= check(2, copy.getIdx(), "Copied Edge23 IDs = 2");
		passed &= check(node2, copy.getNode1(), "Node #1 copied edge23");
		passed &= check(node3, copy.getNode2(), "Node #2, copied edge23");

		allTestsPassed &= passed;

	    ////////////////////////////////////////////////////////////////
	    // Summary of all tests.
	    ////////////////////////////////////////////////////////////////
	    if (allTestsPassed)
	    {
	        std::cout << "    All tests passed!!\n\n";
	    }
	    else
	    {
	        std::cout << "    Not all tests passed!!\n\n";
	    }
	    ////////////////////////////////////////////////////////////////
	}

	
	return allTestsPassed;
}

#endif



