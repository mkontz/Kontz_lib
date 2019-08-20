#ifndef _NODE_CLASS_HEADER_H__
#define _NODE_CLASS_HEADER_H__

#include "../HashTable/hash.h"

namespace MEK
{
	template<typename T>
	class Node
	{
	private:
		T m_idx;
		Hash<T, T> m_adjacentEdges;

	public:
		Node(T idx = 0) :
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

        T getIdx() const { return m_idx; }
        Hash<T, T> getAdjEdgeHash() const { return m_adjacentEdges; }
        std::vector<T> getAdjEdgeVector()
        {
        	std::vector<T> keys;
        	std::vector<T> values;
        	m_adjacentEdges.getAll(keys, values);

        	return keys;
        }

		void addEdge(T idx)
		{
			m_adjacentEdges.set(idx, idx);
		}

		bool removeEdge(T idx)
		{
			return m_adjacentEdges.remove(idx);
		}
	};
}

#endif