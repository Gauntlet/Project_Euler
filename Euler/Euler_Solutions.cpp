#include "Euler_Solutions.h"
#include "Euler.h"

#include <vector>
#include <iostream>

using namespace std;

void euler001() {
	std::vector<size_t> factors;
	factors.push_back(3);
	factors.push_back(5);

	const size_t sum = euler::sumMultiples(factors, 1000);
	cout << sum << endl;
}

void euler002() {
	const size_t sum = euler::sumFibonacci(4e6);
	cout << sum << endl;
}

void euler003() {
	map<long long, long long> prime_factors = euler::primeFactorisation(600851475143);

	long long largest_factor = prime_factors.rbegin()->first;
	cout << largest_factor << endl;
}

void euler004() {
	std::pair<size_t, size_t> factors = euler::largestPalindromicNumber(2);
	cout << factors.first * factors.second << endl;
}

void euler005() {
	std::vector<size_t> factors;

	for (size_t i = 1; i <= 20; ++i) {
		factors.push_back(i);
	}
	
	long long scm = euler::smallestCommonMultiple(factors);

	cout << scm << endl;
}