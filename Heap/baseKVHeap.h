#ifndef _BASE_KV_HEAP_H__
#define _BASE_KV_HEAP_H__

#include "baseListHeap.h"

namespace MEK
{
    template <typename K, typename V>
    struct Entry
    {
        K key;
        V value;
    };

    template <typename K, typename V>
    class BaseKVHeap : public BaseListHeap<Entry<K, V> >
    {
    public:
        BaseKVHeap()
        {}

        ~BaseKVHeap()
        {}

    private:
        virtual bool compare(size_t lower, size_t higher) = 0;

    public:
        K getKey()
        {
            // Set return value to default
            K retVal = K();

            if (!this->empty())
            {
                // peep at entry on top of heap and return key
                retVal = this->front().key;
            }

            return retVal;
        }

        V getValue()
        {
            // Set return value to default
            V retVal = V();

            if (!this->empty())
            {
                // peep at entry on top of heap and return value
                retVal = this->peep().value;
            }

            return retVal;
        }

        void addPair(K key, V value)
        {
            // Create key value pair entry
            Entry<K, V> entry;
            entry.key = key;
            entry.value = value;

            // Use base heap class to add entry and bubble
            this->add(entry);
        }
    };
}

#endif