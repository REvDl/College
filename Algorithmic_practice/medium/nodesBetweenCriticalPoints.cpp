#include <algorithm>
#include <climits>
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
  std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
      return {-1, -1};
    }

    int first_idx = -1;
    int prev_idx = -1;
    int min_dist = INT_MAX;

    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *next = curr->next;
    int curr_idx = 1;

    while (next) {
      if ((curr->val > prev->val && curr->val > next->val) ||
          (curr->val < prev->val && curr->val < next->val)) {

        if (first_idx == -1) {
          first_idx = curr_idx;
        } else {
          min_dist = std::min(min_dist, curr_idx - prev_idx);
        }
        prev_idx = curr_idx;
      }

      prev = curr;
      curr = next;
      next = next->next;
      curr_idx++;
    }

    if (first_idx == prev_idx) {
      return {-1, -1};
    }

    return {min_dist, prev_idx - first_idx};
  }
};
