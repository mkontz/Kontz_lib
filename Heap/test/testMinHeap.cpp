#include <iostream>
#include <algorithm>
#include <cmath>
#include "testMinMaxHeaps.h"
#include "../minHeap.h"

using namespace std;

bool compareKV(MEK::Entry<double, int> t1, MEK::Entry<double, int> t2) { return (t1.key < t2.key); }

bool testMinHeap()
{
    bool allTestsPassed = true;
    bool passed = true;

    cout << "Testing min-heap class.\n";

    std::vector<double> input;
    for (double k = 0; k < 747; k++)
    {
        input.push_back(std::cos(k) + std::sin(3.0 * k) - std::cos(5.0 * k));
    }

    {
        cout << "    Checking min heap with integer data type...\n";
        passed = true;
        MEK::MinHeap<int> minHeapInt;
        int minValue = int(input.at(0));

        cout << "        Build heap while checking minimum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            minHeapInt.add(int(input.at(k)));

            if (int(input.at(k)) < minValue)
            {
                minValue = int(input.at(k));
            }

            if (minHeapInt.getHeap().front() != minValue)
            {
                cout << "            minHeap is not tracking the minimum value - Failed\n";
                passed = false;
            }
        }

        std::vector<int> expected = minHeapInt.getHeap();
        std::sort(expected.begin(), expected.end());

        std::vector<int> output;

        cout << "        Pop all values which checking the order/minimum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(minHeapInt.pop());

            if (output.at(k) != expected.at(k))
            {
                cout << "            minHeap's " << k << "th output does not match expected: ";
                cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failed\n";
                passed = false;
            }
        }

        if (passed)
        {
            cout << "        All checks passed.\n";
        }
        cout << endl;

        allTestsPassed = (allTestsPassed && passed);
    }

    {
        cout << "    Checking min heap with double data type...\n";
        passed = true;
        MEK::MinHeap<double> minHeapIntDouble;
        double minValue = input.at(0);

        cout << "        Build heap while checking minimum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            minHeapIntDouble.add(input.at(k));

            if (input.at(k) < minValue)
            {
                minValue = input.at(k);
            }

            if (minHeapIntDouble.getHeap().front() != minValue)
            {
                cout << "            minHeap is not tracking the minimum value - Failed\n";
                passed = false;
            }
        }

        std::vector<double> expected = minHeapIntDouble.getHeap();
        std::sort(expected.begin(), expected.end());

        std::vector<double> output;

        cout << "        Pop all values which checking the order/minimum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(minHeapIntDouble.pop());

            if (output.at(k) != expected.at(k))
            {
                cout << "            minHeap's " << k << "th output does not match expected: ";
                cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failed\n";
                passed = false;
            }
        }

        if (passed)
        {
            cout << "        All checks passed.\n";
        }
        cout << endl;

        allTestsPassed = (allTestsPassed && passed);
    }

    {
        cout << "    Checking min KV heap with key valeu pair ...\n";
        passed = true;

        MEK::MinKVHeap<double, int> minKVHeap;
        double minValue = input.at(0);

        cout << "        Build heap while checking minimum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            minKVHeap.addPair(input.at(k), k);

            if (input.at(k) < minValue)
            {
                minValue = input.at(k);
            }

            if (minKVHeap.getKey() != minValue)
            {
                cout << "            minHeap is not tracking the minimum value - Failed\n";
                passed = false;
            }
        }

        std::vector<MEK::Entry<double, int> > expected = minKVHeap.getHeap();
        std::sort(expected.begin(), expected.end(), compareKV);

        std::vector<MEK::Entry<double, int> > output;

        cout << "        Pop all values which checking the order/minimum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(minKVHeap.pop());

            if (output.at(k).key != expected.at(k).key)
            {
                cout << "            minHeap's " << k << "th output does not match expected: ";
                cout << "expected: " << expected.at(k).key << ", output: " << output.at(k).key << " - Failed\n";
                passed = false;
            }
        }

        if (passed)
        {
            cout << "        All checks passed.\n";
        }
        cout << endl;

        allTestsPassed = (allTestsPassed && passed);
    }

    return allTestsPassed;
}