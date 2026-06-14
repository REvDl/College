#include <algorithm>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    std::vector<int> res;
    res.reserve(100000);
    ListNode *curr = head;
    int twin_sum = 0;
    while (curr) {
      res.push_back(curr->val);
      curr = curr->next;
    }
    int n = res.size();
    for (size_t i = 0; i < n; ++i) {
      twin_sum = std::max(res[i] + res[n - 1 - i], twin_sum);
    }
    return twin_sum;
  }
};
