#ifndef _MAX_HEAP_H__
#define _MAX_HEAP_H__

#include "baseListHeap.h"
#include "baseKVHeap.h"

namespace MEK
{
    template <typename T>
    class MaxHeap : public BaseListHeap<T>
    {
    public:
        MaxHeap()
        {}

        ~MaxHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (this->m_heap.at(lower) > this->m_heap.at(higher));
        }
    };

    template <typename K, typename V>
    class MaxKVHeap : public BaseKVHeap<K, V>
    {
    public:
        MaxKVHeap()
        {}

        ~MaxKVHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (this->m_heap.at(lower).key > this->m_heap.at(higher).key);
        }
    };
}

#endif