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
        size_t m_numEntries;
        bool m_autoResizeEnabled;

    public:
        Hash() :
            m_numEntries(0),
            m_autoResizeEnabled(true)
        {
            // Create hash table sized using the smallest prime number larger than the min_size argument
            m_table.resize(m_primeNumbers.findNextPrime(100), NULL);
        }

        Hash(size_t min_size) :
            m_numEntries(0),
            m_autoResizeEnabled(true)
        {
            // Create hash table sized using the smallest prime number larger than the min_size argument
            m_table.resize(m_primeNumbers.findNextPrime(min_size), NULL);
        }

        ~Hash()
        {
            removeAll();
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
            checkAutoResize();

            Entry* pEntry = m_table.at(hashFunction(key));

            if (pEntry == NULL)
            {
                // Key not found create new entry
                m_table.at(hashFunction(key)) = createNewEntry(key);
                pEntry = m_table.at(hashFunction(key));
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
                    pEntry->pNext = createNewEntry(key);
                    pEntry = pEntry->pNext;
                }
            }

            return pEntry->value;
        }

        void set(K key, const V value)
        {
            checkAutoResize();

            size_t hash = hashFunction(key);

            if (m_table.at(hash) == NULL)
            {
                // Create new element to store in hash table
                m_table.at(hash) = createNewEntry(key, value);
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
                    // Create new element and put at end of linked list
                    pEntry->pNext = createNewEntry(key, value);
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
                    m_numEntries--;
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
                            m_numEntries--;
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

        void resize(size_t min_size)
        {
            // get all value currently in the hash table and put in lists
            std::vector<K> keyList;
            std::vector<V> valueList;
            getAll(keyList, valueList);

            // Remove all entries from hash table
            removeAll();

            // Create hash table sized using the smallest prime number larger than the min_size argument
            m_table.resize(m_primeNumbers.findNextPrime(min_size), NULL);

            // Put key, value pairs back in newly resize hash table
            for (size_t k = 0; k < keyList.size(); k++)
            {
                set(keyList.at(k), valueList.at(k));
            }
        }

        void removeAll()
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

            m_numEntries = 0;
        }

        size_t numberEntries() { return m_numEntries; }

        size_t hashTableSize() { return m_table.size(); }

        void enableAutoResize(bool isEnabled) { m_autoResizeEnabled = isEnabled; }
        bool getAutoResize() { return m_autoResizeEnabled; }

    private:

        Entry* createNewEntry(K key)
        {
            // Create new entry
            Entry* pEntry = new Entry();
            pEntry->key = key;
            pEntry->pNext = NULL;

            // Increment number of entry counter
            m_numEntries++;

            return pEntry;

        }

        Entry* createNewEntry(K key, V value)
        {
            Entry* pEntry = createNewEntry(key);
            pEntry->value = value;

            return pEntry;
        }

        bool checkAutoResize()
        {
            bool retVal = false;

            if (m_autoResizeEnabled && (m_table.size() < (m_numEntries * 2 )))
            {
                resize(m_numEntries * 10);
                retVal = true;
            }

            return retVal;
        }

        size_t hashFunction(K key) { return (key % m_table.size()); }
    };
}

#endif