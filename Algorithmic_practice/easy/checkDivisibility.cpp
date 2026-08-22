class Solution {
public:
  bool checkDivisibility(int n) {
    int sum_n = 0;
    int prod_n = 1;
    int num = n;
    while (num > 0) {
      int last_num = num % 10;
      sum_n += last_num;
      prod_n *= last_num;
      num /= 10;
    }
    return n % (sum_n + prod_n) == 0;
  }
};
