#include <vector>

using std::vector;

class FibonacciAlgorithm {
	vector<int> memo;

public:
	FibonacciAlgorithm();

	int fibonacciMemoize(int n);
};