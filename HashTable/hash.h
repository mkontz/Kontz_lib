#ifndef _HASH_H__
#define _HASH_H__

#include <vector>
#include "../PrimeNumber/prime.h"

#include <iostream>
namespace MEK
{
    template <typename K, typename V> class Hash
    {
    private:
        struct Entry {
            K key;
            V value;
            Entry* pNext = NULL;
        };

        MEK::Primes<K> m_primeNumbers;
        std::vector<Entry*> m_table;

    public:
        Hash(size_t min_size)
        {
            // Create hash table sized using the smallest prime number larger than the min_size argument
            m_table.resize(m_primeNumbers.findNextPrime(min_size), NULL);
        }

        ~Hash()
        {
            Entry* pNext = NULL;

            for (size_t k = 0; k < m_table.size(); k++)
            {
                while (m_table.at(k) != NULL)
                {
                    pNext = m_table.at(k)->pNext;
                    delete m_table.at(k);
                    m_table.at(k) = pNext;
                }
            }
        }

        V& operator [] (const K key)
        {
            return get(key);
        }

        bool exist(K key)
        {
            Entry* pEntry = m_table.at(hashFunction(key));

            while ((pEntry != NULL) && (pEntry->key != key))
            {
                pEntry = pEntry->pNext;
            }

            return (pEntry != NULL);
        }

        V& get(K key)
        {
            Entry* pEntry = m_table.at(hashFunction(key));

            if (pEntry == NULL)
            {
                // Key not found create new entry
                pEntry = new Entry();
                pEntry->key = key;
                pEntry->pNext = NULL;

                m_table.at(hashFunction(key)) = pEntry;
            }
            else
            {
                while ((pEntry->key != key) && (pEntry->pNext != NULL))
                {
                    pEntry = pEntry->pNext;
                }

                if (pEntry->key != key)
                {
                    // Key not found create new entry
                    Entry* pNew = new Entry();
                    pNew->key = key;
                    pNew->pNext = NULL;

                    pEntry->pNext = pNew;
                    pEntry = pEntry->pNext;
                }
            }

            return pEntry->value;
        }

        void set(K key, const V value)
        {
            size_t hash = hashFunction(key);

            if (m_table.at(hash) == NULL)
            {
                // Create new element to store in hash table
                Entry* pNew = new Entry();
                pNew->key = key;
                pNew->value = value;
                pNew->pNext = NULL;

                m_table.at(hash) = pNew;
            }
            else
            {
                Entry* pEntry = m_table.at(hash);

                while ((pEntry->key != key) && (pEntry->pNext != NULL))
                {
                    pEntry = pEntry->pNext;
                }

                if (pEntry->key == key)
                {
                    // Found key, replace value
                    pEntry->value = value;
                }
                else
                {
                    // Create new element to store in hash table
                    Entry* pNew = new Entry();
                    pNew->key = key;
                    pNew->value = value;
                    pNew->pNext = NULL;

                    // put at end of linked list
                    pEntry->pNext = pNew;
                }
            }
        }

        bool remove(K key)
        {
            bool found = false;

            size_t hash = hashFunction(key);

            if (m_table.at(hash) != NULL)
            {
                Entry* pCurr = m_table.at(hash);
                Entry* pNext = pCurr->pNext;

                if (pCurr->key == key)
                {
                    delete pCurr;
                    m_table.at(hash) = pNext;
                    found = true;
                }
                else
                {
                    while (pNext != NULL)
                    {
                        if (pNext->key == key)
                        {
                            pCurr->pNext = pNext->pNext;
                            delete pNext;
                            found = true;
                            break;
                        }
                        else
                        {
                            pCurr = pNext;
                            pNext = pNext->pNext;
                        }
                    }
                }
            }

            return found;
        }

        void getAll(std::vector<K>& keyList, std::vector<V>& valueList)
        {
            keyList.resize(0);
            valueList.resize(0);

            for (size_t k = 0; k < m_table.size(); k++)
            {
                Entry* pNext = m_table.at(k);
                while (pNext != NULL)
                {
                    keyList.push_back(pNext->key);
                    valueList.push_back(pNext->value);

                    pNext = pNext->pNext;
                }
            }
        }

    private:
        size_t hashFunction(K key) { return (key % m_table.size()); }
    };
}

#endif