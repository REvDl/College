#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

using namespace std;

/*
2.	Заповнити масив різними дійсними числами, які випадково вибираються
із вказаного проміжку. Вивести на екран елементи масиву у два стовпчики:
в перший - елементи з непарними номерами, у другий - елементи з парними
номерами.
*/

void array_by_span(double x, double y, int arr_size) {
  if (x > y)
    swap(x, y);
  if (arr_size <= 0) {
    cout << "Error: array size must be greater than 0!\n";
    return;
  }
  vector<double> arr(arr_size);
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<double> distr(x, y);
  generate(arr.begin(), arr.end(), [&]() { return distr(gen); });
  for (int i = 0; i < arr_size; i += 2) {
    cout << arr[i] << " N" << i << "\t\t";
    if ((i + 1) < arr_size)
      cout << arr[i + 1] << " N" << i + 1;
    cout << "\n";
  }
}

/*
9.	Масиви А(N), В(М) містять цифри N-значного і
M-значного чисел відповідно (1 <=N, М <= 100).
Заповнити масив С(Nх M) цифрами добутку чисел масивів А і В.
*/

void arrays_product(vector<int> &A, vector<int> &B) {
  int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());
  if (N <= 0) {
    cout << "Error: N size must be greater than 0!";
    return;
  }
  if (M > 100) {
    cout << "Error: M size must be less than 100!";
    return;
  }
  vector<vector<int>> C(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      C[i][j] = A[i] * B[j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << C[i][j] << " (By: " << A[i] << ", " << B[j] << ")" << endl;
    }
  }
}

/*
12.	Заповнити масив різними числами Армстронга.
Числом Армстронга називають натуральне n-цифрове число,
сума цифр якого, піднесених до n-го степеня, рівна цьому числу.
Наприклад, 153=13 + 53 + З3.
*/

/*
def is_armstrong_number(number):
        s = str(number)
        num_digits = len(s)
        sum_of_powers = 0
        for char_digit in s:
                sum_of_powers += int(char_digit) ** num_digits
        return sum_of_powers == number
*/

void generate_armstrong_arr(int arr_size, int limit) {
  if (arr_size >= 1000 || arr_size <= 0) {
    cout << "Error: arr_size must be greater than 0 and less than 1000!";
    return;
  }
  vector<int> arr_arm;
  for (int number = 1; number <= limit; ++number) {
    if (arr_arm.size() == arr_size) {
      break;
    }
    string s = to_string(number);
    int num_digits = s.length();
    int sum_of_powers = 0;
    for (char char_digit : s) {
      int digit = char_digit - '0';
      sum_of_powers += pow(digit, num_digits);
    }
    if (sum_of_powers == number) {
      arr_arm.push_back(number);
    }
  }
  for (int num : arr_arm) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  int a = 10, b = 100;
  cout << "2: " << endl;
  array_by_span(a, b, 10);
  vector<int> A = {4, 5, 2, 8, 1};
  vector<int> B = {9, 3, 6};
  cout << "9: " << endl;
  arrays_product(A, B);
  int arr_size = 15, limit = 100000;
  cout << "12: " << endl;
  generate_armstrong_arr(arr_size, limit);
}
