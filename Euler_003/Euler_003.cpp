/*Find the largest prime factorisation of 600851475143.*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argn, char* argv[]) {
	const long long val_init = 600851475143;
	cout << val_init << endl << endl;

	vector<long long> prime_factors;

	long long val = val_init;
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

	while (prime_test <= val) {
		if(val % prime_test == 0) {
			prime_factors.push_back(prime_test);
			val /= prime_test;

			//check_multiplier *= (long long) prime_test;
			//std::printf("%d\n", prime_factors.back());
		}
		else {
			prime_test++;
		}
	}
	
	cout << "Largest prime factor: " << prime_factors.back() << endl;
	//cout << check_multiplier << " | " << val_init << endl;

	return 0;
}