#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Vertex {
  int w;
  int p;
  vector<int> child;

  Vertex(int weight, int parent) : w(weight), p(parent) {}
};

void dfs(int node, const vector<Vertex>& tree, int X, int currentSum, unordered_map<int, int>& prefixSums, int& count) {
  // Обновляем текущую префиксную сумму
  currentSum += tree[node].w;

  // Если префиксная сумма минус X существует, добавляем количество таких префиксных сумм к общему счетчику
  if (prefixSums.find(currentSum - X) != prefixSums.end()) {
    count += prefixSums[currentSum - X];
  }

  // Увеличиваем количество текущих префиксных сумм в хеш-таблице
  prefixSums[currentSum]++;

  // Обходим всех детей текущей вершины
  for (int child : tree[node].child) {
    dfs(child, tree, X, currentSum, prefixSums, count);
  }

  // После обработки детей текущей вершины, уменьшаем количество текущих префиксных сумм
  prefixSums[currentSum]--;
}

int getNumberOfUpgoingPaths(const vector<Vertex>& tree, int X) {
  unordered_map<int, int> prefixSums;
  prefixSums[0] = 1;  // Начальная префиксная сумма равна 0
  int count = 0;

  // Запускаем DFS с корня, который всегда является первой вершиной
  dfs(0, tree, X, 0, prefixSums, count);
  
  return count;
}

vector<Vertex> readTree(int n) {
  vector<Vertex> tree;
  for (int i = 0; i < n; i++) {
    int parent, weight;
    cin >> parent >> weight;
    tree.push_back(Vertex(weight, parent));
  }

  // Заполнение детей после создания всех вершин
  for (int i = 0; i < n; i++) {
    if (tree[i].p != -1) {
      tree[tree[i].p].child.push_back(i);
    }
  }

  return tree;
}

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  vector<Vertex> tree = readTree(n);
  cout << getNumberOfUpgoingPaths(tree, x) << endl;
}