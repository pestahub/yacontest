
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long getEnergyForUnion(vector<int>& stones) {
  priority_queue<long long, vector<long long>, greater<long long>> minHeap(
      stones.begin(), stones.end());

  long long sum = 0;

  while (minHeap.size() > 1) {
    long long a = minHeap.top();
    minHeap.pop();

    long long b = minHeap.top();
    minHeap.pop();

    long long s = a + b;
    sum += s;

    minHeap.push(s);
  }
  // your code goes here
  return sum;
}

vector<int> readList(int n) {
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> stones = readList(n);

  cout << getEnergyForUnion(stones);
}