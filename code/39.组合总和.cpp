/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int m_target;
    vector<int> cur;    // current vector of candidates
    int m_cur;  // current sum of candidate 
    void dfs(vector<int> &candidates, int idx, vector<vector<int>> &ans) {
        if (m_cur == m_target) {
            ans.emplace_back(cur);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (m_cur + candidates[i] > m_target) {
                continue;
            }
            m_cur += candidates[i];
            cur.push_back(candidates[i]);
            dfs(candidates, i, ans);
            cur.pop_back();
            m_cur -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        m_target = target;
        m_cur = 0;
        dfs(candidates, 0, ans);
        return ans;
    }
};
// @lc code=end

