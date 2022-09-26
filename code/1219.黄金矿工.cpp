/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    const vector<vector<int>> DIRECTIONS{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int dfs(vector<vector<int>> &grid,
             vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { 
            return 0; 
        }
        if (visited[i][j] || grid[i][j] == 0) { return 0; }
        visited[i][j] = true;
        int ans = 0;
        for (int k = 0; k < DIRECTIONS.size(); ++k) {
            int row = i + DIRECTIONS[k][0];
            int col = j + DIRECTIONS[k][1];
            ans = max(ans, dfs(grid, visited, row, col));
        }
        visited[i][j] = false;
        return ans + grid[i][j];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        // vector<vector<int>> val(grid);  // 以 grid[i][j] 为终点的最大的黄金开采量
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

