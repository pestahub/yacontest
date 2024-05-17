#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int convertToArabic(const string& romanNumber) {
    try {
      int sum = 0;
      string cur = romanNumber.substr(0, 1);
      string prev = cur;
      bool skip = false;
      for (int i = 0; i < romanNumber.size(); ++i) {
        cur = romanNumber.substr(i, 1);
        checkCorrectLatter(cur);

        checkFifOverload(cur);
        checkDecOverload(prev, cur);

        if (toInt(cur) > toInt(prev) && !skip) {
          return -1;
        }

        if (i + 1 < romanNumber.size() &&
            toInt(cur) < toInt(romanNumber.substr(i + 1, 1))) {
          sum -= toInt(cur);
          skip = true;
        } else {
          sum += toInt(cur);
          skip = false;
        }
        prev = cur;
      }

      return sum;

    } catch (const exception& e) {
      // cout << e.what() << endl;
      return -1;
    }
  }

 private:
  unordered_map<string, int> dec{{"I", 0}, {"X", 0}, {"C", 0}, {"M", 0}};
  unordered_map<string, unordered_set<string>> extendeble{
      {"I", {"V", "X"}}, {"X", {"L", "C"}}, {"C", {"D", "M"}}};

  unordered_map<string, int> fif{{"V", 0}, {"L", 0}, {"D", 0}};

  const unordered_map<string, int> digits{
      {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
      {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
      {"D", 500}, {"CM", 900}, {"M", 1000},
  };

  void checkCorrectLatter(const string& romanDigit) {
    if (digits.find(romanDigit) == digits.end())
      throw runtime_error("Incorrect letter: " + romanDigit);
  }

  void checkFifOverload(const string& curDigit) {
    if (fif.find(curDigit) == fif.end()) return;

    if (fif[curDigit] > 0)
      throw runtime_error("FifOverload, digit: " + curDigit);

    fif[curDigit]++;
  }

  void checkDecOverload(const string& prevDigit, const string& curDigit) {
    resetDecsIfNew(prevDigit, curDigit);
    if (dec.find(curDigit) == dec.end()) return;
    if (dec[curDigit] > 2)
      throw runtime_error("DecOverload, digit: " + curDigit);
    dec[curDigit]++;
  }

  void resetDecsIfNew(const string& prevDigit, const string& curDigit) {
    if (prevDigit == curDigit) return;
    if (dec.find(prevDigit) == dec.end()) return;

    dec[prevDigit] = 0;
  }

  int toInt(const string& romanDigit) {
    // cout << romanDigit << endl;
    if (digits.find(romanDigit) == digits.end())
      throw runtime_error("toInt error: " + romanDigit);

    return digits.at(romanDigit);
  }
};

int main() {
  string romanNumber;
  cin >> romanNumber;
  Solution s;
  cout << s.convertToArabic(romanNumber);
}