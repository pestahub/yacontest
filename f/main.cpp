#include <iostream>
#include <stack>

using namespace std;

bool isPair(const char& a, const char& b) {
  int dist = 'A' - 'a';
  return ((a + dist) == b) || ((a - dist) == b);
}

string convertToGoodString(const string& probablyBadString) {
  string stk;

  for (char ch : probablyBadString) {
    if (!stk.empty() && isPair(stk.back(), ch)) {
      stk.pop_back();

    } else {
      stk.push_back(ch);
    }
  }

  return stk;
}

int main() {
  string probablyBadString;
  cin >> probablyBadString;
  cout << convertToGoodString(probablyBadString);
}