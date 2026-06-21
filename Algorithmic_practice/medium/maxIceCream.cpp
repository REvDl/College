#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    vector<int> count;
    count.resize(*max_element(costs.begin(), costs.end()) + 1, 0);
    int max_ice = 0;
    for (int price : costs) {
      count[price] += 1;
    }
    for (int price = 1; price < count.size(); ++price) {
      if (count[price] > 0) {
        int can_buy = coins / price;
        if (can_buy == 0)
          break;
        int really_buy = min(can_buy, count[price]);
        coins -= really_buy * price;
        max_ice += really_buy;
      }
    }
    return max_ice;
  }
};
