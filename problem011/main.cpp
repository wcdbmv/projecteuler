#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
T product_horizontal(const Matrix<T>& grid, size_t n, size_t i, size_t j) {
	return std::reduce(&grid[i][j], &grid[i][j + n], T{1}, std::multiplies<T>());
}

template <typename T>
T product_vertical(const Matrix<T>& grid, size_t n, size_t i, size_t j) {
	return std::accumulate(&grid[i], &grid[i + n], T{1}, [=](T acc, auto row) { return acc * row[j]; });
}

template <typename T>
T product_diagonal_down_right(const Matrix<T>& grid, size_t n, size_t i, size_t j) {
	return std::accumulate(&grid[i], &grid[i + n], T{1}, [j, k = 0u](T acc, auto row) mutable { return acc * row[j + k++]; });
}

template <typename T>
T product_diagonal_down_left(const Matrix<T>& grid, size_t n, size_t i, size_t j) {
	return std::accumulate(&grid[i], &grid[i + n], T{1}, [j, k = 0u](T acc, auto row) mutable { return acc * row[j - k++]; });
}

template <typename T>
T greatest_product_of_n_adjacent_numbers(const Matrix<T>& grid, size_t n) {
	assert(n > 0 && !grid.empty());

	const size_t n_rows = grid.size();
	const size_t n_cols = grid[0].size();

	T greatest_product = std::numeric_limits<T>::min();

	auto sweep = [&](size_t ib, size_t ie, size_t jb, size_t je, auto product_func) {
		for (size_t i = ib; i < ie; ++i) {
			for (size_t j = jb; j < je; ++j) {
				greatest_product = std::max(greatest_product, product_func(grid, n, i, j));
			}
		}
	};

	sweep(0, n_rows, 0, n_cols - n + 1, product_horizontal<T>);
	sweep(0, n_rows - n + 1, 0, n_cols, product_vertical<T>);
	sweep(0, n_rows - n + 1, 0, n_cols - n + 1, product_diagonal_down_right<T>);
	sweep(0, n_rows - n + 1, n - 1, n_cols, product_diagonal_down_left<T>);

	return greatest_product;
}

template <typename T>
std::vector<std::vector<T>> read_matrix(const std::string& filename) {
	std::vector<std::vector<T>> matrix;

	std::ifstream input(filename);
	assert(input);

	for (std::string line{}; std::getline(input, line);) {
		std::istringstream line_stream(line);
		matrix.emplace_back(std::vector<T>(std::istream_iterator<T>(line_stream), {}));
	}

	return matrix;
}

int main() {
	const auto grid = read_matrix<int>("grid.txt");
	std::cout << greatest_product_of_n_adjacent_numbers(grid, 4) << '\n';
}
