#ifndef TEST_GRAPH_CLASS_HEADER_H__
#define TEST_GRAPH_CLASS_HEADER_H__

#include "../graph.h"
#include "testEdge.h" // for passed &= check()
#include <iostream>
#include <string>

#define private public
#define protected public

bool testGraph()
{
	bool passed = true;
	bool allTestsPassed = true;

	using std::cout;
	using std::string;
	using std::endl;
	using std::vector;
	using MEK::Node;
	using MEK::Hash;
	using MEK::Graph;

	{
		cout << "Testing Graph class." << endl;
		passed = true;

		cout << "   Check constructor." << endl;
		Graph graph;

		passed &= check(0, graph.getNodeHash().numberEntries(), "Number of nodes");
		passed &= check(0, graph.getEdgeHash().numberEntries(), "Number of edges");

		cout << "   Check addNode()." << endl;
		graph.addNode(1);
		graph.addNode(2);
		graph.addNode(3);
		passed &= check(3, graph.getNodeHash().numberEntries(), "Number of nodes");
		passed &= check(0, graph.getEdgeHash().numberEntries(), "Number of edges");
		passed &= check(0, graph.getNodeHash()[1].getAdjEdgeVector().size(), "Number of neighbors node 1");
		passed &= check(0, graph.getNodeHash()[2].getAdjEdgeVector().size(), "Number of neighbors node 2");
		passed &= check(0, graph.getNodeHash()[3].getAdjEdgeVector().size(), "Number of neighbors node 3");

		cout << "   Check addEdge()." << endl;
		graph.addEdge(12, 1, 2);
		graph.addEdge(23, 2, 3);
		graph.addEdge(31, 3, 1);
		passed &= check(3, graph.getNodeHash().numberEntries(), "Number of nodes");
		passed &= check(3, graph.getEdgeHash().numberEntries(), "Number of edges");

		{
			vector<int> neighbors = graph.getNodeHash().get(1).getAdjEdgeVector();
			passed &= check(2, neighbors.size(), "Number of neighbors node 1");
			passed &= check(31, neighbors.at(0), "    1st neighbor");
			passed &= check(12, neighbors.at(1), "    2nd neighbor");
		}

		{
			vector<int> neighbors = graph.getNodeHash().get(2).getAdjEdgeVector();
			passed &= check(2, neighbors.size(), "Number of neighbors node 2");
			passed &= check(23, neighbors.at(0), "    1st neighbor");
			passed &= check(12, neighbors.at(1), "    2nd neighbor");
		}

		{
			vector<int> neighbors = graph.getNodeHash().get(3).getAdjEdgeVector();
			passed &= check(2, neighbors.size(), "Number of neighbors node 3");
			passed &= check(23, neighbors.at(0), "    1st neighbor");
			passed &= check(31, neighbors.at(1), "    2nd neighbor");
		}

		{
			cout << "   Check ''='' overload" << endl;
			Graph copiedGraph;
			copiedGraph = graph;

			passed &= check(3, graph.getNodeHash().numberEntries(), "Number of nodes");
			passed &= check(3, graph.getEdgeHash().numberEntries(), "Number of edges");

			{
				vector<int> neighbors = graph.getNodeHash().get(1).getAdjEdgeVector();
				passed &= check(2, neighbors.size(), "Number of neighbors node 1");
				passed &= check(31, neighbors.at(0), "    1st neighbor");
				passed &= check(12, neighbors.at(1), "    2nd neighbor");
			}

			{
				vector<int> neighbors = graph.getNodeHash().get(2).getAdjEdgeVector();
				passed &= check(2, neighbors.size(), "Number of neighbors node 2");
				passed &= check(23, neighbors.at(0), "    1st neighbor");
				passed &= check(12, neighbors.at(1), "    2nd neighbor");
			}

			{
				vector<int> neighbors = graph.getNodeHash().get(3).getAdjEdgeVector();
				passed &= check(2, neighbors.size(), "Number of neighbors node 3");
				passed &= check(23, neighbors.at(0), "    1st neighbor");
				passed &= check(31, neighbors.at(1), "    2nd neighbor");
			}
		}

		cout << "   Check deleteEdge() - deleting edge 23." << endl;
		graph.deleteEdge(31);
		passed &= check(3, graph.getNodeHash().numberEntries(), "Number of nodes");
		passed &= check(2, graph.getEdgeHash().numberEntries(), "Number of edges");

		{
			vector<int> neighbors = graph.getNodeHash().get(1).getAdjEdgeVector();
			passed &= check(1, neighbors.size(), "Number of neighbors node 1");
			passed &= check(12, neighbors.at(0), "    1st neighbor");
		}

		{
			vector<int> neighbors = graph.getNodeHash().get(2).getAdjEdgeVector();
			passed &= check(2, neighbors.size(), "Number of neighbors node 2");
			passed &= check(23, neighbors.at(0), "    1st neighbor");
			passed &= check(12, neighbors.at(1), "    2nd neighbor");
		}

		{
			vector<int> neighbors = graph.getNodeHash().get(3).getAdjEdgeVector();
			passed &= check(1, neighbors.size(), "Number of neighbors node 3");
			passed &= check(23, neighbors.at(0), "    1st neighbor");
		}

		cout << "   Check deleteNode() - deleting node 3." << endl;
		graph.deleteNode(3);
		passed &= check(2, graph.getNodeHash().numberEntries(), "Number of nodes");
		passed &= check(1, graph.getEdgeHash().numberEntries(), "Number of edges");

		{
			vector<int> neighbors = graph.getNodeHash().get(1).getAdjEdgeVector();
			passed &= check(1, neighbors.size(), "Number of neighbors node 1");
			passed &= check(12, neighbors.at(0), "    1st neighbor");
		}

		{
			vector<int> neighbors = graph.getNodeHash().get(2).getAdjEdgeVector();
			passed &= check(1, neighbors.size(), "Number of neighbors node 2");
			passed &= check(12, neighbors.at(0), "    1st neighbor");
		}

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



