/*Find the sum of all even Fibonacci numbers less than or equal to 4 million.*/

#include <iostream>

using namespace std;

int main(int argn, char* argv[]) {
	size_t sum = 2;
	size_t fib_pair[2];
	
	fib_pair[0] = 1;
	fib_pair[1] = 2;

	size_t i = 0;
	while(sum <= 4e6) {
		fib_pair[i] += fib_pair[(i+1)%2];

		if (fib_pair[i] % 2 == 0) {
			sum += fib_pair[i];
		}


		i = (i+1)%2;
	}

	printf("%d\n", sum);
	return 0;
}