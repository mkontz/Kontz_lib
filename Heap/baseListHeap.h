#ifndef _BASE_LIST_HEAP_H__
#define _BASE_LIST_HEAP_H__

#include <vector>
#include <queue>

namespace MEK
{
    template <typename T> class BaseListHeap
    {
    protected:
        std::vector<T> m_heap;
        std::queue<size_t> m_dirty;

    public:
        BaseListHeap() :
            m_heap()
        {}

        ~BaseListHeap()
        {
        }

        T peep()
        {
            // Set return value to default
            T retVal = T();

            if (!empty())
            {
                // take top of heap
                retVal = m_heap.front();
            }

            return retVal;
        }

        T pop()
        {
            // Set return value to default
            T retVal = T();

            if (!empty())
            {
                // return/remove first/last element
                retVal = m_heap.front();

                if (1 == m_heap.size())
                {
                    m_heap.pop_back();
                }
                else
                {
                    //  move to fist spot, pop last element and mark as "dirty"
                    m_heap.front() = m_heap.back();
                    m_heap.pop_back();
                    m_dirty.push(0);

                    // bubble dirty elements
                    bubble();
                }
            }

            return retVal;
        }

        void add(T inVal)
        {
            // add element to back of heap and mark as "dirty"
            m_heap.push_back(inVal);
            m_dirty.push(m_heap.size() - 1);

            // bubble dirty elements
            bubble();
        }

        bool empty() { return m_heap.empty(); }
        size_t size() { return m_heap.size(); }
        std::vector<T> getHeap() { return m_heap; }

    protected:

        bool moveUp(size_t lower, size_t higher)
        {
            bool retVal = false;

            // check if indices are in range
            if (inRange(lower) && inRange(higher))
            {
                // call compare function
                retVal  = compare(lower, higher);
            }

            return retVal;
        }

        bool inRange(size_t k) { return ((0 <= k) && (k < m_heap.size())); }

        virtual bool compare(size_t lower, size_t higher) = 0;

        void bubble()
        {
            while (!m_dirty.empty())
            {
                size_t curr = m_dirty.front();
                m_dirty.pop();

                // check parent (higher on heap)
                if (0 < curr)
                {
                    size_t higher = (curr - 1) / 2;

                    if (moveUp(curr, higher))
                    {
                        swap(curr, higher);
                        continue;
                    }
                }

                // check two children (lower on heap)
                size_t left = 2*curr + 1;
                size_t right = 2*curr + 2;

                if (moveUp(left, curr) && moveUp(right, curr))
                {
                    if (moveUp(left, right))
                    {
                        swap(left, curr);
                    }
                    else
                    {
                        swap(right, curr);
                    }
                }
                else if (moveUp(left, curr))
                {
                    swap(left, curr);
                }
                else if (moveUp(right, curr))
                {
                    swap(right, curr);
                }
            }
        }

        void swap(size_t k1, size_t k2)
        {
            // swap two elements
            T tmp = m_heap.at(k1);
            m_heap.at(k1) = m_heap.at(k2);
            m_heap.at(k2) = tmp;

            // mark both as dirty
            m_dirty.push(k1);
            m_dirty.push(k2);
        }
    };
}

#endif