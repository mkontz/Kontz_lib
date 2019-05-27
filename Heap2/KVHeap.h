#ifndef _KV_HEAP_H__
#define _KV_HEAP_H__

#include <queue>
#include <utility>

namespace MEK
{
    enum HeapType {
        max,
        min
    };

    template <typename K, typename V>
    class Compare
    {
    private:
        HeapType m_type;

    public:
        Compare() : 
            m_type(HeapType::max)
        {}

        void setType(const HeapType type) { m_type = type; }

        bool operator() (const std::pair<K, V>& kv1, const std::pair<K, V>& kv2)
        {
            return (m_type == HeapType::max) ? (kv1.first < kv2.first) : (kv1.first > kv2.first);
        }
    };

	template <typename K, typename V>
    class KVHeap : public std::priority_queue<std::pair<K, V>, std::vector<std::pair<K, V> >, Compare<K, V> >
    {
    public:
        KVHeap()
        {}

        KVHeap(HeapType type)
        {
            this->comp.setType(type);
        }

        ~KVHeap()
        {}

        void push(K key, V value)
        {
            std::pair<K, V> entry;
            entry.first = key;
            entry.second = value;
            
            push(entry);
        }

        void push(const std::pair<K, V>& entry)
        {
            std::priority_queue<std::pair<K, V>, std::vector<std::pair<K, V> >, Compare<K, V> >::push(entry);
        }

        K topKey() const
        {

            return this->top().first;
        }

        V topValue() const
        {
            return this->top().second;
        }
    };

}

#endif