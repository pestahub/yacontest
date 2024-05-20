#include <iostream>
#include <vector>

using namespace std;

class NQueens {
 public:
  NQueens(int n)
      : n(n),
        board(n, -1),
        cols(n, false),
        diag1(2 * n - 1, false),
        diag2(2 * n - 1, false) {}

  void solve() {
    backtrack(0);
    cout << solutions.size() << endl;
    for (const auto& solution : solutions) {
      for (int pos : solution) {
        cout << pos + 1 << " ";  // Преобразуем индексы в 1-based
      }
      cout << endl;
    }
  }

 private:
  int n;
  vector<int> board;
  vector<bool> cols, diag1, diag2;
  vector<vector<int>> solutions;

  void backtrack(int row) {
    if (row == n) {
      solutions.push_back(board);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
        board[row] = col;
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
        backtrack(row + 1);
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        board[row] = -1;  // backtrack
      }
    }
  }
};

int main() {
  int n;
  cin >> n;
  NQueens nq(n);
  nq.solve();
  return 0;
}