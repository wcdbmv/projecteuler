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

std::vector<int> primes_below(int n) {
	auto is_prime = eratosthenes(n);

	std::vector<int> primes;
	// http://mathworld.wolfram.com/PrimeNumberTheorem.html
	primes.reserve(n / (std::log(n) - 1.08366));

	primes.push_back(2);
	for (int i = 3; i <= n; i += 2)
		if (is_prime[i])
			primes.push_back(i);

	return primes;
}

int lcm_of_range(int n) {
	std::vector<int> primes = primes_below(n);
	std::vector<int> powers(primes.size(), 1);

	int result = 1;
	bool check = true;

	for (int i = 0; i != primes.size(); ++i) {
		if (check) {
			if (primes[i] * primes[i] <= n)
				powers[i] = std::floor(std::log(n) / std::log(primes[i]));
			else
				check = false;
		}

		result *= std::pow(primes[i], powers[i]);
	}

	return result;
}

int main() {
	std::cout << lcm_of_range(20) << std::endl;
}
