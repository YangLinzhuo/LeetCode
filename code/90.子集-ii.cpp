/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> m_cur;
    void backtrace(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        // add nums[idx]
        if (idx >= nums.size()) {
            ans.emplace_back(m_cur);
            return;
        }
        m_cur.push_back(nums[idx]);
        backtrace(nums, idx + 1, ans);
        m_cur.pop_back();
        int i = idx + 1;
        while (i < nums.size() && nums[i] == nums[idx]) {   // nums must be sorted
            ++i;
        }
        backtrace(nums, i, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrace(nums, 0, ans);
        return ans;
    }
};
// @lc code=end

