#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
  long long MOD = 1e9 + 7;

  vector<vector<long long>>
  multiply_matrices(const vector<vector<long long>> &A,
                    const vector<vector<long long>> &B) {

    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < n; ++k) {
        long long val = A[i][k];
        if (!val)
          continue;
        for (int j = 0; j < n; ++j) {
          C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
        }
      }
    }
    return C;
  }

  vector<vector<long long>> matrix_pow(vector<vector<long long>> M, int p) {
    int size = M.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
      result[i][i] = 1;
    }

    vector<vector<long long>> bs = M;
    while (p > 0) {
      if (p % 2 == 1) {
        result = multiply_matrices(result, bs);
      }
      bs = multiply_matrices(bs, bs);
      p /= 2;
    }
    return result;
  }

  vector<long long>
  multiply_vector_matrix(const vector<long long> &array,
                         const vector<vector<long long>> &matrix) {

    int n = array.size();
    vector<long long> result(n, 0);
    for (int i = 0; i < n; ++i) {
      long long current_sum = 0;
      for (int j = 0; j < n; ++j) {
        current_sum = (current_sum + array[j] * matrix[j][i]) % MOD;
      }
      result[i] = current_sum;
    }
    return result;
  }

public:
  int zigZagArrays(int n, int l, int r) {
    int K = r - l + 1;
    vector<vector<long long>> M(K * 2, vector<long long>(K * 2, 0));

    for (int x = 0; x < K; ++x) {
      for (int y = x + 1; y < K; ++y) {
        M[K + y][x] = 1;
      }
      for (int y = 0; y < x; ++y) {
        M[y][K + x] = 1;
      }
    }

    vector<vector<long long>> matrix = matrix_pow(M, n - 1);
    vector<long long> V1(2 * K, 1);
    vector<long long> Vn = multiply_vector_matrix(V1, matrix);

    long long total_sum = 0;
    for (long long val : Vn) {
      total_sum = (total_sum + val) % MOD;
    }

    return total_sum;
  }
};
