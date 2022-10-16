/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegrees(graph.size(), 0);
        vector<vector<int>> out(graph.size(), vector<int>());
        for (int i = 0; i < graph.size(); ++i) {
            auto& item = graph[i];
            for (auto p : item) {
                indegrees[i]++;
                out[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            ans.push_back(p);
            for (auto item : out[p]) {
                indegrees[item]--;
                if (indegrees[item] == 0) {
                    q.push(item);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

