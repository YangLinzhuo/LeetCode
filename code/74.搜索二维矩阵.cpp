/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_row = matrix.size();
        int num_col = matrix[0].size();
        int left = 0, right = num_row * num_col;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int i = mid / num_col;
            int j = mid % num_col;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

