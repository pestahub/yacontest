#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestIncreasingPath(int n, int m, const vector<vector<int>>& matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int max_path = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        max_path = max(max_path, dfs(matrix, dp, i, j));
      }
    }

    return max_path;
  }

 private:
  int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& dp, int x,
          int y) {
    if (dp[x][y] != -1) {
      return dp[x][y];
    }

    static const vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int max_length = 1;  // минимальная длина пути - 1 (сама клетка)

    for (const auto& dir : directions) {
      int nx = x + dir.first;
      int ny = y + dir.second;
      if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() &&
          matrix[nx][ny] > matrix[x][y]) {
        max_length = max(max_length, 1 + dfs(matrix, dp, nx, ny));
      }
    }

    dp[x][y] = max_length;
    return dp[x][y];
  }
};

int getLongestIncreasingPath(int n, int m, const vector<vector<int>>& matrixs) {
  Solution solution;
  return solution.longestIncreasingPath(n, m, matrixs);
}

int readInt() {
  int x;
  cin >> x;
  return x;
}

vector<int> readList(int n) {
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  return res;
}

vector<vector<int>> readMatrix(int n, int m) {
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    matrix[i] = readList(m);
  }
  return matrix;
}

int main() {
  /**
2 5
10 8 5 8 10
10 5 4 5 10
  */

  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix = readMatrix(n, m);
  cout << getLongestIncreasingPath(n, m, matrix);
}
