#include <vector>

using std::vector;

class NQueensProblem {
	vector<vector<int>> chessBoard;
	int numOfQueens = 0;

public:
	explicit NQueensProblem(int _numOfQueens);
	void solve();

private:
	bool setQueens(int colIdx);
	[[nodiscard]] bool isValidPlace(int rowIdx, int colIdx) const;

	void printQueens() const;
};