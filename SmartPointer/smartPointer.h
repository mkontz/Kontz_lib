#include <iostream>

template<class T> class SmartPointer
{
public:
	T* m_pObj;
	unsigned* m_pCnt;

	SmartPointer() :
		m_pObj(NULL),
		m_pCnt(NULL)
	{
	}

	SmartPointer(T* pObj) :
		m_pObj(pObj),
		m_pCnt()
	{
		if (NULL == m_pCnt)
			m_pCnt = new unsigned();

		*m_pCnt = 1;
	}

	SmartPointer(SmartPointer<T>& sPntr) :
		m_pObj(sPntr.m_pObj),
		m_pCnt(sPntr.m_pCnt)
	{
		if (NULL == m_pCnt)
			m_pCnt = new unsigned();	
		
		(*m_pCnt)++;
	}

	virtual ~SmartPointer()
	{
		remove();
	}

	SmartPointer<T>& operator = (SmartPointer<T>& other)
	{
		if (this->m_pObj != other.m_pObj)
		{
			// remove association with previous object
			remove();

			// change association to match other
			m_pObj = other.m_pObj;
			m_pCnt = other.m_pCnt;
			if (m_pCnt)
				(*m_pCnt)++;		
		}

		return *this;
	}

	T& operator * () { return *m_pObj; }

	T* operator -> () { return m_pObj; }

	void printPntrInfo()
	{
		if (NULL == m_pCnt)
			std:: cout << "    Object pointer: " << m_pObj << ", count pointer: " << m_pCnt << std::endl;
		else
			std:: cout << "    Object pointer: " << m_pObj << ", count pointer: " << m_pCnt << ", number: " << *m_pCnt << std::endl;
	}

protected:
	void remove()
	{
		// decrement counter since smart pointer is being deleted
		if (NULL != m_pCnt)
		{
			if (0 < *m_pCnt)
				(*m_pCnt)--;

			if (*m_pCnt == 0)
			{
				// this is last instance of smart pointer....so clean up
				delete m_pCnt;

				
				if (NULL != m_pObj)
					delete m_pObj;
			}

		}
	}
};
