#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long pairs(long long n) { return n * (n - 1) / 2; }

long long getNumberOfGoodPairs(int n, vector<int>& numbers) {
  // 1. берем остаток от всех чисел O(n)
  // 2. Создаем хеш таблицу с ключем - остаток, значение - колчисетво таких
  // остатков O(n)
  // 3. Проходим по всем значениям, схладываем результат pairs(значение всех
  // пар)

  for (int i = 0; i < n; ++i) {
    numbers[i] = numbers[i] % 200;
  }

  unordered_map<int, int> map;

  for (int i = 0; i < n; ++i) {
    if (map.find(numbers[i]) == map.end()) {
      map.insert(pair<int, int>(numbers[i], 1));

    } else {
      map[numbers[i]]++;
    }
  }

  // тут была ошибка возвращаемый тип должен быть таким же как у функции (а я
  // поставил инт)
  long long sum = 0;
  for (auto& pair : map) {
    sum += pairs(pair.second);
  }

  return sum;
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
