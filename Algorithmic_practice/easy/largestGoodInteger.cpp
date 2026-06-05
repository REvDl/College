#include <string>
#include <vector>

using namespace std;

vector<string> good_number = {"999", "888", "777", "666", "555",
                              "444", "333", "222", "111", "000"};
class Solution {
public:
  string largestGoodInteger(string num) {
    for (string good : good_number) {
      if (num.find(good) != string::npos) {
        return good;
      }
    }
    return "";
  }
};
