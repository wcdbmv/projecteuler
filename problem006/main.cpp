#include <iostream>

constexpr int difference_between_square_of_sum_and_sum_of_squares(int n) {
//	sum of squares = n * (n + 1) * (2*n + 1) / 6;
//	square of sum  = pow(n * (n + 1) / 2, 2);

	return n * (n - 1) * (n + 1) * (3*n + 2) / 12;
//	return n * (n * (n * (3*n + 2) - 3) - 2) / 12;
}

int main() {
	std::cout << difference_between_square_of_sum_and_sum_of_squares(100) << std::endl;
}
