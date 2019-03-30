#ifndef _MIN_HEAP_H__
#define _MIN_HEAP_H__

#include "baseListHeap.h"

namespace MEK
{
    template <typename T>
    class MinHeap : public MEK::BaseListHeap<T>
    {
    public:
        MinHeap()
        {}

        ~MinHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (MEK::BaseListHeap<T>::m_heap.at(lower) < MEK::BaseListHeap<T>::m_heap.at(higher));
        }
    };
}

#endif