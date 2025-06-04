#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define cer(x) cerr << #x << " = " << x << ' ';
#define cern(x) cerr << #x << " = " << x << '\n';
#define cc cerr << '\n';
const bool MULTIPLE_QUERY = 0;
const ll MAX_N = 200'005;
const ll MOD = 1e9 + 7;
struct SudokuSolver {
    std::vector<std::vector<char>> board;
    char EMPTY_CHAR = '.';
    SudokuSolver(std::vector<std::vector<char>> initialBoard, char empty_char) {
        board = initialBoard;
        EMPTY_CHAR = empty_char;
    }

    bool isValidSudoku() {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(i) || !isValidColumn(i) || !isValidBox(i)) {
                return false;
            }
        }
        return true;
    }

    bool isValidRow(int row) {
        std::vector<bool> used(9, false);
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != EMPTY_CHAR) {
                int num = board[row][col] - '1';
                if (used[num]) {
                    return false;
                }
                used[num] = true;
            }
        }
        return true;
    }

    bool isValidColumn(int col) {
        std::vector<bool> used(9, false);
        for (int row = 0; row < 9; row++) {
            if (board[row][col] != EMPTY_CHAR) {
                int num = board[row][col] - '1';
                if (used[num]) {
                    return false;
                }
                used[num] = true;
            }
        }
        return true;
    }

    bool isValidBox(int box) {
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        std::vector<bool> used(9, false);

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] != EMPTY_CHAR) {
                    int num = board[i][j] - '1';
                    if (used[num]) {
                        return false;
                    }
                    used[num] = true;
                }
            }
        }
        return true;
    }

    bool solveSudoku() {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == EMPTY_CHAR) {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isSafe(row, col, num)) {
                            board[row][col] = num;
                            if (solveSudoku()) {
                                return true;
                            }
                            board[row][col] = EMPTY_CHAR;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(int row, int col, char num) {
        return isSafeInRow(row, num) && isSafeInColumn(col, num) && isSafeInBox(row - row % 3, col - col % 3, num);
    }

    bool isSafeInRow(int row, char num) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == num) {
                return false;
            }
        }
        return true;
    }

    bool isSafeInColumn(int col, char num) {
        for (int row = 0; row < 9; row++) {
            if (board[row][col] == num) {
                return false;
            }
        }
        return true;
    }

    bool isSafeInBox(int boxStartRow, int boxStartCol, char num) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row + boxStartRow][col + boxStartCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    void printBoard() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

void solveSudoku(vector<vector<char>>& board) {
    SudokuSolver sudokuSolver(board, '.');
    sudokuSolver.solveSudoku();
    board = sudokuSolver.board;
}
void solve() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    SudokuSolver sudokuSolver(board, '.');
    sudokuSolver.solveSudoku();
    board = sudokuSolver.board;
    for (auto i: board) {
        for (auto j: i) {
            cout << j << ' ';
        } qq;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (MULTIPLE_QUERY) {
		ll Q;
		cin >> Q;
		while (Q--) {
			solve(); qq;
		}
	} else {
		solve();
	}
}