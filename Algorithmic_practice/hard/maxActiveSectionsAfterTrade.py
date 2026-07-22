#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Block {
    char type;
    int start;
    int end;
    int length;
};

class SegmentTree {
private:
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(data, 2 * node, start, mid);
        build(data, 2 * node + 1, mid + 1, end);
        tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return std::max(query(2 * node, start, mid, l, r),
                        query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            build(data, 1, 0, n - 1);
        }
    }

    int query(int l, int r) {
        if (n == 0 || l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    std::vector<int> maxActiveSectionsAfterTrade(const std::string& s, const std::vector<std::vector<int>>& queries) {
        int n = s.length();
        int total_ones_s = 0;
        for (char c : s) {
            if (c == '1') total_ones_s++;
        }

        std::vector<Block> blocks;
        int i = 0;
        while (i < n) {
            int start = i;
            char char_type = s[i];
            while (i < n && s[i] == char_type) {
                i++;
            }
            int end = i - 1;
            blocks.push_back({char_type, start, end, end - start + 1});
        }

        int num_blocks = blocks.size();
        std::vector<int> block_idx(n);
        for (int idx = 0; idx < num_blocks; ++idx) {
            for (int k = blocks[idx].start; k <= blocks[idx].end; ++k) {
                block_idx[k] = idx;
            }
        }

        std::vector<int> internal_gain(num_blocks, 0);
        for (int idx = 1; idx < num_blocks - 1; ++idx) {
            if (blocks[idx].type == '1') {
                int left_0_start = blocks[idx - 1].start;
                int right_0_end = blocks[idx + 1].end;
                internal_gain[idx] = (blocks[idx].start - left_0_start) + (right_0_end - blocks[idx].end);
            }
        }

        SegmentTree tree(internal_gain);
        std::vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            int bl = block_idx[L];
            int br = block_idx[R];
            int max_gain = 0;

            int candidates[4] = {bl, bl + 1, br - 1, br};
            std::sort(candidates, candidates + 4);
            
            for (int j = 0; j < 4; ++j) {
                int idx = candidates[j];
                if (j > 0 && idx == candidates[j - 1]) continue; 
                
                if (idx >= 0 && idx < num_blocks) {
                    const auto& b = blocks[idx];
                    if (b.type == '1' && b.start >= L + 1 && b.end <= R - 1) {
                        int left_0_start = blocks[idx - 1].start;
                        int right_0_end = blocks[idx + 1].end;
                        int g_left = b.start - std::max(L, left_0_start);
                        int g_right = std::min(R, right_0_end) - b.end;
                        if (g_left + g_right > max_gain) {
                            max_gain = g_left + g_right;
                        }
                    }
                }
            }

            if (bl + 2 <= br - 2) {
                int tree_max = tree.query(bl + 2, br - 2);
                if (tree_max > max_gain) {
                    max_gain = tree_max;
                }
            }

            ans.push_back(total_ones_s + max_gain);
        }

        return ans;
    }
};

