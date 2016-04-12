/*Find the largest palindrome which is a multiple of two 3 digit numbers.*/

#include <iostream>
#include <string>

using namespace std;

int main(int argn, char* argv[]) {
	
	size_t large_1(0), large_2(0);
	size_t pal_max = 0;

	for (size_t i = 100; i < 1000; i++) {
		for (size_t j = 999; j >= i; j--) {
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

	cout << large_1 << " x " << large_2 << " = " << large_1*large_2 << endl;

	return 0;
}