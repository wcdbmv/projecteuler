#include <iostream>

constexpr int sum_of_multiplies(int divider, int range) {
	const int amount = range / divider;
	return divider * amount * (amount + 1) / 2;
}

int main() {
	std::cout << sum_of_multiplies(3, 999) + sum_of_multiplies(5, 999) - sum_of_multiplies(15, 999) << std::endl;
}
