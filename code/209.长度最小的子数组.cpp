/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sum(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(sum));
        int n = nums.size();
        int ans = n + 10;
        for (int i = 1; i <= n; ++i) {
            int val = sum[i] - target;
            int left = 0;
            int right = i;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (sum[mid] <= val) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            if (sum[left] <= val) {
                ans = min(ans, i - left);
            }
        }
        if (ans == nums.size() + 10) {
            return 0;
        }
        return ans;
    }
};
// @lc code=end

