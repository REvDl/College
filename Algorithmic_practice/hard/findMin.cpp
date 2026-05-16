#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] == nums[right]) {
                right -= 1;
            }
            else right = mid;
            
        }
        return nums[left];
    }
};


int main() {
    cout << "Suck" << endl;
    return 0;
}