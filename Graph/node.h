#ifndef _NODE_CLASS_HEADER_H__
#define _NODE_CLASS_HEADER_H__

#include "../HashTable/hash.h"
#include <iostream>
namespace MEK
{
	class Node
	{
	private:
		int m_idx;
		Hash<int, int> m_adjacentEdges;

	public:
		Node(int idx = -1) :
		 	m_idx(idx),
		 	m_adjacentEdges(20)
		{}

	 	~Node()
		{}

        Node& operator = (const Node& other)
        {
        	if (this != &other)
        	{
				m_idx = getIdx();
				m_adjacentEdges = getAdjEdgeHash();		
        	}

            return *this;
        }

        int getIdx() const { return m_idx; }
        Hash<int, int> getAdjEdgeHash() const { return m_adjacentEdges; }
        std::vector<int> getAdjEdgeVector()
        {
        	std::vector<int> keys;
        	std::vector<int> values;
        	m_adjacentEdges.getAll(keys, values);

        	return keys;
        }

		void addEdge(int idx)
		{
			m_adjacentEdges.set(idx, idx);
		}

		bool removeEdge(int idx)
		{
			return m_adjacentEdges.remove(idx);
		}
	};
}

#endif