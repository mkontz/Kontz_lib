#include <iostream>
#include <algorithm>
#include <cmath>
#include "testKVHeap.h"

using namespace std;

bool compareDoubleIntMax(pair<double, int> p1, pair<double, int> p2) { return (p1.first > p2.first); }

bool compareDoubleIntMin(pair<double, int> p1, pair<double, int> p2) { return (p1.first < p2.first); }

bool testKVHeap()
{
    bool allTestsPassed = true;
    bool passed = true;

    cout << "Testing max-heap class.\n";

    {
        cout << "    Checking KV heap with no min/max type argument (Default should be max).\n";
        passed = true;

        MEK::KVHeap<double, int> heap;
        pair<double, int> entry;
        vector<pair<double, int> > expected; 
        double maxValue = -10.0;
        double value;

        cout << "        Add entries to heap while verifying that top of head is the maximun." << endl;
        for (int k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<double>(k));

            if (maxValue < value)
            {
                maxValue = value;
            }

            entry.first = value;
            entry.second = k;

            heap.push(entry);
            expected.push_back(entry);

            if (maxValue != heap.top().first)
            {
                cout << "                Top of heap = " << heap.top().first << "), expected = ";
                cout << maxValue << " - Failed" << endl;
                passed = false;
            }
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMax);

        cout << "        Pop all values while checking the order/maximum ...\n";
        if (expected.size() != heap.size())
        {
            cout << "        Size of heap (" << heap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != heap.top().first) || (expected.at(k).second != heap.top().second))
                {
                    cout << "                Key = " << heap.top().first;
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << heap.top().second;
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                heap.pop();
            }
        }

        if (passed)
        {
            cout << "        All tests passed!" << endl;
        }

        allTestsPassed &= passed;
    }

    {
        cout << "    Checking KV heap with max type argument.\n";
        passed = true;

        MEK::KVHeap<float, int16_t> heap(MEK::HeapType::max);
        pair<float, int16_t> entry;
        vector<pair<float, int16_t> > expected; 
        float maxValue = -10.0f;
        float value;

        cout << "        Add entries to heap while verifying that top of head is the maximun." << endl;
        for (int16_t k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<float>(k));

            if (maxValue < value)
            {
                maxValue = value;
            }

            entry.first = value;
            entry.second = k;

            heap.push(entry.first, entry.second);
            expected.push_back(entry);

            if (maxValue != heap.top().first)
            {
                cout << "                Top of heap = " << heap.topKey() << "), expected = ";
                cout << maxValue << " - Failed" << endl;
                passed = false;
            }
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMax);

        cout << "        Pop all values while checking the order/maximum ...\n";
        if (expected.size() != heap.size())
        {
            cout << "        Size of heap (" << heap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != heap.topKey()) || (expected.at(k).second != heap.topValue()))
                {
                    cout << "                Key = " << heap.topKey();
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << heap.topValue();
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                heap.pop();
            }
        }

        if (passed)
        {
            cout << "        All tests passed!" << endl;
        }

        allTestsPassed &= passed;
    }

    {
        cout << "    Checking KV heap with max type argument.\n";
        passed = true;

        MEK::KVHeap<float, int16_t> heap(MEK::HeapType::min);
        pair<float, int16_t> entry;
        vector<pair<float, int16_t> > expected; 
        float minValue = 10.0f;
        float value;

        cout << "        Add entries to heap while verifying that top of head is the maximun." << endl;
        for (int16_t k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<float>(k));

            if (value < minValue)
            {
                minValue = value;
            }

            entry.first = value;
            entry.second = k;

            heap.push(entry.first, entry.second);
            expected.push_back(entry);

            if (minValue != heap.top().first)
            {
                cout << "                Top of heap = " << heap.topKey() << "), expected = ";
                cout << minValue << " - Failed" << endl;
                passed = false;
            }
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMin);

        cout << "        Pop all values while checking the order/maximum ...\n";
        if (expected.size() != heap.size())
        {
            cout << "        Size of heap (" << heap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != heap.topKey()) || (expected.at(k).second != heap.topValue()))
                {
                    cout << "                Key = " << heap.topKey();
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << heap.topValue();
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                heap.pop();
            }
        }

        if (passed)
        {
            cout << "        All tests passed!" << endl;
        }

        allTestsPassed &= passed;
    }

    return allTestsPassed;
}
