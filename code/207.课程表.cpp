/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> successor(numCourses, vector<int>());
        for (auto &item : prerequisites) {
            int a = item[0];
            int b = item[1];
            indegrees[a]++;
            successor[b].push_back(a);
        }
        queue<int> Q;
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int course = Q.front();
            Q.pop();
            ans.push_back(course);
            for (int item : successor[course]) {
                indegrees[item]--;
                if (indegrees[item] == 0) {
                    Q.push(item);
                }
            }
        }
        return ans.size() == numCourses;
    }
};
// @lc code=end

