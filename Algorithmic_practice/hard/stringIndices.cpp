#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode_tle {
  unordered_map<char, TrieNode_tle *> node;
  int best_index;

  TrieNode_tle(int best_index = -1) { this->best_index = best_index; }
};

class Solution_tle {
public:
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    int best_index = 0;
    for (size_t i = 1; i < wordsContainer.size(); ++i) {
      if (wordsContainer[best_index].size() > wordsContainer[i].size())
        best_index = static_cast<int>(i);
    }
    TrieNode_tle node{best_index};
    for (size_t i = 0; i < wordsContainer.size(); ++i) {
      TrieNode_tle *curr = &node;
      string word = wordsContainer[i];
      reverse(word.begin(), word.end());
      for (char letter : word) {
        if (!curr->node.contains(letter)) {
          curr->node[letter] = new TrieNode_tle(i);
        }
        curr = curr->node[letter];
        if (wordsContainer[i].size() <
            wordsContainer[curr->best_index].size()) {
          curr->best_index = i;
        }
      }
    }
    vector<int> ans;
    for (size_t i = 0; i < wordsQuery.size(); ++i) {
      TrieNode_tle *curr = &node;
      string word = wordsQuery[i];
      reverse(word.begin(), word.end());
      for (char letter : word) {
        if (curr->node.contains(letter)) {
          curr = curr->node[letter];
        } else
          break;
      }
      ans.push_back(curr->best_index);
    }
    return ans;
  }
};

struct TrieNode {
  array<TrieNode *, 26> node{};
  int best_index;

  TrieNode(int best_index = -1) { this->best_index = best_index; }
};

class Solution {
public:
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    int best_index = 0;
    for (size_t i = 1; i < wordsContainer.size(); ++i) {
      if (wordsContainer[best_index].size() > wordsContainer[i].size())
        best_index = static_cast<int>(i);
    }
    TrieNode node{best_index};
    for (size_t i = 0; i < wordsContainer.size(); ++i) {
      TrieNode *curr = &node;
      string word = wordsContainer[i];
      reverse(word.begin(), word.end());
      for (char letter : word) {
        int idx = letter - 'a';
        if (curr->node[idx] == nullptr) {
          curr->node[idx] = new TrieNode(i);
        }
        curr = curr->node[idx];
        if (wordsContainer[i].size() <
            wordsContainer[curr->best_index].size()) {
          curr->best_index = i;
        }
      }
    }
    vector<int> ans;
    for (size_t i = 0; i < wordsQuery.size(); ++i) {
      TrieNode *curr = &node;
      string word = wordsQuery[i];
      reverse(word.begin(), word.end());
      for (char letter : word) {
        int idx = letter - 'a';
        if (curr->node[idx] != nullptr) {
          curr = curr->node[idx];
        } else
          break;
      }
      ans.push_back(curr->best_index);
    }
    return ans;
  }
};

int main() {
  Solution_tle obj;
  vector<string> wordsContainer = {"abcd", "bcd", "xbcd"},
                 wordsQuery = {"cd", "bcd", "xyz"};
  vector<int> result = obj.stringIndices(wordsContainer, wordsQuery);
  for (auto i : result) {
    cout << i << " ";
  }
}
