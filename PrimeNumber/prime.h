#ifndef _PRIME_H__
#define _PRIME_H__

#include <vector>
#include <algorithm>

namespace MEK
{
	template<typename T> class Primes
	{
	private:
		std::vector<T> m_primes;

	public:

		Primes() :
			m_primes()
		{
			m_primes.push_back(2);
			m_primes.push_back(3);
			m_primes.push_back(5);
			m_primes.push_back(7);
		}

		Primes(T max_value) :
			m_primes()
		{
			m_primes.push_back(2);
			m_primes.push_back(3);
			m_primes.push_back(5);
			m_primes.push_back(7);

			addPrimesLessThan(max_value);
		}

		~Primes() { }

		Primes& operator = (const Primes& other)
		{
			if (&other != this)
			{
				this->m_primes = other.getPrimes();
			}

			return *this;
		}

		void setPrimes(std::vector<T> primes) { m_primes = primes; }
		std::vector<T> getPrimes() const { return m_primes; }

		T findNextPrime()
		{
			return findNextPrime(m_primes.back());
		}

		T findNextPrime(T number)
		{
			if (number < m_primes.back())
			{
				// If prime number is already be in cashed list....find prime number in list
				//    use binary search
				size_t k1 = 0;
				size_t k2 = m_primes.size() - 1;
				size_t k_mid;

				while ((k1 + 1) <  k2)
				{
					k_mid = (k1 + k2) / 2;

					if (number < m_primes.at(k_mid))
					{
						k2 = k_mid;
					}
					else
					{
						k1 = k_mid;
					}
				}

				number = m_primes.at(k2);
			}
			else // next prime number is not is cached list
			{
				bool notPrime = true;  // assume each loop it is a prime number

				// There are some special case related to 2, 3 & 5, but these will be handled by number in the initial prime list
				// From this point on it can be assume that the last digit in all primes are 1, 3, 7 or 9.

				// Even numbers can't be prime...except 2
				if ((number % 2) == 0)
				{
					number--;
				}

				// initialize moduous variables and declare variables outside of loops
				uint8_t mod3 = (number % 3);
				uint8_t mod10 = (number % 10);
				uint8_t delta;
				size_t k_sqrt = 1;

				while (notPrime)
				{
					// assume the number is a prime and prove otherwise
					notPrime = false;

					delta = (mod10 == 3) ? 4 : 2; // skip odd numbers ending in 5
					number += delta;
					mod3 = (mod3 + delta) % 3;
					mod10 = (mod10 + delta) % 10;

					// check 3
					if (mod3 == 0)
					{
						notPrime = true;
					}
					else
					{
						// Ensure that list of prime are at least as big as the the square root of the number
						while ((m_primes.at(k_sqrt) * m_primes.at(k_sqrt)) < number)
						{
							k_sqrt++;

							if (m_primes.size() <= k_sqrt)
							{
								addNextPrime();
							}
						}

						for (size_t k = 2; k <= k_sqrt; k++)
						{
							if ((number % m_primes.at(k)) == 0)
							{
								notPrime = true;
								break;
							}
						}
					}
				}
			}

			return number;
		}

		void addNextPrime()
		{
			m_primes.push_back(findNextPrime());
		}

		void addPrimesLessThan(T max_value)
		{
			while (m_primes.back() < max_value)
			{
				addNextPrime();
			}
			m_primes.pop_back();
		}
	};
}

#endif