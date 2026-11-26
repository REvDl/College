

class Solution {
public:
  bool canAliceWin(int n) {
    int steps = 0;
    for (int i = 10; i > 0; --i) {
      if (n < i) {
        break;
      }
      n -= i;
      steps++;
    }
    return steps % 2 != 0;
  }
};
