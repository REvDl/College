#include <cctype>
#include <iostream>
#include <set>
#include <string>

class Solution {
public:
  int numberOfSpecialChars(std::string word) {
    std::set<char> upper_char, lower_char;
    int result = 0;
    for (char chr : word) {
      if (std::isupper(chr))
        upper_char.insert(chr);
      else
        lower_char.insert(chr);
    }
    for (char chr : lower_char) {
      if (upper_char.contains(toupper(chr)))
        result += 1;
    }
    return result;
  }
};

int main() {
  Solution obj;
  std::string word = "aaAbcBC";
  int result = obj.numberOfSpecialChars(word);
  std::cout << result << std::endl;
}
