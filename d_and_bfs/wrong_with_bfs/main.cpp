#include <iostream>
#include <vector>

using namespace std;

struct Cell {
  int row;
  int col;
};

const vector<Cell> neighbour_dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bfs(int n, int m, const vector<vector<int>>& matrixs, int i, int j,
         vector<vector<int>>& real_dists) {
  int edge_nums = ((m - 1) * n) + ((n - 1) * m);
  vector<vector<Cell>> vd(edge_nums + 1, vector<Cell>{});
  vd[0].push_back({i, j});
  vector<vector<int>> dists(n, vector<int>(m, -1));
  dists[i][j] = 0;

  for (int i = 0; i < edge_nums; i++) {
    for (auto& v : vd[i]) {
      Cell current = v;

      for (const Cell& direction : neighbour_dirs) {
        Cell neighbour{current.row + direction.row,
                       current.col + direction.col};
        // Могла получиться некорректная ячейка, проверим
        if (neighbour.row < 0 || neighbour.row == (int)matrixs.size() ||
            neighbour.col < 0 || neighbour.col == (int)matrixs[0].size()) {
          continue;
        }
        // проверка что мы еще не зашли в
        if (dists[neighbour.row][neighbour.col] == -1 &&
            matrixs[neighbour.row][neighbour.col] >
                matrixs[current.row][current.col]) {
          dists[neighbour.row][neighbour.col] =
              dists[current.row][current.col] + 1;

          vd[i + 1].push_back(neighbour);
        }
      }
    }
  }

  int real_size = 0;

  for (auto& v : vd) {
    if (v.size() != 0) {
      real_size++;
    }
  }

  for (int i = 0; i < real_size; i++) {
    for (auto& u : vd[i]) {
      if (real_dists[u.row][u.col] < real_size - i)
        real_dists[u.row][u.col] = real_size - i;
    }
  }

  // for (auto& r : real_dists) {
  //   for (auto& c : r) {
  //     cout << c << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
}

int getLongestIncreasingPath(int n, int m, const vector<vector<int>>& matrixs) {
  vector<vector<int>> real_dists(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bfs(n, m, matrixs, i, j, real_dists);
    }
  }

  int max = 0;
  for (auto& r : real_dists) {
    for (auto& c : r) {
      if (max < c) {
        max = c;
      }
    }
  }

  return max;
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
