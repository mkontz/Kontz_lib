#ifndef _MAX_HEAP_H__
#define _MAX_HEAP_H__

#include "baseListHeap.h"

namespace MEK
{
    template <typename T>
    class MaxHeap : public MEK::BaseListHeap<T>
    {
    public:
        MaxHeap()
        {}

        ~MaxHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (MEK::BaseListHeap<T>::m_heap.at(lower) > MEK::BaseListHeap<T>::m_heap.at(higher));
        }
    };
}

#endif