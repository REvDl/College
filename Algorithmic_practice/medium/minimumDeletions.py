#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_idx = std::distance(nums.begin(), min_it);
        int max_idx = std::distance(nums.begin(), max_it);

        int first_idx = std::min(min_idx, max_idx);
        int second_idx = std::max(min_idx, max_idx);

        int left_and_right = (first_idx + 1) + (n - second_idx);
        int only_left = second_idx + 1;
        int only_right = n - first_idx;

        return std::min({left_and_right, only_left, only_right});
    }
};

