#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

std::vector<bool> eratosthenes(int n) {
	assert(n >= 2);

	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;

	auto sieve = [&is_prime](int start, int step) {
		for (int i = start; i < is_prime.size(); i += step)
			is_prime[i] = false;
	};

	sieve(4, 2);

	for (int i = 3; i * i <= n; i += 2)
		if (is_prime[i])
			sieve(i * i, 2 * i);

	return is_prime;
}

int nth_prime(int n) {
//	https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
	auto is_prime = eratosthenes(n * (std::log(n) + std::log(std::log(n))));

	int result = 0;
	for (int i = 0, j = 0; i != is_prime.size() && !result; ++i)
		if (is_prime[i])
			if (++j == n)
				result = i;

	return result;
}

int main() {
	std::cout << nth_prime(10001) << std::endl;
}
