class Solution {
public:
  int checkWaviness(int num) {
    int digits[6];
    int waviness = 0;
    int n = 0;
    while (num > 0) {
      digits[n++] = num % 10;
      num /= 10;
    }
    for (size_t i = 1; i < n - 1; ++i) {
      if (digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) {
        waviness++;
      } else if (digits[i] < digits[i - 1] && digits[i] < digits[i + 1]) {
        waviness++;
      }
    }
    return waviness;
  }

  int totalWaviness(int num1, int num2) {
    int total_waviness = 0;
    for (int i = num1; i < num2 + 1; ++i) {
      total_waviness += checkWaviness(i);
    }
    return total_waviness;
  }
};
