#ifndef ADD_SMART_POINTER_CLASS_HEADER_H__
#define ADD_SMART_POINTER_CLASS_HEADER_H__

namespace MEK
{
	template<class T> class SmartPointer
	{
	public:
		T* m_pObj;
		unsigned* m_pCnt;

		SmartPointer() :
			m_pObj(NULL),
			m_pCnt(NULL)
		{}

		SmartPointer(T* pObj) :
			m_pObj(pObj),
			m_pCnt(NULL)
		{
			if (m_pObj)
			{
				m_pCnt = new unsigned();
				(*m_pCnt) = 1;
			}
		}

		SmartPointer(SmartPointer<T>& sPntr) :
			m_pObj(sPntr.m_pObj),
			m_pCnt(sPntr.m_pCnt)
		{
			if (m_pCnt)
			{
				(*m_pCnt)++;
			}
		}

		virtual ~SmartPointer()
		{
			clear();
		}

		SmartPointer<T>& operator = (SmartPointer<T>& other)
		{
			if (m_pObj != other.m_pObj)
			{
				// remove association with previous object
				clear();

				// change association to match other
				m_pObj = other.m_pObj;
				m_pCnt = other.m_pCnt;

				if (m_pCnt)
				{
					(*m_pCnt)++;
				}
			}

			return *this;
		}

		// Overload to access object
		T& operator * () { return *m_pObj; }
		T* operator -> () { return m_pObj; }

		// methods to addcess smart pointer info
		char* getSmPntr() { return (char*) m_pObj; }
		unsigned getSmCnt() { return (m_pCnt) ? *m_pCnt : 0; }

		// clear or reset smart pointer
		void clear ()
		{
			if (m_pCnt)
			{
				(*m_pCnt)--;

				if (*m_pCnt == 0)
				{
					// this is last instance of smart pointer....so clean up
					delete m_pCnt;
					delete m_pObj;
				}

				// This indicates that smartpointer is not pointing to object
				m_pCnt = NULL;
				m_pObj = NULL;
			}
		}
	};
}



#endif