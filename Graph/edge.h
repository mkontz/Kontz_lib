#ifndef _EDGE_CLASS_HEADER_H__
#define _EDGE_CLASS_HEADER_H__

namespace MEK
{
	class Edge
	{
	private:
		int m_idx;
		int m_node1;
		int m_node2;

	public:
		Edge(int idx = -1, int n1 = -1, int n2 = -1) :
		 	m_idx(idx),
		 	m_node1(n1),
		 	m_node2(n2)
		{ }

		~Edge()
		{ }

        Edge& operator = (const Edge& other)
        {
        	if (this != &other)
        	{
        		m_idx = other.getIdx();
        		m_node1 = other.getNode1();
        		m_node2 = other.getNode2();
        	}

            return *this;
        }

        int getIdx() const { return m_idx; }

        int getNode1() const { return m_node1; }
        void setNode1(int node) { m_node1 = node; }

        int getNode2() const { return m_node2; }
        void setNode2(int node) { m_node2 = node; }

        void setNodes(int node1, int node2)
        {
        	m_node1 = node1;
        	m_node2 = node2;
        }
	};
}

#endif
