
int square_root(int number) {
  if (number <= 1) {
    return number;
  }
  int left = 1, right = number;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    long long product = (long long)mid * mid;
    if (product == number) {
      return mid;
    } else if (product < number) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}
