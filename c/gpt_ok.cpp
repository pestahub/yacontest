#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long getNumberOfGoodPairs(int n, vector<int>& numbers) {
  // Create an array to count occurrences of each remainder
  vector<long long> counts(200, 0);

  // Count each element's remainder when divided by 200
  for (int i = 0; i < n; i++) {
    int remainder = numbers[i] % 200;
    counts[remainder]++;
  }

  // Calculate the number of valid pairs
  long long result = 0;
  for (int i = 0; i < 200; i++) {
    if (counts[i] > 1) {
      // If more than one element has the same remainder, calculate combinations
      result += (counts[i] * (counts[i] - 1)) / 2;
    }
  }

  return result;
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

int main() {
  int n = readInt();
  vector<int> numbers = readList(n);

  cout << getNumberOfGoodPairs(n, numbers);
}