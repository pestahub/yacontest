#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
 public:
  int convertToArabic(const string& romanNumber) {
    unordered_map<char, int> romanToInt = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int n = romanNumber.size();
    int result = 0;
    
    for (int i = 0; i < n; ++i) {
      if (romanToInt.find(romanNumber[i]) == romanToInt.end()) {
        return -1;  // Некорректная цифра
      }
      
      if (i < n - 1 && romanToInt[romanNumber[i]] < romanToInt[romanNumber[i + 1]]) {
        result -= romanToInt[romanNumber[i]];  // Правило вычитания
      } else {
        result += romanToInt[romanNumber[i]];
      }
    }
    
    // Дополнительная проверка корректности римского числа
    if (!isValidRoman(romanNumber)) {
      return -1;
    }
    
    return result;
  }
  
 private:
  bool isValidRoman(const string& romanNumber) {
    unordered_map<char, int> maxRepetitions = {
        {'I', 3}, {'X', 3}, {'C', 3}, {'M', 3}, {'V', 1}, {'L', 1}, {'D', 1}};
    
    unordered_map<char, int> count;
    
    for (char c : romanNumber) {
      count[c]++;
      if (count[c] > maxRepetitions[c]) {
        return false;  // Нарушение максимального числа повторений
      }
    }
    
    for (int i = 0; i < romanNumber.size() - 1; ++i) {
      if (romanToInt(romanNumber[i]) < romanToInt(romanNumber[i + 1])) {
        // Проверка на допустимые префиксные комбинации
        if ((romanNumber[i] == 'I' && (romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X')) ||
            (romanNumber[i] == 'X' && (romanNumber[i + 1] == 'L' || romanNumber[i + 1] == 'C')) ||
            (romanNumber[i] == 'C' && (romanNumber[i + 1] == 'D' || romanNumber[i + 1] == 'M'))) {
          continue;
        } else {
          return false;  // Некорректная последовательность
        }
      }
    }
    
    return true;
  }

  int romanToInt(char c) {
    unordered_map<char, int> romanToIntMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    return romanToIntMap[c];
  }
};

int main() {
  string romanNumber;
  cin >> romanNumber;
  Solution s;
  cout << s.convertToArabic(romanNumber) << endl;
  return 0;
}
