#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers_v1(vector<int> &flowerbed, int n) {
    vector<int> flowers;
    flowers.reserve(flowerbed.size() + 2);
    flowers.push_back(0);
    flowers.insert(flowers.end(), flowerbed.begin(), flowerbed.end());
    flowers.push_back(0);
    for (size_t i = 1; i < flowers.size() - 1; ++i) {
      if (flowers[i] == 0) {
        if (flowers[i - 1] == 0 && flowers[i + 1] == 0) {
          n -= 1;
          flowers[i] = 1;
        }
      }
    }
    return n <= 0;
  }

  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len_arr = flowerbed.size();
    for (int i = 0; i < len_arr; ++i) {
      if (n <= 0)
        return true;
      if (flowerbed[i] == 0) {
        bool left_neigh = (i == 0 || flowerbed[i - 1] == 0);
        bool right_neigh = (i == len_arr - 1 || flowerbed[i + 1] == 0);
        if (left_neigh && right_neigh) {
          n -= 1;
          flowerbed[i] = 1;
        }
      }
    }
    return n <= 0;
  }
};

int main() {
  Solution obj;
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  int n = 1;
  cout << obj.canPlaceFlowers(flowerbed, n) << endl;
}
