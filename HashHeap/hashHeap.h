#ifndef _Hash_HEAP_H__
#define _Hash_HEAP_H__


#include "../HashTable/hash.h"
#include "../Heap2/KVHeap.h"

namespace MEK
{
	template <typename K, typename V>
    class HashHeap
    {
    private:
        Hash<K, V> m_hash;
        KVHeap<V, K> m_heap;

    public:
        HashHeap() :
            m_hash(),
            m_heap(HeapType::min)
        {}

        HashHeap(HeapType type) :
            m_hash(),
            m_heap(type)
        {}

        ~HashHeap()
        {}

        void push(K key, V value)
        {
            // add key or replace existing value
            m_hash[key] = value;

            // the heap will short on the first argument
            m_heap.push(value, key); // Note keys and values are swapped in heap
        }

        void pop()
        {
            updateFront();

            if (!m_heap.empty())
            {
                remove(m_heap.topValue()); // remove key form hash corresponding to top item in heap
                m_heap.pop();
            }
        }

        K frontKey()
        {
            K key = K();
            updateFront();

            if (!m_heap.empty())
            {
                key = m_heap.topValue(); // Note keys and values are swapped in heap
            }

            return key;
        }

        V frontValue()
        {
            V value = V();
            updateFront();

            if (!m_heap.empty())
            {
                value = m_heap.topKey(); // Note keys and values are swapped in heap
            }

            return value;
        }

        bool exist(K key)
        {
            return m_hash.exist(key);
        }

        bool remove(K key)
        {
            return m_hash.remove(key);
        }

        size_t size()
        {
            return m_hash.numberEntries();
        }

        bool empty()
        {
            return (0 == size());
        }

    private:
        void updateFront()
        {
            bool isValid = false;

            while (!(m_heap.empty()) && !isValid)
            {
                if (m_hash.exist(m_heap.topValue())) // Note keys and values are swapped in heap
                {
                    if (m_hash[m_heap.topValue()] == m_heap.topKey()) // Note keys and values are swapped in heap
                    {
                        isValid = true;
                    }
                    else
                    {
                        // remove top element heap since it does not match hash table
                        m_heap.pop();
                    }
                }
                else
                {
                    // remove top element from heap since it is not in hash table
                    m_heap.pop();
                }
            }
        }
    };
}

#endif