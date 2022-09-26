/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.size() == 0) {
            return ans;
        }
        int left = lower_bound(nums, target);
        int right = upper_bound(nums, target);
        if (left >= 0 && left < nums.size() && nums[left] == target) {
            ans[0] = left;
        }
        --right;
        if (right >= 0 && right < nums.size() && nums[right] == target) {
            ans[1] = right;
        }
        return ans;
    }
};
// @lc code=end

