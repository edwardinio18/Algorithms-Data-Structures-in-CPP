#include <iostream>

// ! RECURSION !

// we need to store the calls on the stack
int factorial(int n) {
	// base case
	if (n == 1) return 1;

	// calculate n factorial recursively
	return n * factorial(n - 1);
}

// no need to store calls on stack because we are using an accumulator to store our values
int factorialAccumulator(int n, int accumulator) {

	// base case
	if (n == 1) return accumulator;

	// calculate n factorial recursively with the use of an accumulator
	return factorialAccumulator(n - 1, n * accumulator);
}

// calculating the nth fibonacci number using head recursion ! NOT the best solution !
int fibonacciHead(int n) {

	// base cases
	if (n == 0) return 0;
	if (n == 1) return 1;

	// calculate the nth fibonacci number recursively using head recursion
	return fibonacciHead(n - 1) + fibonacciHead(n - 2);
}

// calculating the nth fibonacci number using tail recursion ! a BETTER solution !
int fibonacciTail(int n, int a, int b) {

	// base cases
	if (n == 0) return a;
	if (n == 1) return b;

	// calculate the nth fibonacci number recursively using tail recursion
	return fibonacciTail(n - 1, b, a + b);
}

// solving the Tower of Hanoi problem recursively
void hanoi(int n, char fromRod, char middleRod, char toRod) {

	// base case
	if (n == 1) {
		std::cout << "Plate 1 from " << fromRod << " to " << toRod << std::endl;
		return;
	}

	// calculate hanoi recursively moving disks from the first rod to the middle rod with the help of the last rod
	hanoi(n - 1, fromRod, toRod, middleRod);

	std::cout << "Plate " << n << " from " << fromRod << " to " << toRod << std::endl;

	// calculate hanoi recursively moving disks from the middle rod to the last rod with the help of the first rod
	hanoi(n - 1, middleRod, fromRod, toRod);
}

// ! SEARCHING ALGORITHMS !

// linear search
// unsorted array - O(n)
void search(int array[], int n, int a) {
	for (int i = 0; i < n; ++i) {
		// element found
		if (array[i] == a) {
			std::cout << "Item found at index " << i << std::endl;
		}
	}
}

// binary search
// sorted array - O(log n)
int binarySearch(int array[], int low, int high, int a) {

	// base case
	if (low > high) return -1;

	// picking the middle item
	int mid = low + (high - low) / 2;

	// if the element at index mid is the number we are looking for, we are done
	if (array[mid] == a) return mid;

	// check left subarray recursively
	if (a < array[mid]) {
		return binarySearch(array, low, mid - 1, a);
	}

	// check right subarray recursively
	return binarySearch(array, mid + 1, high, a);
}

// ! BACKTRACKING !

#include "NQueensProblem.h"

NQueensProblem::NQueensProblem(int _numOfQueens) : numOfQueens(_numOfQueens) {
	chessBoard.resize(numOfQueens);
	for (auto &chessRow : chessBoard) {
		chessRow.resize(numOfQueens);
	}
}

void NQueensProblem::solve() {
	if (setQueens(0)) {
		printQueens();
	} else {
		std::cout << "There is no feasible solution!" << std::endl;
	}
}

bool NQueensProblem::setQueens(int colIdx) {

	// base case
	if (colIdx == numOfQueens) return true;

	// try all columns
	for (int i = 0; i < numOfQueens; ++i) {
		// check if given location on board is valid
		if (isValidPlace(i, colIdx)) {
			// place a queen on valid place
			chessBoard[i][colIdx] = 1;

			// check the next queen (next column) - 1 queen on each column !ONLY!
			// if we manage to place a queen on the next column too -> return true
			if (setQueens(colIdx + 1)) return true;

			// we have to backtrack and modify previous solutions
			chessBoard[i][colIdx] = 0;
		}
	}

	// we have checked all rows and columns and no feasible solution has been found to solve the problem for the given number of queens
	return false;
}

bool NQueensProblem::isValidPlace(int rowIdx, int colIdx) const {
	// only 1 queen is allowed on every row
	for (int i = 0; i < colIdx; ++i) {
		if (chessBoard[rowIdx][i] == 1) return false;
	}

	// queen found on primary diagonal
	for (int i = rowIdx, j = colIdx; i >= 0 && j >= 0; --i, --j) {
		if (chessBoard[i][j] == 1) {
			return false;
		}
	}

	// queen found on secondary diagonal
	for (int i = rowIdx, j = colIdx; i < numOfQueens && j >= 0; ++i, --j) {
		if (chessBoard[i][j] == 1) {
			return false;
		}
	}

	// valid place
	return true;
}

void NQueensProblem::printQueens() const {
	for (int i = 0; i < chessBoard.size(); ++i) {
		for (int j = 0; j < chessBoard.size(); ++j) {
			if (chessBoard[i][j] == 1) std::cout << " * ";
			else std::cout << " - ";
		}
		std::cout << std::endl;
	}
}

#include "GraphColoring.h"

GraphColoring::GraphColoring(const vector<vector<int>> &graph, int _numOfColors) : matrix(graph), numOfColors(_numOfColors) {
	colors.resize(matrix.size());
}

void GraphColoring::operator()() {
	if (solve(0)) {
		printColors();
	} else {
		std::cout << "No feasible solution!";
	}
}

