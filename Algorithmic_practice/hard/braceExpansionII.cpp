#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
private:
  std::vector<std::string>
  multiply_groups(const std::vector<std::string> &group1,
                  const std::vector<std::string> &group2) {
    std::vector<std::string> res;
    for (const auto &one : group1) {
      for (const auto &two : group2) {
        res.push_back(one + two);
      }
    }
    return res;
  }

  std::vector<std::string>
  delete_duplicates(const std::vector<std::string> &group1,
                    const std::vector<std::string> &group2) {
    std::unordered_set<std::string> unique_elements(group1.begin(),
                                                    group1.end());
    unique_elements.insert(group2.begin(), group2.end());
    return std::vector<std::string>(unique_elements.begin(),
                                    unique_elements.end());
  }

public:
  std::vector<std::string> braceExpansionII(std::string expression) {
    std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>>
        stack;
    std::vector<std::string> curr_group = {""};
    std::vector<std::string> res_group = {};

    for (char val : expression) {
      if (val >= 'a' && val <= 'z') {
        curr_group = multiply_groups(curr_group, {std::string(1, val)});
      } else if (val == '{') {
        stack.push_back({res_group, curr_group});
        res_group.clear();
        curr_group = {""};
      } else if (val == '}') {
        std::vector<std::string> curr_brace =
            delete_duplicates(res_group, curr_group);
        auto [prev_res, prev_group] = stack.back();
        stack.pop_back();
        curr_group = multiply_groups(prev_group, curr_brace);
        res_group = prev_res;
      } else if (val == ',') {
        res_group = delete_duplicates(res_group, curr_group);
        curr_group = {""};
      }
    }

    std::vector<std::string> finaly_brace =
        delete_duplicates(res_group, curr_group);
    std::sort(finaly_brace.begin(), finaly_brace.end());
    return finaly_brace;
  }
};
