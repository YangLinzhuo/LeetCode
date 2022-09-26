/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int m_target;
    int m_cur;
    vector<int> m_vec;
    void backtrace(vector<int> &candidates, int idx, vector<vector<int>> &ans) {
        if (m_cur == m_target) {
            ans.emplace_back(m_vec);
            return;
        }
        unordered_set<int> selected;
        for (int i = idx; i < candidates.size(); ++i) {
            if (selected.find(candidates[i]) != selected.end()) {
                continue;
            }
            if (m_cur + candidates[i] > m_target) {
                break;
            }
            selected.insert(candidates[i]);
            m_cur += candidates[i];
            m_vec.push_back(candidates[i]);
            backtrace(candidates, i + 1, ans);
            m_vec.pop_back();
            m_cur -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        m_cur = 0;
        m_target = target;
        backtrace(candidates, 0, ans);
        return ans;
    }
};
// @lc code=end

