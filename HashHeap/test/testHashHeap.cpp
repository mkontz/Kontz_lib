#include <iostream>
#include <algorithm>
#include <cmath>
#include "testHashHeap.h"

using namespace std;

bool compareDoubleIntMax(pair<int, double> p1, pair<int, double> p2) { return (p1.second > p2.second); }

bool compareDoubleIntMin(pair<int, double> p1, pair<int, double> p2) { return (p1.second < p2.second); }

bool testHashHeap()
{
    bool allTestsPassed = true;
    bool passed = true;

    cout << "Testing max-heap class.\n";

    {
        cout << "    Checking KV heap with no min/max type argument (Default should be min).\n";
        passed = true;

        MEK::HashHeap<int, double> hashHeap;
        double minValue = 10.0;
        double value = 0.0;

        cout << "        Add entries (-20 -> 20) to heap (using cosine) verify front is the mimimin." << endl;
        for (int k = -20; k <= 20; k++)
        {
            value = std::cos(static_cast<double>(k));

            if (value < minValue)
            {
                minValue = value;
            }

            hashHeap.push(k, value);

            if (minValue != hashHeap.frontValue())
            {
                cout << "                Front of heap = " << hashHeap.frontValue() << "), expected = ";
                cout << minValue << " - Failed" << endl;
                passed = false;
            }
        }

        cout << "        Remove entires with abs(key) > 10" << endl;
        for (int k = 11; k <= 20; k++)
        {
            hashHeap.remove(k);
            hashHeap.remove(-k);
        }

        pair<int, double> entry;
        vector<pair<int, double> > expected;

        cout << "        Add entries (-10 -> 10) to heap (using sine)" << endl;
        for (int k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<double>(k));

            entry.first = k;
            entry.second = value;

            hashHeap.push(k, value);
            expected.push_back(entry);
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMin);

        cout << "        Pop all values while checking the order/minimun ...\n";
        if (expected.size() != hashHeap.size())
        {
            cout << "        Size of hash-heap (" << hashHeap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != hashHeap.frontKey()) || (expected.at(k).second != hashHeap.frontValue()))
                {
                    cout << "                Key = " << hashHeap.frontKey();
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << hashHeap.frontValue();
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                hashHeap.pop();
            }
        }

        if (passed)
        {
            cout << "        All tests passed!" << endl;
        }

        allTestsPassed &= passed;
    }

    {
        cout << "    Checking KV heap with min type argument.\n";
        passed = true;

        MEK::HashHeap<int, double> hashHeap(MEK::HeapType::min);
        double minValue = 10.0;
        double value = 0.0;

        cout << "        Add entries (-20 -> 20) to heap (using cosine) verify front is the mimimin." << endl;
        for (int k = -20; k <= 20; k++)
        {
            value = std::cos(static_cast<double>(k));

            if (value < minValue)
            {
                minValue = value;
            }

            hashHeap.push(k, value);

            if (minValue != hashHeap.frontValue())
            {
                cout << "                Front of heap = " << hashHeap.frontValue() << "), expected = ";
                cout << minValue << " - Failed" << endl;
                passed = false;
            }
        }

        cout << "        Remove entires with abs(key) > 10" << endl;
        for (int k = 11; k <= 20; k++)
        {
            hashHeap.remove(k);
            hashHeap.remove(-k);
        }

        pair<int, double> entry;
        vector<pair<int, double> > expected;

        cout << "        Add entries (-10 -> 10) to heap (using sine)" << endl;
        for (int k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<double>(k));

            entry.first = k;
            entry.second = value;

            hashHeap.push(k, value);
            expected.push_back(entry);
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMin);

        cout << "        Pop all values while checking the order/minimun ...\n";
        if (expected.size() != hashHeap.size())
        {
            cout << "        Size of hash-heap (" << hashHeap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != hashHeap.frontKey()) || (expected.at(k).second != hashHeap.frontValue()))
                {
                    cout << "                Key = " << hashHeap.frontKey();
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << hashHeap.frontValue();
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                hashHeap.pop();
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

        MEK::HashHeap<int, double> hashHeap(MEK::HeapType::max);
        double maxValue = -10.0;
        double value = 0.0;

        cout << "        Add entries (-20 -> 20) to heap (using cosine) verify front is the maximum." << endl;
        for (int k = -20; k <= 20; k++)
        {
            value = std::cos(static_cast<double>(k));

            if (maxValue < value)
            {
                maxValue = value;
            }

            hashHeap.push(k, value);

            if (maxValue != hashHeap.frontValue())
            {
                cout << "                Front of heap = " << hashHeap.frontValue() << "), expected = ";
                cout << maxValue << " - Failed" << endl;
                passed = false;
            }
        }


        cout << "        Remove entires with abs(key) > 10" << endl;
        for (int k = 11; k <= 20; k++)
        {
            hashHeap.remove(k);
            hashHeap.remove(-k);
        }

        pair<int, double> entry;
        vector<pair<int, double> > expected;

        cout << "        Add entries (-10 -> 10) to heap (using sine)" << endl;
        for (int k = -10; k <= 10; k++)
        {
            value = std::sin(static_cast<double>(k));

            entry.first = k;
            entry.second = value;

            hashHeap.push(k, value);
            expected.push_back(entry);
        }

        sort(expected.begin(), expected.end(), compareDoubleIntMax);

        cout << "        Pop all values while checking the order/maximum ...\n";
        if (expected.size() != hashHeap.size())
        {
            cout << "        Size of hash-heap (" << hashHeap.size() << ") does not match size of expected vector (";
            cout << expected.size() << ") - Failed<< endl";
            passed = false;
        }
        else
        {
            for (size_t k = 0; k < expected.size(); k++)
            {
                if ((expected.at(k).first != hashHeap.frontKey()) || (expected.at(k).second != hashHeap.frontValue()))
                {
                    cout << "                Key = " << hashHeap.frontKey();
                    cout << ", expected = " << expected.at(k).first << endl;

                    cout << "                Value = " << hashHeap.frontValue();
                    cout << ", expected = " << expected.at(k).second << endl;
                    passed = false;
                }

                hashHeap.pop();
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
