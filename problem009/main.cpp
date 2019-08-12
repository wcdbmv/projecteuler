#include <iostream>
#include <tuple>
#include <cmath>

// not the best one
std::tuple<int, int, int> pythagorean_triplet_with_sum(int s) {
	for (int a = 3; a <= (s - 3) / 3; ++a) {
		for (int b = a + 1; b <= (s - 1 - a) / 2; ++b) {
			const int c = s - a - b;
			if (a*a + b*b == c*c)
				return {a, b, c};
		}
	}

	return {0, 0, 0};
}

int main() {
	auto [a, b, c] = pythagorean_triplet_with_sum(1000);
	std::cout << a * b * c << std::endl;
}
