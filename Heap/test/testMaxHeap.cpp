#include <iostream>
#include <algorithm>
#include <cmath>
#include "testMinMaxHeaps.h"
#include "../maxHeap.h"

using namespace std;

bool compareInt(int t1, int t2) { return (t1 > t2); }

bool compareDouble(double t1, double t2) { return (t1 > t2); }

bool compareMaxKV(MEK::Entry<double, int> t1, MEK::Entry<double, int> t2) { return (t1.key > t2.key); }

bool testMaxHeap()
{
    bool allTestsPassed = true;
    bool passed = true;

    cout << "Testing max-heap class.\n";

    std::vector<double> input;
    for (double k = 0; k < 666; k++)
    {
        input.push_back(std::cos(k) + std::sin(3.0 * k) - std::cos(5.0 * k));
    }

    {
        cout << "    Checking max heap with integer data type...\n";
        passed = true;
        MEK::MaxHeap<int> maxHeapInt;
        int maxValue = int(input.at(0));

        cout << "        Build heap while checking maximum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            maxHeapInt.add(int(input.at(k)));

            if (int(input.at(k)) > maxValue)
            {
                maxValue = int(input.at(k));
            }

            if (maxHeapInt.getHeap().front() != maxValue)
            {
                cout << "            maxHeap is not tracking the maximum value - Failed\n";
                passed = false;
            }
        }

        std::vector<int> expected = maxHeapInt.getHeap();
        std::sort(expected.begin(), expected.end(), compareInt);

        std::vector<int> output;

        cout << "        Pop all values which checking the order/maximum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(maxHeapInt.pop());

            if (output.at(k) != expected.at(k))
            {
                cout << "            maxHeap's " << k << "th output does not match expected: ";
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
        cout << "    Checking max heap with double data type...\n";
        passed = true;
        MEK::MaxHeap<double> maxHeapDouble;
        double maxValue = input.at(0);

        cout << "        Build heap while checking maximum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            maxHeapDouble.add(input.at(k));

            if (input.at(k) > maxValue)
            {
                maxValue = input.at(k);
            }

            if (maxHeapDouble.getHeap().front() != maxValue)
            {
                cout << "            maxHeap is not tracking the maximum value - Failed\n";
                passed = false;
            }
        }

        std::vector<double> expected = maxHeapDouble.getHeap();
        std::sort(expected.begin(), expected.end(), compareDouble);

        std::vector<double> output;

        cout << "        Pop all values which checking the order/maximum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(maxHeapDouble.pop());

            if (output.at(k) != expected.at(k))
            {
                cout << "            maxHeap's " << k << "th output does not match expected: ";
                cout << " expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failed\n";
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
        cout << "    Checking max KV heap with key valeu pair ...\n";
        passed = true;

        MEK::MaxKVHeap<double, int> maxKVHeap;
        double maxValue = input.at(0);

        cout << "        Build heap while checking maximum value ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            maxKVHeap.addPair(input.at(k), k);

            if (input.at(k) > maxValue)
            {
                maxValue = input.at(k);
            }

            if (maxKVHeap.getKey() != maxValue)
            {
                cout << "            maxHeap is not tracking the maximum value - Failed\n";
                passed = false;
            }
        }

        std::vector<MEK::Entry<double, int> > expected = maxKVHeap.getHeap();
        std::sort(expected.begin(), expected.end(), compareMaxKV);

        std::vector<MEK::Entry<double, int> > output;

        cout << "        Pop all values which checking the order/maximum ...\n";
        for (size_t k = 0; k < input.size(); k++)
        {
            output.push_back(maxKVHeap.pop());

            if (output.at(k).key != expected.at(k).key)
            {
                cout << "            maxHeap's " << k << "th output does not match expected: ";
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
