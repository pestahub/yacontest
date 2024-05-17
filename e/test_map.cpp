#include <iostream>
#include <unordered_map>

using namespace std;
const unordered_map<string, int> digits{
    {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
    {"XL", 40}, {"L", 50},   {"XС", 90},  {"C", 100}, {"CD", 400},
    {"D", 500}, {"CM", 900}, {"M", 1000},
};

int main() {
  string romanNumber;
  cin >> romanNumber;

  cout << (digits.find(romanNumber) == digits.end()) << endl;
}