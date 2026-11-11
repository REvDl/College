#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                        int need2) {
    vector<pair<long long, long long>> items = {{need1, cost1}, {need2, cost2}};
    sort(items.begin(), items.end());

    long long min_need = items[0].first;
    long long max_need = items[1].first;
    long long max_cost = items[1].second;

    long long ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
    long long ans2 = 1LL * costBoth * max_need;
    long long ans3 =
        (1LL * costBoth * min_need) + ((max_need - min_need) * max_cost);

    return min({ans1, ans2, ans3});
  }
};