bool GraphColoring::solve(int nodeIdx) {

	// base case
	if (nodeIdx == matrix.size()) return true;

	// try all colors
	for (int i = 1; i <= numOfColors; ++i) {
		// check if the given color is valid
		if (isColorValid(nodeIdx, i)) {
			// color is valid; assign and proceed with the next vertex
			colors[nodeIdx] = i;

			// check next vertex recursively
			if (solve(nodeIdx + 1)) return true;
		}
	}

	// we have checked all colors and no feasible solution has been found to solve the problem for the given number of colors
	return false;
}

bool GraphColoring::isColorValid(int nodeIdx, int colorIdx) {
	for (int i = 0; i < matrix.size(); ++i) {
		// check adjacent nodes and their colors
		if (matrix[nodeIdx][i] == 1 && colorIdx == colors[i]) return false;
	}

	// valid color
	return true;
}

void GraphColoring::printColors() {
	for (int i = 0; i < matrix.size(); ++i) {
		std::cout << "Node " << (i + 1) << " has color index " << colors[i] << std::endl;
	}
}

#include "KnightTour.h"
#include <iomanip>

const std::array<int, 8> KnightTour::xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
const std::array<int, 8> KnightTour::yMoves = {1, 2, 2, 1, -1, -2, -2, -1};

KnightTour::KnightTour() {
	matrix.resize(BOARD_SIZE);

	for (auto &subMatrix : matrix) {
		subMatrix.resize(BOARD_SIZE);
	}

	initializeBoard();
}

void KnightTour::solveKnightTourProblem() {
	// the knight starts from the top left corner of the board
	matrix[0][0] = 0;

	if (!solveProblem(1, 0, 0)) {
		std::cout << "No feasible solution!";
		return;
	}

	showSolution();
}

bool KnightTour::solveProblem(int stepCount, int x, int y) {
	// base case
	if (stepCount == BOARD_SIZE * BOARD_SIZE) return true;
	
	// try all moves a knight can make
	for (int i = 0; i < xMoves.size(); ++i) {
		// possible x and y moves
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];

		// check if it is a valid move for the knight
		if (isValidMove(nextX, nextY)) {
			// valid move
			matrix[nextX][nextY] = stepCount;

			// try next steps recursively
			if (solveProblem(stepCount + 1, nextX, nextY)) return true;

			// we have to backtrack and modify previous solutions
			matrix[nextX][nextY] = INT_MIN;
		}
	}

	// no feasible solution
	return false;
}

bool KnightTour::isValidMove(int x, int y) {
	// knight is out of bounds horizontally
	if (x < 0 || x >= BOARD_SIZE) return false;

	// knight is out of bounds vertically
	if (y < 0 || y >= BOARD_SIZE) return false;

	// cell already visited
	if (matrix[x][y] != INT_MIN) return false;

	// valid move
	return true;
}

void KnightTour::showSolution() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		std::cout << std::left;
		for (int j = 0; j < BOARD_SIZE; ++j) {
			std::cout << std::setw(2) << matrix[i][j] << std::setw(2) << " ";
		}
		std::cout << std::endl;
	}
}

void KnightTour::initializeBoard() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			matrix[i][j] = INT_MIN;
		}
	}
}

// ! DYNAMIC PROGRAMMING !

#include "FibonacciProblem.h"

FibonacciAlgorithm::FibonacciAlgorithm() {
	memo.resize(100);
	memo[0] = 0;
	memo[1] = 1;
}

int FibonacciAlgorithm::fibonacciMemoize(int n) {

	// base cases
	if (n == 0) return 0;
	if (n == 1) return 1;

	// check if sub problem has already been calculated
	if (memo[n] == 0) memo[n] = fibonacciMemoize(n - 1) + fibonacciMemoize(n - 2);

	return memo[n];
}

#include "Knapsack.h"
#include <algorithm>

Knapsack::Knapsack(int _numOfItems, int _capacityOfKnapsack, const vector<int> &_weights, const vector<int> &_values) : numOfItems(_numOfItems), capacityOfKnapsack(_capacityOfKnapsack), weights(_weights), values(_values) {
	knapsackTable.resize(numOfItems + 1);
	for (auto &item : knapsackTable) {
		item.resize(capacityOfKnapsack + 1);
	}
}

void Knapsack::operator()() {

	// we consider all items one by one
	for (int i = 1; i < numOfItems + 1; ++i) {
		for (int j = 1; j < capacityOfKnapsack + 1; ++j) {
			// max value without taking item
			int notTakingItem = knapsackTable[i - 1][j];

			int takingItem = 0;

			// max value if we take the item
			if (weights[i] <= j) {
				takingItem = values[i] + knapsackTable[i - 1][j - weights[i]];
			}

			// maximize profit
			knapsackTable[i][j] = std::max(notTakingItem, takingItem);
		}
	}

	// max profit is last cell of table
	profit = knapsackTable[numOfItems][capacityOfKnapsack];
}

void Knapsack::printResults() {
	std::cout << "Total profit: " << profit << std::endl;

	// print items taken to maximize profit starting with the last cell of table
	for (int i = numOfItems, j = capacityOfKnapsack; i > 0; --i) {
		if (knapsackTable[i][j] != 0 && knapsackTable[i][j] != knapsackTable[i - 1][j]) {
			std::cout << "We take item: #" << i << std::endl;
			j -= weights[i];
		}
	}
}