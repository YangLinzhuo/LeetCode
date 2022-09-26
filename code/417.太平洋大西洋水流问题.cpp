/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
    }
};
// @lc code=end

