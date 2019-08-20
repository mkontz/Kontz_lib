#ifndef _EDGE_CLASS_HEADER_H__
#define _EDGE_CLASS_HEADER_H__

namespace MEK
{
    template<typename T>
	class Edge
	{
	private:
		T m_idx;
		T m_node1;
		T m_node2;

	public:
		Edge(T idx = 0, T n1 = 0, T n2 = 0) :
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

        T getIdx() const { return m_idx; }

        T getNode1() const { return m_node1; }
        void setNode1(T node) { m_node1 = node; }

        T getNode2() const { return m_node2; }
        void setNode2(T node) { m_node2 = node; }

        void setNodes(T node1, T node2)
        {
        	m_node1 = node1;
        	m_node2 = node2;
        }
	};
}

#endif
