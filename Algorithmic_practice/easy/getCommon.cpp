#include <iostream>
#include <vector>
class Solution {
public:
  int getCommon(std::vector<int> nums1, std::vector<int> nums2) {
    int size_one = static_cast<int>(nums1.size()),
        size_two = static_cast<int>(nums2.size());
    int pointer1 = 0, pointer2 = 0;
    while (pointer1 < size_one && pointer2 < size_two) {
      if (nums1[pointer1] > nums2[pointer2])
        pointer2 += 1;
      else if (nums1[pointer1] < nums2[pointer2])
        pointer1 += 1;
      else
        return nums1[pointer1];
    }
    return -1;
  }
};

int main() {
  Solution obj;
  std::vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4};
  std::cout << obj.getCommon(nums1, nums2) << std::endl;
}
