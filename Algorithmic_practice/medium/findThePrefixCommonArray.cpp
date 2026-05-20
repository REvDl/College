#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    unordered_set<int> set_arr;
    vector<int> prefix_common(A.size());
    int current_common = 0;
    for (size_t i = 0; i < A.size(); ++i) {
      if (set_arr.contains(A[i]))
        current_common += 1;
      set_arr.insert(A[i]);
      if (set_arr.contains(B[i]))
        current_common += 1;
      set_arr.insert(B[i]);
      prefix_common[i] = current_common;
    }
    return prefix_common;
  }
};

int main() {
  Solution obj;
  vector<int> A = {1, 2, 3, 4}, B = {3, 1, 2, 4};
  vector<int> result = obj.findThePrefixCommonArray(A, B);
  for (int num : result) {
    cout << num << ", " << endl;
  }
  return 0;
}
