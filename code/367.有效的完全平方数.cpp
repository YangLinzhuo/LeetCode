/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0;
        long long right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long val = mid * mid;
            if (num == val) {
                return true;
            } else if (num > val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

