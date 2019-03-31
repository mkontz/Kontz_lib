#ifndef _MIN_HEAP_H__
#define _MIN_HEAP_H__

#include "baseListHeap.h"
#include "baseKVHeap.h"

namespace MEK
{
    template <typename T>
    class MinHeap : public BaseListHeap<T>
    {
    public:
        MinHeap()
        {}

        ~MinHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (this->m_heap.at(lower) < this->m_heap.at(higher));
        }
    };

    template <typename K, typename V>
    class MinKVHeap : public MEK::BaseKVHeap<K, V>
    {
    public:
        MinKVHeap()
        {}

        ~MinKVHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (this->m_heap.at(lower).key < this->m_heap.at(higher).key);
        }
    };
}

#endif