/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> indegrees(quiet.size(), 0);
        vector<vector<int>> out(quiet.size(), vector<int>());
        for (auto& item : richer) {
            int a = item[0];
            int b = item[1];
            out[a].push_back(b);
            indegrees[b]++;
        }
        vector<int> sort_result;
        vector<int> ans(quiet.size(), 0);
        for (int i = 0; i < quiet.size(); ++i) {
            ans[i] = i;
        }
        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            sort_result.push_back(p);
            for (int item : out[p]) {
                indegrees[item]--;
                if (indegrees[item] == 0) {
                    q.push(item);
                }
                if (quiet[ans[p]] < quiet[ans[item]]) {
                    ans[item] = ans[p];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

