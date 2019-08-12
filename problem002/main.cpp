#include <iostream>

int sum_of_even_fibonacci(int range) {
	int a = 1;
	int b = 1;
	int c = a + b;
	int sum = 0;

	while (c < range) {
		sum += c;
		a = b + c;
		b = c + a;
		c = a + b;
	}

	return sum;
}

int main() {
	std::cout << sum_of_even_fibonacci(4000000) << std::endl;
	return 0;
}
