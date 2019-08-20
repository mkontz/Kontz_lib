#ifndef _GRAPH_CLASS_HEADER_H__
#define _GRAPH_CLASS_HEADER_H__

#include "node.h"
#include "edge.h"
#include "../HashTable/hash.h"
#include <vector>

//*********************************************************************
//  Graph Class
//*********************************************************************

namespace MEK
{
	template<typename T, class N = Node<T>, class E = Edge<T> >
	class Graph
	{
	private:
		Hash<T, N> m_nodeHash;
		Hash<T, E> m_edgeHash;

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

		virtual void addNode(T idx)
		{
			N tmp(idx);
			m_nodeHash.set(idx, tmp);
		}

		virtual bool deleteNode(T idx)
		{
			bool found = false;

			if (m_nodeHash.exist(idx))
			{
				std::vector<T> edgeList = m_nodeHash[idx].getAdjEdgeVector();

				for (size_t k = 0; k < edgeList.size(); k++)
				{
					deleteEdge(edgeList.at(k));
				}

				m_nodeHash.remove(idx);

				found = true;
			}

			return found;
		}

		virtual bool addEdge(T idx, T n1, T n2)
		{
			bool retVal = false;

			if (m_edgeHash.exist(idx))
			{
				deleteEdge(idx);
			}

			if (m_nodeHash.exist(n1) && m_nodeHash.exist(n2))
			{
				m_edgeHash[idx] = E(idx, n1, n2);

				(m_nodeHash[n1]).addEdge(idx);
				(m_nodeHash[n2]).addEdge(idx);

				retVal= true;
			}

			return retVal;
		}

		virtual bool deleteEdge(T idx)
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

		Hash<T, N>& getNodeHash() { return m_nodeHash; }
		Hash<T, E>& getEdgeHash() { return m_edgeHash; }
	};
}
#endif
