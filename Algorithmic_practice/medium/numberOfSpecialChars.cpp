#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int numberOfSpecialChars(std::string word) {
    std::unordered_map<char, int> lower_letter, upper_letter;
    for (int i = 0; i < word.length(); ++i) {
      if (std::isupper(word[i])) {
        if (upper_letter.contains(word[i])) {
          continue;
        } else
          upper_letter[word[i]] = i;
      } else
        lower_letter[word[i]] = i;
    }
    int result = 0;
    for (const auto &[chr, idx] : lower_letter) {
      char upper_chr = std::toupper(chr);
      if (upper_letter.contains(upper_chr)) {
        if (lower_letter[chr] < upper_letter[upper_chr]) {
          result += 1;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution obj;
  std::string word = "aaaaaaAAAAAa";
  std::cout << obj.numberOfSpecialChars(word) << std::endl;
}
