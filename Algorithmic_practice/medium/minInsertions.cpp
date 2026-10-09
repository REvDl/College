#include <string>

class Solution {
public:
  int minInsertions(std::string s) {
    int count = 0;
    int added = 0;
    bool can_closed = false;

    for (char ch : s) {
      if (ch == '(') {
        if (can_closed) {
          if (count > 0) {
            added += 1;
            count -= 1;
          } else {
            added += 2;
          }
          can_closed = false;
        }
        count += 1;
      } else {
        if (count > 0) {
          if (can_closed) {
            count -= 1;
            can_closed = false;
          } else {
            can_closed = true;
          }
        } else if (count <= 0) {
          if (can_closed) {
            added += 1;
            can_closed = false;
          } else {
            can_closed = true;
          }
        }
      }
    }

    if (can_closed) {
      if (count > 0) {
        added += 1;
        count -= 1;
      } else {
        added += 2;
      }
    }

    return added + count * 2;
  }
};
