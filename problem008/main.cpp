#include <iostream>
#include <fstream>
#include <array>
#include <numeric>
#include <cassert>
#include <cctype>

int main() {
//	this is so bad function don't look at me alright

	constexpr auto filename = "digits.txt";
	constexpr int N_FACTORS = 13;
	constexpr int N_DIGITS = 1000;

	std::ifstream input(filename);
	assert(input);

	auto get_char = [&input]() {
		char chr;

		do {
			input >> chr;
		} while (std::isspace(chr));

		return chr;
	};

	std::array<int64_t, N_FACTORS> buffer{};

	int64_t product = 1;
	for (int i = 0; i != N_FACTORS; ++i)
		product *= buffer[i] = get_char() - '0';

	int64_t max_product = product;
	for (int i = N_FACTORS, last_zero = N_FACTORS + 1; i != N_DIGITS; ++i, ++last_zero) {
		char chr = get_char();

		const int j = i % N_FACTORS;
		const int64_t dropped = buffer[j];
		buffer[j] = chr - '0';

		if (!buffer[j])
			last_zero = 0;

		if (last_zero > N_FACTORS)
			product = product / dropped * buffer[j];
		else if (last_zero == N_FACTORS)
			product = std::accumulate(buffer.begin(), buffer.end(), 1ll, std::multiplies<>());

		if (last_zero >= N_FACTORS)
			max_product = std::max(product, max_product);
	}

	std::cout << max_product << std::endl;
}
