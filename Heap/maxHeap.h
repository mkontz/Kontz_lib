#ifndef _MAX_HEAP_H__
#define _MAX_HEAP_H__

#include "baseListHeap.h"

namespace MEK
{
    template <typename T> class maxHeap : public MEK::BaseListHeap<T>
    {
    public:
        maxHeap()
        {}

        ~maxHeap()
        {}

    private:

        bool compare(size_t lower, size_t higher)
        {
            return (MEK::BaseListHeap<T>::m_heap.at(lower) > MEK::BaseListHeap<T>::m_heap.at(higher));
        }
    };
}

#endif