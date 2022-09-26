/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ptr_1 = 0, ptr_2 = 0;
        int n = nums1.size(), m = nums2.size();
        bool is_swap = false;
        if (n > m) { // ensure nums1.size() < nums2.size()
            swap(nums1, nums2);
            swap(n, m);
            is_swap = true;
        }
        vector<vector<int>> ans;
        auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(n, k); ++i) {
            q.push({i, 0});
        }
        while (ans.size() < k && q.size()) {
            auto item = q.top();
            q.pop();
            if (!is_swap) {
                q.push({nums1[item.first], nums2[item.second]});
            } else {
                q.push({nums2[item.second], nums1[item.first]});
            }
            if ((item.second + 1) < m) {
                q.push({item.first, item.second + 1});
            }
        }
        return ans;
    }
};
// @lc code=end

