#include <iostream>
#include <string>
#include <ctime>
#include "../prime.h"

#define private public
#define protected public

using namespace MEK;
// using namespace std;

template<typename T>
bool checkNextPrime(Primes<T> primeTest, T input, T expected, bool passed = true)
{
	T output = primeTest.findNextPrime(input);

	if (expected == output)
	{
		std::cout << "    Next prime after " << input << " is " << output << " - Passed\n";
	}
	else
	{
		passed = false;
		std::cout << "    Next prime after " << input << " is NOT " << output << " - Failed\n";
	}

	return passed;
}

int main()
{
	bool passed = true;
	bool allTestsPassed = true;

	{
		std::cout << "Testing Primes class #1.\n";
		passed = true;

		unsigned max_value = 100;

		std::clock_t begin = clock();
		Primes<unsigned> primeTest(max_value);
		std::clock_t end = clock();

		double primeTime = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		std::vector<unsigned> bruteForce;
		for (unsigned k = 2; k <= max_value; k++)
		{
			bool isPrime = true;
			for (unsigned h = 2; h <k; h++)
			{
				if ((k % h) == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				bruteForce.push_back(k);
			}
		}
		end = clock();

		double bruteTime = double(end - begin) / CLOCKS_PER_SEC;

		std::vector<unsigned> prime_list = primeTest.getPrimes();
		std::cout << "    list of prime = ["  << prime_list.at(0);
		for (size_t k = 1; k < 15; k++) // prime_list.size(); k++)
		{
			std::cout << " " << prime_list.at(k);
		}
		std::cout << "]\n";

		passed = true;
		if (bruteForce.size() != prime_list.size())
		{
			std::cout << "    Length of prime lists don't match." << std::endl;
			passed = false;
		}
		else
		{
			for (size_t k = 0; k < bruteForce.size(); k++)
			{
				if (bruteForce.at(k) != prime_list.at(k))
				{
					std::cout << "    lists don't match: " << bruteForce.at(k) << ", " << bruteForce.at(k) << std::endl;
					passed = false;
				}
			}
		}

		std::cout << "    prime time = " << primeTime << ", brute force time = " << bruteTime << std::endl << std::endl;

		allTestsPassed = (allTestsPassed && passed);
	}

	{
		std::cout << "Testing Primes class #2.\n";

		passed = true;

		int max_value = 1234567;

		std::clock_t begin = clock();
		Primes<uint32_t> primeTest(max_value);
		primeTest.addNextPrime();
		std::clock_t end = clock();

		double primeListTime = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		Primes<uint32_t> primeTest2;
		uint32_t nextPrime = primeTest2.findNextPrime(max_value);
		end = clock();

		double nextPrimeTime = double(end - begin) / CLOCKS_PER_SEC;

		if (primeTest.getPrimes().back() != nextPrime)
		{
			passed = false;
			std::cout << "    last prime in list: " << primeTest.getPrimes().back() << ", next prime method: " << nextPrime << std::endl;
		}
		else
		{
			std::cout << "    next prime method: " << nextPrime << std::endl;
		}

		std::cout << "    prime list  time = " << primeListTime << ", next prime time = " << nextPrimeTime << std::endl << std::endl;

		allTestsPassed = (allTestsPassed && passed);
	}

	{
		std::cout << "Testing Primes class with primes in list.\n";

		passed = true;

		Primes<uint16_t> primeTest(20);

		uint16_t input = 2;
		uint16_t expected = 3;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 3;
		expected = 5;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 4;
		expected = 5;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 5;
		expected = 7;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 6;
		expected = 7;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 7;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 8;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 9;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 10;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 11;
		expected = 13;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 12;
		expected = 13;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 13;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 14;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 15;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 16;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 17;
		expected = 19;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 18;
		expected = 19;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 19;
		expected = 23;
		passed = checkNextPrime(primeTest, input, expected, passed);

		std::cout << std::endl;

		allTestsPassed = (allTestsPassed && passed);
	}

	{
		std::cout << "Testing Primes class without primes in list.\n";

		passed = true;

		Primes<uint16_t> primeTest;

		uint16_t input = 2;
		uint16_t expected = 3;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 3;
		expected = 5;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 4;
		expected = 5;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 5;
		expected = 7;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 6;
		expected = 7;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 7;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 8;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 9;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 10;
		expected = 11;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 11;
		expected = 13;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 12;
		expected = 13;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 13;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 14;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 15;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 16;
		expected = 17;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 17;
		expected = 19;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 18;
		expected = 19;
		passed = checkNextPrime(primeTest, input, expected, passed);

		input = 19;
		expected = 23;
		passed = checkNextPrime(primeTest, input, expected, passed);

		std::cout << std::endl;

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




