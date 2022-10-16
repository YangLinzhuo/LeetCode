/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    using Coor = pair<int, int>;
    int m;
    int n;
    
    vector<vector<int>> DIRECTIONS{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool is_find(unordered_set<int> &s, Coor &target) {
        int val = target.first * n + target.second;
        return s.find(val) != s.end();
    }

    void insert(unordered_set<int> &s, Coor &target) {
        int val = target.first * n + target.second;
        s.insert(val);
    }

    void bfs(vector<vector<int>> &heights, unordered_set<int> &s, queue<Coor> &q) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while (!q.empty()) {
            Coor coor = q.front();
            q.pop();
            insert(s, coor);
            visited[coor.first][coor.second] = true;
            for (int k = 0; k < DIRECTIONS.size(); ++k) {
                int row = coor.first + DIRECTIONS[k][0];
                int col = coor.second + DIRECTIONS[k][1];
                if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || heights[row][col] < heights[coor.first][coor.second]) {
                    continue;
                } else {
                    q.emplace(Coor(row, col));
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<int> pacific;
        unordered_set<int> atlantic;
        queue<Coor> q;
        
        m = heights.size();
        n = heights[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        for (int j = 0; j < n; ++j) {
            q.emplace(Coor(0, j));
        }
        for (int i = 0; i < m; ++i) {
            q.emplace(Coor(i, 0));
        }
        bfs(heights, pacific, q);
        for (int j = 0; j < n; ++j) {
            q.emplace(Coor(m - 1, j));
        }
        for (int i = 0; i < m; ++i) {
            q.emplace(Coor(i, n - 1));
        }

        bfs(heights, atlantic, q);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                Coor coor = make_pair(i, j);
                if (is_find(pacific, coor) && is_find(atlantic, coor)) {
                    ans.emplace_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

