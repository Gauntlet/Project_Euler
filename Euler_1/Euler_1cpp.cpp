/*Find the sum of all multiples of 3 or 5 less than 1000.*/

#include <iostream>

using namespace std;

int main(int argn, char* argv[]) {
	size_t sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("%d\n", sum);
	return 0;
}