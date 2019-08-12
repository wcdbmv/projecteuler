#include <iostream>
#include <vector>
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

int64_t sum_of_primes_below(int n) {
	auto is_prime = eratosthenes(n);

	int64_t result = 2;
	for (int i = 3; i < n; i += 2)
		if (is_prime[i])
			result += i;

	return result;
}

int main() {
	std::cout << sum_of_primes_below(2000000) << std::endl;
}
