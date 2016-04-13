#include "Euler.h"

using namespace std;

size_t euler::sumMultiples(const std::vector<size_t> factors, const size_t max_lim) {
	size_t sum = 0;

	for (size_t i = 0; i < max_lim; ++i) {
		for (size_t j = 0; j < factors.size(); j++) {
			if (i % factors.at(j) == 0) {
				sum += i;
				break;
			}
		}
	}

	return sum;
}

size_t euler::sumFibonacci(const size_t max_lim) {
	size_t sum = 2;
	size_t fib_pair[2];

	fib_pair[0] = 1;
	fib_pair[1] = 2;

	size_t i = 0;
	while (sum <= max_lim) {
		fib_pair[i] += fib_pair[(i + 1) % 2];

		if (fib_pair[i] % 2 == 0) {
			sum += fib_pair[i];
		}


		i = (i + 1) % 2;
	}

	return sum;
}

std::map<long long, long long> euler::primeFactorisation(const long long val) {
	map<long long, long long> prime_factors;

	long long factor = val;
	long long prime_test = 2;

	/*
	All numbers can be represented as the product of their prime factors.
	To decompose the number val_init into its prime factors we divide by
	each prime smaller than val_init starting with 2.

	We check to see if val is divisible by prime_test:
	- If it is we divide by prime_test and add it to the list of prime
	factors.
	- If it is not we add 1 to prime_test and repeat this step.

	If prime_test is not a prime it will fail the modulo test and will
	quickly be skipped. We could speed up the process by testing a list of
	known primes before using the decomposition method outlined above.
	*/

	long long check_multiplier = 1;

	while (prime_test <= factor) {
		if (factor % prime_test == 0) {
			//Check to see if prime is in map already.
			if (prime_factors.find(prime_test) == prime_factors.end()) {
				//Add prime to map.
				prime_factors[prime_test] = 1;
			}
			else {
				//Increment the prime test.
				prime_factors[prime_test]++;
			}

			//divide the remaining factor by the test prime.
			factor /= prime_test;
		}
		else {
			prime_test++;
		}
	}

	return prime_factors;
}

long long euler::primeFactorExpansion(const std::map<long long, long long> primeFactors)
{
	long long multiple = 1;
	for (std::map<long long, long long>::const_iterator it = primeFactors.begin(); it != primeFactors.end(); ++it) {
		multiple *= std::pow(it->first, it->second);
	}
	return multiple;
}

std::pair<size_t, size_t> euler::largestPalindromicNumber(const size_t factorMagnitude) {
	size_t large_1(0), large_2(0);
	size_t pal_max = 0;

	for (size_t i = pow(10, factorMagnitude); i < pow(10, factorMagnitude + 1); i++) {
		for (size_t j = pow(10, (factorMagnitude + 1))-1; j >= i; j--) {
			size_t pal_pot = i * j;

			string str = to_string(pal_pot);

			string str_rev = str;
			reverse(str_rev.begin(), str_rev.end());
			if (str == str_rev) {
				if (pal_pot > pal_max) {
					large_1 = i;
					large_2 = j;
					pal_max = pal_pot;
				}
			}
		}
	}

	return pair<size_t,size_t>(large_1, large_2);
}

size_t euler::smallestCommonMultiple(const std::vector<size_t> factors) {

	std::map<long long, long long> scmf;

	for (auto it = factors.begin(); it != factors.end(); ++it) {
		auto prime_factors = euler::primeFactorisation(*it);

		for (auto pfit = prime_factors.begin(); pfit != prime_factors.end(); ++pfit) {
			if (scmf.find(pfit->first) == scmf.end()) {
				scmf[pfit->first] = pfit->second;
			}
			else {
				if (scmf[pfit->first] < pfit->second) {
					scmf[pfit->first] = pfit->second;
				}
			}
		}
	}

	long long scm = euler::primeFactorExpansion(scmf);

	return scm;
}
