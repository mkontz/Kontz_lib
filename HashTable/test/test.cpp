#include <iostream>
#include "../hash.h"
#include <ctime>

using namespace std;

struct Combo
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint32_t value;
};

// Compares two combos based on value.
bool compareCombos(Combo c1, Combo c2)
{
    bool retVal = true;

    if (c1.value == c2.value)
    {
        if (c1.a == c2.a)
        {
            if (c1.b == c2.b)
            {
                if (c1.c == c2.c)
                {
                    retVal = (c1.d < c2.d);
                }
                else
                {
                    retVal = (c1.c < c2.c);
                }
            }
            else
            {
                retVal = (c1.b < c2.b);
            }
        }
        else
        {
            retVal = (c1.a < c2.a);
        }
    }
    else
    {
        retVal = (c1.value < c2.value);
    }

    return retVal;
};

struct Pair
{
    uint32_t a;
    uint32_t b;
    uint32_t value;
};

int main()
{
    bool passed = true;
    bool allTestsPassed = true;

    {
        cout << "Testing Hash class using set and get methods.\n";
        MEK::Hash<uint16_t, float> hashtable(20); // Next prime -> 23

        bool passed = true;

        cout << "    Check first entries.\n";

        uint16_t key = 345;
        float value = 5.34;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        key = 45 ;
        value = 3.73;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        cout << "    Check over writing entries.\n";

        key = 345 ;
        value = 1.489;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        key = 45 ;
        value = 34.6789;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        cout << "    Check collisions.\n";

        key = 345 % 23 ;
        value = 112.5;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        key = 345 ;
        value = 1.489;
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        key = 45 % 23 ;
        value = 12.5345;
        hashtable.set(key, value);
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        key = 45 ;
        value = 34.6789;
        if (hashtable.get(key) == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable.get(key) << ", but " << value << " is expected - Failed\n";
        }

        cout << "\n";

        allTestsPassed &= passed;

        cout << "Testing copying hashtable using ''='' operator overload\n";
        MEK::Hash<uint16_t, float> hashCopy(100);
        hashCopy = hashtable;

        cout << "    Check size of elements.\n";

        cout << "        Prime number class copied correctly, size of prime number vectors match";
        if (hashCopy.getPrimes().getPrimes().size() != hashtable.getPrimes().getPrimes().size())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Size of hash table copied correctly";
        if (hashCopy.hashTableSize() != hashtable.hashTableSize())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Number of entries match";
        if (hashCopy.numberEntries() != hashtable.numberEntries())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Auto Resize Enable flags match";
        if (hashCopy.hashTableSize() != hashtable.hashTableSize())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "    Check all keys and values.\n";

        std::vector<uint16_t> orgKeyList;
        std::vector<float> orgValueList;
        hashtable.getAll(orgKeyList, orgValueList);

        std::vector<uint16_t> copyKeyList;
        std::vector<float> copyValueList;
        hashCopy.getAll(copyKeyList, copyValueList);

        if ((orgKeyList.size() != orgValueList.size()) ||
            (orgKeyList.size() != copyKeyList.size()) ||
            (orgValueList.size() != copyValueList.size()))
        {
            cout << "        Hash table did not copy correctly because number of keys and values don't match - Failed\n";
            cout << "            Number of keys (orininal):     " << orgKeyList.size() << "\n";
            cout << "            Number of values (orininal):   " << orgValueList.size() << "\n";
            cout << "            Number of keys (copy):         " << copyKeyList.size() << "\n";
            cout << "            Number of values (copy):       " << copyValueList.size() << "\n";

            passed = false;
        }
        else
        {
            for (size_t k = 0; k < orgKeyList.size(); k++)
            {
                if (orgKeyList.at(k) != copyKeyList.at(k))
                {
                    cout << "        Copied key does not match - Failed\n";
                    passed = false;
                }

                if (orgValueList.at(k) != copyValueList.at(k))
                {
                    cout << "        Copied value does not match - Failed\n";
                    passed = false;
                }
            }
        }

        if (passed)
        {
            cout << "        Hash table copied correct - Passed\n";
        }


        cout << "    Check that hash tables are decoupled.\n";

        key = 45 % 23 ;
        value = 11.568;
        hashtable.set(key, value);

        key = 45 ;
        value = -234.239840;
        hashtable.set(key, value);

        cout << "        Hash tables are decoupled";
        if (hashtable[45 % 23] != hashCopy[45 % 23] && hashtable[45] != hashCopy[45])
        {
            cout << " - Passed\n";
        }
        else
        {
            if (hashtable[45 % 23] == hashCopy[45 % 23])
            {
                cout << ": hashtable[45 % 23] != hashCopy[45 % 23] - Failed\n";
            }

            if (hashtable[45] == hashCopy[45])
            {
                cout << ": hashtable[45] != hashCopy[45] - Failed\n";
            }

            passed = false;
        }


        allTestsPassed &= passed;
    }

    {
        cout << "\nTesting Hash class using [] overload.\n";
        cout << "    Creating hash table.\n";
        MEK::Hash<uint32_t, double> hashtable(20); // Next prime -> 23
        cout << "    Finished creating hash table.\n";

        passed = true;

        cout << "    Check first entries.\n";

        uint32_t key = 345;
        double value = 5.34;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        key = 45 ;
        value = 3.73;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        cout << "    Check over writing entries.\n";

        key = 345 ;
        value = 1.489;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        key = 45 ;
        value = 34.6789;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        cout << "    Check collisions.\n";

        key = 345 % 23 ;
        value = 112.5;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        key = 345 ;
        value = 1.489;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        key = 45 % 23 ;
        value = 12.5345;
        hashtable[key] = value;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        key = 45;
        value = 34.6789;
        if (hashtable[key] == value)
        {
            cout << "        Hash table value at " << key << " is " << value << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Hash table value at " << key << " is " << hashtable[key] << ", but " << value << " is expected - Failed\n";
        }

        cout << "\n";

        ////////////////////////////////////////////////////////////////
        cout << "Testing Hash class using exist methods.\n";
        ////////////////////////////////////////////////////////////////

        cout << "    Check 4 keys that exist\n";

        key = 0;
        if (hashtable.exist(key))
        {
            cout << "        Entry with key " << key << " exists - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Entry with key " << key << " does not exists - Failed\n";
        }

        key = 22;
        if (hashtable.exist(key))
        {
            cout << "        Entry with key " << key << " exists - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Entry with key " << key << " does not exists - Failed\n";
        }

        key = 45;
        if (hashtable.exist(key))
        {
            cout << "        Entry with key " << key << " exists - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Entry with key " << key << " does not exists - Failed\n";
        }

        key = 345;
        if (hashtable.exist(key))
        {
            cout << "        Entry with key " << key << " exists - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Entry with key " << key << " does not exists - Failed\n";
        }

        cout << "    Check 2 keys that don't exist and won't collide with existing entries\n";

        key = 1;
        if (hashtable.exist(key))
        {
            passed = false;
            cout << "        Entry with key " << key << " exists - Failed\n";
        }
        else
        {
            cout << "        Entry with key " << key << " does not exists - Passed\n";
        }

        key = 111;
        if (hashtable.exist(key))
        {
            passed = false;
            cout << "        Entry with key " << key << " exists - Failed\n";
        }
        else
        {
            cout << "        Entry with key " << key << " does not exists - Passed\n";
        }

        cout << "    Check 2 keys that don't exist and will collide with existing entries\n";

        key = 23*3;
        if (hashtable.exist(key))
        {
            passed = false;
            cout << "        Entry with key " << key << " exists - Failed\n";
        }
        else
        {
            cout << "        Entry with key " << key << " does not exists - Passed\n";
        }

        key = 22 + 23 * 8;
        if (hashtable.exist(key))
        {
            passed = false;
            cout << "        Entry with key " << key << " exists - Failed\n";
        }
        else
        {
            cout << "        Entry with key " << key << " does not exists - Passed\n";
        }

        cout << "\n";

        cout << "Testing copying constructor\n";
        MEK::Hash<uint32_t, double> hashCopy(1000);
        hashCopy = hashtable;

        cout << "    Check size of elements.\n";

        cout << "        Prime number class copied correctly, size of prime number vectors match";
        if (hashCopy.getPrimes().getPrimes().size() != hashtable.getPrimes().getPrimes().size())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Size of hash table copied correctly";
        if (hashCopy.hashTableSize() != hashtable.hashTableSize())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Number of entries match";
        if (hashCopy.numberEntries() != hashtable.numberEntries())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "        Auto Resize Enable flags match";
        if (hashCopy.hashTableSize() != hashtable.hashTableSize())
        {
            cout << " - Failed\n";
            passed = false;
        }
        else
        {
            cout << " - Passed\n";
        }

        cout << "    Check all keys and values.\n";

        std::vector<uint32_t> orgKeyList;
        std::vector<double> orgValueList;
        hashtable.getAll(orgKeyList, orgValueList);

        std::vector<uint32_t> copyKeyList;
        std::vector<double> copyValueList;
        hashCopy.getAll(copyKeyList, copyValueList);

        if ((orgKeyList.size() != orgValueList.size()) ||
            (orgKeyList.size() != copyKeyList.size()) ||
            (orgValueList.size() != copyValueList.size()))
        {
            cout << "        Hash table did not copy correctly because number of keys and values don't match - Failed\n";
            cout << "            Number of keys (orininal):     " << orgKeyList.size() << "\n";
            cout << "            Number of values (orininal):   " << orgValueList.size() << "\n";
            cout << "            Number of keys (copy):         " << copyKeyList.size() << "\n";
            cout << "            Number of values (copy):       " << copyValueList.size() << "\n";

            passed = false;
        }
        else
        {
            for (size_t k = 0; k < orgKeyList.size(); k++)
            {
                if (orgKeyList.at(k) != copyKeyList.at(k))
                {
                    cout << "        Copied key does not match - Failed\n";
                    passed = false;
                }

                if (orgValueList.at(k) != copyValueList.at(k))
                {
                    cout << "        Copied value does not match - Failed\n";
                    passed = false;
                }
            }
        }

        if (passed)
        {
            cout << "        Hash table copied correct - Passed\n";
        }


        cout << "    Check that hash tables are decoupled.\n";

        key = 45 % 23 ;
        value = 11.568;
        hashtable.set(key, value);

        key = 45 ;
        value = -234.239840;
        hashtable.set(key, value);

        cout << "        Hash tables are decoupled";
        if (hashtable[45 % 23] != hashCopy[45 % 23] && hashtable[45] != hashCopy[45])
        {
            cout << " - Passed\n";
        }
        else
        {
            if (hashtable[45 % 23] == hashCopy[45 % 23])
            {
                cout << ": hashtable[45 % 23] != hashCopy[45 % 23] - Failed\n";
            }

            if (hashtable[45] == hashCopy[45])
            {
                cout << ": hashtable[45] != hashCopy[45] - Failed\n";
            }

            passed = false;
        }


        ////////////////////////////////////////////////////////////////
        cout << "\nTesting Hash class using remove and getAll methods.\n";
        ////////////////////////////////////////////////////////////////

        cout << "    Checking that getAll methods return 4 entries.\n";

        std::vector<uint32_t> keyList;
        std::vector<double> valueList;
        hashtable.getAll(keyList, valueList);

        size_t expectLen = hashtable.numberEntries();
        if ((keyList.size() == expectLen) && (valueList.size() == expectLen))
        {
            cout << "        Both key and value list have " << expectLen << " as expected - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Number of keys: " << keyList.size() << ", number of values: " << valueList.size() << ", expected: " << expectLen << " - Failed\n";
        }

        cout << "        Key-value pairs from hashtable\n";
        for (size_t k = 0; k < keyList.size(); k++)
        {
            cout << "            (" << keyList.at(k) << ", " << valueList.at(k) << ")\n";
        }

        cout << "    Remove 2 colliding entry and re-check getAll methods return 2 entries.\n";

        hashtable.remove(45);
        hashtable.remove(45 % 23);
        hashtable.getAll(keyList, valueList);


        expectLen = hashtable.numberEntries();
        if ((keyList.size() == expectLen) && (valueList.size() == expectLen))
        {
            cout << "        Both key and value list have " << expectLen << " as expected - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Number of keys: " << keyList.size() << ", number of values: " << valueList.size() << ", expected: " << expectLen << " - Failed\n";
        }

        cout << "        Key-value pairs from hashtable\n";
        for (size_t k = 0; k < keyList.size(); k++)
        {
            cout << "            (" << keyList.at(k) << ", " << valueList.at(k) << ")\n";
        }
        cout << "\n";


        allTestsPassed = (allTestsPassed && passed);
    }

    {
        passed = true;

        cout << "Testing Combinations of two integer.\n";
        std::clock_t begin = clock();
        std::clock_t end = clock();

        uint32_t N = 100;

        vector<Combo> bruteForceCombos;
        Combo tmpCombo;

        cout << "    Starting brute force test:\n";
        begin = clock();
        for (uint32_t a = 0; a <= N; a++)
        {
        //     if ((a % 100) == 0)
        //     {
        //      cout << "        " << a << "\n";
        //     }
            for (uint32_t b = 0; b <= N; b++)
            {
                for (uint32_t c = 0; c <= N; c++)
                {
                    for (uint32_t d = 0; d <= N; d++)
                    {
                        if ((a*a + b*b) == (c*c + d*d))
                        {
                            tmpCombo.a = a;
                            tmpCombo.b = b;
                            tmpCombo.c = c;
                            tmpCombo.d = d;
                            tmpCombo.value = a*a + b*b;

                            bruteForceCombos.push_back(tmpCombo);
                        }
                    }
                }
            }
        }
        end = clock();
        cout << "    Completed brute force test:\n\n";

        double bruteForceTime = double(end - begin) / CLOCKS_PER_SEC;

        cout << "    Starting hash table test:\n";
        begin = clock();

        Pair tmpPair;
        vector<Pair> tmpVector;

        vector<Combo> hashCombos;

        MEK::Hash<uint32_t, vector<Pair> > hashtable;


        for (uint32_t a = 0; a <= N; a++)
        {
            // if ((a % 100) == 0)
            // {
            //  cout << "        " << a << "\n";
            // }

            for (uint32_t b = a; b <= N; b++)
            {
                tmpPair.a = a;
                tmpPair.b = b;
                tmpPair.value = a*a + b*b;

                if (hashtable.exist(tmpPair.value))
                {
                    // start with existing pair vector
                    tmpVector = hashtable.get(tmpPair.value);
                }
                else
                {
                    // start woth empty vector
                    tmpVector.resize(0);
                }

                tmpVector.push_back(tmpPair);
                hashtable.set(tmpPair.value, tmpVector);
            }
        }

        std::vector<uint32_t> keyList;
        std::vector<vector<Pair> > valueList;
        hashtable.getAll(keyList, valueList);

        // cout << "    Hash table summary:\n";
        // for (size_t k = 0; k < keyList.size(); k++)
        // {
        //  cout << "        Key = " << keyList.at(k) << "\n";
        //  for (size_t p = 0; p < valueList.at(k).size(); p++)
        //  {
        //      tmpPair = valueList.at(k).at(p);
        //      cout << "            (" << valueList.at(k).at(p).a << ", " << valueList.at(k).at(p).b << ")\n";
        //  }
        // }

        // Iterate through hash table item by key (total value) and create list of combinations
        uint32_t tmp;
        for (size_t k = 0; k < keyList.size(); k++)
        {
            tmpVector.resize(0);
            for (size_t p = 0; p < valueList.at(k).size(); p++)
            {
                tmpPair = valueList.at(k).at(p);

                if (tmpPair.a == tmpPair.b)
                {
                    tmpVector.push_back(tmpPair);
                }
                else
                {
                    tmpVector.push_back(tmpPair);
                    tmp = tmpPair.a;
                    tmpPair.a = tmpPair.b;
                    tmpPair.b = tmp;
                    tmpVector.push_back(tmpPair);
                }
            }

            tmpCombo.value = keyList.at(k);
            for (size_t p1 = 0; p1 < tmpVector.size(); p1++)
            {
                for (size_t p2 = 0; p2 < tmpVector.size(); p2++)
                {
                    tmpCombo.a = tmpVector.at(p1).a;
                    tmpCombo.b = tmpVector.at(p1).b;
                    tmpCombo.c = tmpVector.at(p2).a;
                    tmpCombo.d = tmpVector.at(p2).b;
                    hashCombos.push_back(tmpCombo);
                }
            }
        }

        end = clock();
        cout << "    Completed hash table test:\n\n";

        double hashTime = double(end - begin) / CLOCKS_PER_SEC;

        sort(hashCombos.begin(), hashCombos.end(), compareCombos);
        sort(bruteForceCombos.begin(), bruteForceCombos.end(), compareCombos);

        if (bruteForceCombos.size() != hashCombos.size())
        {
            cout << "Length of combos don't match - FAILED\n";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < bruteForceCombos.size(); k++)
            {
                if ((bruteForceCombos.at(k).a != hashCombos.at(k).a) ||
                    (bruteForceCombos.at(k).b != hashCombos.at(k).b) ||
                    (bruteForceCombos.at(k).c != hashCombos.at(k).c) ||
                    (bruteForceCombos.at(k).d != hashCombos.at(k).d) ||
                    (bruteForceCombos.at(k).value != hashCombos.at(k).value))
                {
                    cout << "    Combos don't match - FAILED\n";
                    passed = false;
                }
            }
        }

        if (passed)
        {
            cout << "    Some number of combos and all combos match - Passed\n\n";
        }

        // cout << "    Brute force combos\n";
        // for (size_t k = 0; k < bruteForceCombos.size(); k++)
        // {
        //  tmpCombo = bruteForceCombos.at(k);

        //  cout << "        " << tmpCombo.a << "^2 + " << tmpCombo.b << "^2 = ";
        //  cout << tmpCombo.c << "^2 + " << tmpCombo.d << "^2 = " << tmpCombo.value << "\n";
        // }
        // cout << endl;

        // cout << "    Hash combos\n";
        // for (size_t k = 0; k < hashCombos.size(); k++)
        // {
        //  tmpCombo = hashCombos.at(k);

        //  cout << "        " << tmpCombo.a << "*" << tmpCombo.a << " + " << tmpCombo.b << "*" << tmpCombo.b << " = ";
        //  cout << tmpCombo.c << "*" << tmpCombo.c << " + " << tmpCombo.d << "*" << tmpCombo.d << " = " << tmpCombo.value << "\n";
        // }
        // cout << endl;

        cout << "    Summary:\n";
        cout << "        Brute force time = " << bruteForceTime << ", hash table time = " << hashTime << endl; 
        cout << "        Brute force size = " << bruteForceCombos.size() << ", hash table size = " << hashCombos.size() << endl << endl;

        ////////////////////////////////////////////////////////////////
        cout << "Testing Hash class using resize, numberEntries, hashTableSize and removeAll methods.\n";
        ////////////////////////////////////////////////////////////////

        cout << "    Checking entries before and after resize.\n";

        std::vector<uint32_t> keyListInitial;
        std::vector<vector<Pair> > valueListInitial;
        hashtable.getAll(keyListInitial, valueListInitial);

        size_t initSize = hashtable.hashTableSize();
        size_t initEntries = hashtable.numberEntries();
        hashtable.resize(hashtable.numberEntries() * 2);
        size_t afterSize = hashtable.hashTableSize();
        size_t afterEntries = hashtable.numberEntries();

        std::vector<uint32_t> keyListAfter;
        std::vector<vector<Pair> > valueListAfter;
        hashtable.getAll(keyListAfter, valueListAfter);

        cout << "        hash table size: before: " << initSize << ", after: " << afterSize << "\n";
        if ((valueListInitial.size() == valueListAfter.size()) && (keyListInitial.size() == valueListInitial.size()) && (keyListAfter.size() == valueListAfter.size()) && (initEntries == afterEntries) && (initEntries == valueListInitial.size()))
        {
            cout << "        Number of entries match: " << afterEntries << " - Passed\n";
        }
        else
        {
            passed = false;
            cout << "        Number of entries changed during resize() - Failed\n";
            cout << "            Number of inital keys: " << keyListInitial.size() << "\n";
            cout << "            Number of inital values: " << valueListInitial.size() << "\n";
            cout << "            Number of inital entries: " << initEntries << "\n";
            cout << "            Number of final keys: " << keyListAfter.size() << "\n";
            cout << "            Number of final values: " << valueListAfter.size() << "\n";
            cout << "            Number of final entries: " << afterEntries << "\n";
        }

        cout << "    Remove all entries.\n";

        hashtable.removeAll();
        hashtable.getAll(keyListAfter, valueListAfter);

        if ((keyListAfter.size() == 0) && (valueListAfter.size() == 0))
        {
            cout << "        There are no key, value pairs as expected - Passed\n\n";
        }
        else
        {
            passed = false;
            cout << "        There are key, value pairs which is not expected - Failed\n\n";
        }

        allTestsPassed = (allTestsPassed && passed);
    }

    ////////////////////////////////////////////////////////////////
    // Summary of all tests.
    ////////////////////////////////////////////////////////////////
    if (allTestsPassed)
    {
        std::cout << "All tests passed!!\n\n";
    }
    else
    {
        std::cout << "Not all tests passed!!\n\n";
    }
    ////////////////////////////////////////////////////////////////

    return 0;
}




