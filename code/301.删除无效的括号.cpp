/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
// @lc code=start
class Solution {
public:
    string cur_str;
    int cur_score{0};
    int max_score{0};
    int max_len{0};
    unordered_set<string> tmp_ans;

    void add_para(string &s, int idx, bool is_left) {
        int val = is_left ? 1 : -1;
        cur_str.push_back(s[idx]);
        cur_score += val;
        dfs(s, idx + 1);
        cur_score -= val;
        cur_str.pop_back();
    }

    void dfs(string &s, int idx) {
        if (cur_score < 0 || cur_score > max_score) {
            return;
        }
        if (idx >= s.size()) {
            if (cur_score == 0 && cur_str.size() >= max_len) {
                tmp_ans.emplace(cur_str);
                max_len = cur_str.size();
            }
            return;
        }
        char c = s[idx];
        if (c == '(') {
            // add
            add_para(s, idx, true);
            // not add
            dfs(s, idx + 1);
        } else if (c == ')') {
            // add
            add_para(s, idx, false);
            // not add
            dfs(s, idx + 1);
        } else {
            // must be added
            cur_str.push_back(c);
            dfs(s, idx + 1);
            cur_str.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int left_score = 0, right_score = 0;
        for (auto c : s) {  // calculate the max score on theory
            if (c == '(') { left_score++; }
            else if (c == ')') { right_score++; }
        }
        max_score = min(left_score, right_score);
        dfs(s, 0);

        for (auto &str : tmp_ans) {
            if (str.size() == max_len) {
                ans.emplace_back(str);
            }
        }
        return ans;
    }
};
// @lc code=end

