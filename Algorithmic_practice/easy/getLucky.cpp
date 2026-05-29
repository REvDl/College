#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int getLucky(string s, int k) {
    int result = 0;
    int current_sum = 0;
    for (char chr : s) {
      int num = chr - 'a' + 1;
      while (num > 0) {
        current_sum += num % 10;
        num /= 10;
      }
    }
    for (int i = 1; i < k; ++i) {
      int next_sum = 0;
      while (current_sum > 0) {
        next_sum += current_sum % 10;
        current_sum /= 10;
      }
      current_sum = next_sum;
    }
    return current_sum;
  }
};

int main() {
  Solution obj;
  string s = "iiii";
  cout << obj.getLucky(s, 1) << endl;
}
