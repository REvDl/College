#include <vector>

class ProductOfNumbers {
private:
  std::vector<int> P;

public:
  ProductOfNumbers() { P = {1}; }

  void add(int num) {
    if (num == 0) {
      P = {1};
    } else {
      if (!P.empty()) {
        P.push_back(P.back() * num);
      } else {
        P.push_back(num);
      }
    }
  }

  int getProduct(int k) {
    if (k >= P.size()) {
      return 0;
    }
    return P.back() / P[P.size() - k - 1];
  }
};
