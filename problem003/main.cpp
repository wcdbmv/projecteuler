#include <iostream>
#include <cmath>

void divide(int64_t& number, int64_t& last_factor, int64_t factor) {
	if (number % factor == 0) {
		last_factor = factor;

		do {
			number /= factor;
		} while (number % factor == 0);
	}
}

int64_t biggest_prime_factor(int64_t number) {
	int64_t last_factor = 1;

	divide(number, last_factor, 2);

	for (int64_t factor = 3; number > 1 && factor * factor < number; factor += 2)
		divide(number, last_factor, factor);

	return number == 1 ? last_factor : number;
}

int main() {
	std::cout << biggest_prime_factor(600851475143) << std::endl;
}
