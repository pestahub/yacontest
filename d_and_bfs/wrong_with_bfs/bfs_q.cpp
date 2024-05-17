#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
  int row;
  int col;
};

const vector<Cell> neighbour_dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getShortPathToUV(int n, int m, const vector<vector<int>>& matrixs, int u) {
  queue<Cell> q;
  q.push({0, 0});
  vector<vector<int>> dists(n, vector<int>(m, -1));
  dists[0][0] = 0;

  while (q.size() != 0) {
    Cell current = q.front();
    q.pop();

    for (const Cell& direction : neighbour_dirs) {
      Cell neighbour{current.row + direction.row, current.col + direction.col};
      // Могла получиться некорректная ячейка, проверим
      if (neighbour.row < 0 || neighbour.row == (int)matrixs.size() ||
          neighbour.col < 0 || neighbour.col == (int)matrixs[0].size()) {
        continue;
      }
      // проверка что мы еще не зашли в
      if (dists[neighbour.row][neighbour.col] == -1) {
        dists[neighbour.row][neighbour.col] =
            dists[current.row][current.col] + 1;
        if (matrixs[neighbour.row][neighbour.col] == u) {
          return dists[neighbour.row][neighbour.col];
        }
        q.push(neighbour);
      }
    }
  }

  for (auto& row : dists) {
    for (auto& num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
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
  int n, m, u;
  cin >> n >> m >> u;
  vector<vector<int>> matrix = readMatrix(n, m);
  // clang-format off
  /**
  
  2 3 10
  10 8 5
  10 5 4
  
  */
  // clang-format on

  cout << getShortPathToUV(n, m, matrix, u);
}
