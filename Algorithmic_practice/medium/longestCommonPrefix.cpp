#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> prefix_set;
    for (int number : arr2) {
      while (number > 0) {
        prefix_set.insert(number);
        number /= 10;
      }
    }
    int current_common = 0;
    for (int number : arr1) {
      while (number > 0) {
        if (prefix_set.contains(number)) {
          int len = to_string(number).length();
          current_common = max(current_common, len);
        }
        number /= 10;
      }
    }
    return current_common;
  }
};

int main() {
  Solution obj;
  vector<int> arr1 = {13, 27, 45}, arr2 = {21, 27, 48};
  cout << obj.longestCommonPrefix(arr1, arr2) << endl;
}
