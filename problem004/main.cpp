#include <iostream>

int reverse(int n) {
	int result = 0;

	for (; n > 0; n /= 10)
		result = 10 * result + n % 10;

	return result;
}

bool palindrome(int n) {
	return n == reverse(n);
}

int largest_palindrome_product_of_two_three_digit_numbers() {
	int result = 0;

	for (int a = 999; a >= 100; --a) {
		int b = 990;
		int db = 11;
		if (a % 11 == 0) {
			b = 999;
			db = 1;
		}

		for (; b >= a; b -= db) {
			const int product = a * b;

			if (product <= result)
				break;

			if (palindrome(product))
				result = product;
		}
	}

	return result;
}

int main() {
	std::cout << largest_palindrome_product_of_two_three_digit_numbers() << std::endl;
}
