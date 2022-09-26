/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>& nums, int end, int cur_val, int cnt, vector<bool>& visited, int k, int target) {
        if (cnt == k) { return true; }
        if (cur_val == target) { return dfs(nums, nums.size() - 1, 0, cnt + 1, visited, k, target); }
        for (int i = end; i >= 0; --i) {
            if (visited[i] || cur_val + nums[i] > target) { continue; }
            visited[i] = true;
            if (dfs(nums, i - 1, cur_val + nums[i], cnt, visited, k, target)) {
                return true;
            }
            visited[i] = false;
            if (cur_val == 0) { return false; }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) { return false; }
        int target = sum / k;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return dfs(nums, nums.size() - 1, 0, 0, visited, k, target);
    }
};
// @lc code=end

