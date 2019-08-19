#ifndef TEST_NODE_CLASS_HEADER_H__
#define TEST_NODE_CLASS_HEADER_H__

#include "../node.h"
#include "testEdge.h" // for passed &= check()
#include <iostream>
#include <string>

#define private public
#define protected public

bool testNode()
{
	bool passed = true;
	bool allTestsPassed = true;

	using std::cout;
	using std::endl;
	using std::string;
	using std::vector;
	using MEK::Node;
	using MEK::Hash;

	{
		cout << "Testing Node class." << endl;
		passed = true;
		Node node1(11);

		cout << "   Check constructor and getIdx()." << endl;

		passed &= check(11, node1.getIdx(), "Node 1 ID = 1");
		passed &= check(0, node1.getAdjEdgeVector().size(), "Number of neighbors = 0");


		cout << "   Check addEdge() and getAdjEdgeVector()." << endl;

		node1.addEdge(3);
		node1.addEdge(4);
		node1.addEdge(5);

		vector<int> vec = node1.getAdjEdgeVector();
		//std::sort(vec.begin(), vec.end());
		passed &= check(3, vec.size(), "Number of neighbors = 3");
		for (int k = 0; k < 3; k++)
		{
			passed &= check(k + 3, vec.at(k), "Checking neighbors IDs");
		}

		cout << "   Check ''='' overload." << endl;

		Node copiedNode = node1;
		passed &= check(11, copiedNode.getIdx(), "Coppied Node ID = 1");
		vec = copiedNode.getAdjEdgeVector();
		//std::sort(vec.begin(), vec.end());
		passed &= check(3, vec.size(), "Number of neighbors = 3");
		for (int k = 0; k < 3; k++)
		{
			passed &= check(k + 3, vec.at(k), "Checking neighbors IDs");
		}

		cout << "   Check removeEdge()." << endl;
		node1.removeEdge(3);
		node1.removeEdge(5);

		Hash<int, int> edgeHash = node1.getAdjEdgeHash();
		passed &= check(1, edgeHash.numberEntries(), "Number of neighbors = 1");
		passed &= check(4, edgeHash[4], "The neighbors is 4");
		
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



