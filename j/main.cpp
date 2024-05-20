#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> getAllPeacefulCombinations(int n_) {
    // 0 - free, 1 - used

    n = n_;
    vector<int> c(n, 0);

    vector<vector<int>> field = vector<vector<int>>{n, c};

    solve(field, 0);

    cout << res << endl;

    return {};
  }

 private:
  void solve(vector<vector<int>> field, int row) {
    if (row == n) {
      vector<int> res_p(n, 0);
      

      // cout << "YES" << endl;

      res++;
      return;
    }
    vector<vector<int>> save_field;
    for (int col = 0; col < n; col++) {
      if (field[row][col] == 0) {
        // printField(field, "pre");
        save_field = field;
        for (int i = 0; i < n; i++) {
          field[i][col] = 1;
          field[row][i] = 1;

          int col_rd = i + col - row;
          if (col_rd < n && col_rd >= 0) field[i][col_rd] = 1;

          int col_ld = -i + col + row;
          if (col_ld < n && col_ld >= 0) field[i][col_ld] = 1;
          field[row][col] = 5;
        }

        // printField(field, "in");
        solve(field, row + 1);

        field = save_field;
        // printField(field, "post");
      }
    }
  }

  void printField(vector<vector<int>> field, string s) {
    cout << "FIELD " << s << endl;
    for (auto& elem : field) {
      for (auto& e : elem) {
        cout << e << " ";
      }
      cout << endl;
    }
  }

  vector<vector<int>> res_v;
  int res = 0;
  int n = 3;
};

void printArray(const vector<int>& combination) {
  for (int elem : combination) {
    cout << elem << " ";
  }
  cout << endl;
}

void outputAnswer(const vector<vector<int>>& possibleCombinations) {
  cout << possibleCombinations.size() << endl;
  for (const vector<int>& combination : possibleCombinations) {
    printArray(combination);
  }
}

int main() {
  int n;
  cin >> n;
  Solution s;
  vector<vector<int>> possibleCombinations = s.getAllPeacefulCombinations(n);
  // outputAnswer(possibleCombinations);
}