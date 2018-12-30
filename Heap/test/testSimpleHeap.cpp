#include <iostream>
#include <algorithm>
#include <cmath>
#include "testSimpleHeap.h"
#include "../minHeap.h"
#include "../maxHeap.h"

using namespace std;

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
		MEK::minHeap<int> minHeapInt;
		int minValue = int(input.at(0));

		for (size_t k = 0; k < input.size(); k++)
		{
			minHeapInt.add(int(input.at(k)));

			if (int(input.at(k)) < minValue)
			{
				minValue = int(input.at(k));
			}

			if (minHeapInt.peep() > minValue)
			{
				cout << "        minHeapd is not tracking the minimum value - Failled\n";
				passed = false;
			}
		}

		std::vector<int> expected = minHeapInt.getHeap();
		std::sort(expected.begin(), expected.end());

		std::vector<int> output;

		for (size_t k = 0; k < input.size(); k++)
		{
			output.push_back(minHeapInt.pop());

			if (output.at(k) != expected.at(k))
			{
				cout << "        minHeapd's " << k << "th output does not match expected: ";
				cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failled\n";
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
		MEK::minHeap<double> minHeapIntDouble;
		double minValue = input.at(0);

		for (size_t k = 0; k < input.size(); k++)
		{
			minHeapIntDouble.add(input.at(k));

			if (input.at(k) < minValue)
			{
				minValue = input.at(k);
			}

			if (minHeapIntDouble.peep() > minValue)
			{
				cout << "        minHeapd is not tracking the minimum value - Failled\n";
				passed = false;
			}
		}

		std::vector<double> expected = minHeapIntDouble.getHeap();
		std::sort(expected.begin(), expected.end());

		std::vector<double> output;

		for (size_t k = 0; k < input.size(); k++)
		{
			output.push_back(minHeapIntDouble.pop());

			if (output.at(k) != expected.at(k))
			{
				cout << "        minHeapd's " << k << "th output does not match expected: ";
				cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failled\n";
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

bool compareInt(int t1, int t2)
{
	return (t1 > t2);
}

bool compareDouble(double t1, double t2)
{
	return (t1 > t2);
}

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
		MEK::maxHeap<int> maxHeapInt;
		int maxValue = int(input.at(0));

		for (size_t k = 0; k < input.size(); k++)
		{
			maxHeapInt.add(int(input.at(k)));

			if (int(input.at(k)) > maxValue)
			{
				maxValue = int(input.at(k));
			}

			if (maxHeapInt.peep() > maxValue)
			{
				cout << "        maxHeapd is not tracking the minimum value - Failled\n";
				passed = false;
			}
		}

		std::vector<int> expected = maxHeapInt.getHeap();
		std::sort(expected.begin(), expected.end(), compareInt);

		std::vector<int> output;

		for (size_t k = 0; k < input.size(); k++)
		{
			output.push_back(maxHeapInt.pop());

			if (output.at(k) != expected.at(k))
			{
				cout << "        maxHeap's " << k << "th output does not match expected: ";
				cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failled\n";
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
		MEK::maxHeap<double> maxHeapIntDouble;
		double maxValue = input.at(0);

		for (size_t k = 0; k < input.size(); k++)
		{
			maxHeapIntDouble.add(input.at(k));

			if (input.at(k) > maxValue)
			{
				maxValue = input.at(k);
			}

			if (maxHeapIntDouble.peep() > maxValue)
			{
				cout << "        maxHeapd is not tracking the minimum value - Failled\n";
				passed = false;
			}
		}

		std::vector<double> expected = maxHeapIntDouble.getHeap();
		std::sort(expected.begin(), expected.end(), compareDouble);

		std::vector<double> output;

		for (size_t k = 0; k < input.size(); k++)
		{
			output.push_back(maxHeapIntDouble.pop());

			if (output.at(k) != expected.at(k))
			{
				cout << "        maxHeap's " << k << "th output does not match expected: ";
				cout << "expected: " << expected.at(k) << ", output: " << output.at(k) << " - Failled\n";
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
