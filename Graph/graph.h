#ifndef _GRAPH_CLASS_HEADER_H__
#define _GRAPH_CLASS_HEADER_H__

#include "node.h"
#include "edge.h"
#include "../HashTable/hash.h"
#include <vector>
#include <iostream>

//*********************************************************************
//  Graph Class
//*********************************************************************

namespace MEK
{
	class Graph
	{
	private:
		Hash<int, Node> m_nodeHash;
		Hash<int, Edge> m_edgeHash;

	public:
		Graph() :
		 	m_nodeHash(),
		 	m_edgeHash()
		{ }

		~Graph()
		{ }

        Graph& operator = (const Graph& other)
        {
        	if (this != &other)
        	{
        		m_nodeHash = getNodeHash();
        		m_edgeHash = getEdgeHash();
        	}

            return *this;
        }

		void addNode(int idx)
		{
			Node tmp(idx);
			m_nodeHash.set(idx, tmp);
		}

		bool deleteNode(int idx)
		{
			bool found = false;

			if (m_nodeHash.exist(idx))
			{
				std::vector<int> edgeList = m_nodeHash[idx].getAdjEdgeVector();

				for (size_t k = 0; k < edgeList.size(); k++)
				{
					deleteEdge(edgeList.at(k));
				}

				m_nodeHash.remove(idx);

				found = true;
			}

			return found;
		}

		bool addEdge(int idx, int n1, int n2)
		{
			bool retVal = false;

			if (m_edgeHash.exist(idx))
			{
				deleteEdge(idx);
			}

			if (m_nodeHash.exist(n1) && m_nodeHash.exist(n2))
			{
				m_edgeHash[idx] = Edge(idx, n1, n2);

				(m_nodeHash[n1]).addEdge(idx);
				(m_nodeHash[n2]).addEdge(idx);

				retVal= true;
			}

			return retVal;
		}

		bool deleteEdge(int idx)
		{
			bool retVal = true;

			if (m_edgeHash.exist(idx))
			{
				if (m_nodeHash.exist(m_edgeHash[idx].getNode1()))
				{
					m_nodeHash[m_edgeHash[idx].getNode1()].removeEdge(idx);
				}

				if (m_nodeHash.exist(m_edgeHash[idx].getNode2()))
				{
					m_nodeHash[m_edgeHash[idx].getNode2()].removeEdge(idx);
				}	

				m_edgeHash.remove(idx);
			}
			else
			{
				retVal = false;
			}

			return retVal;
		}

		Hash<int, Node>& getNodeHash() { return m_nodeHash; }
		Hash<int, Edge>& getEdgeHash() { return m_edgeHash; }
	};
}
#endif
