#include <vector>

using std::vector;

class GraphColoring {
	vector<vector<int>> matrix;
	int numOfColors;
	vector<int> colors;

public:
	GraphColoring(const vector<vector<int>> &graph, int _numOfColors);

	// solving the problem
	void operator()();

private:

	// assign colors recursively
	bool solve(int nodeIdx);

	// check if it is valid to allot color to vertex
	bool isColorValid(int nodeIdx, int colorIdx);

	void printColors();
};