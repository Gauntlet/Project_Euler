#ifndef EULER_001_H
#define EULER_001_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

namespace euler {
	size_t sumMultiples(const std::vector<size_t> factors, const size_t max_lim);
	
	size_t sumFibonacci(const size_t max_lim);

	std::map<long long, long long> primeFactorisation(const long long val);
	long long primeFactorExpansion(const std::map<long long, long long> primeFactors);

	std::pair<size_t, size_t> largestPalindromicNumber(const size_t factorMagnitude);
	
	size_t smallestCommonMultiple(const std::vector<size_t> factors);
}

#endif