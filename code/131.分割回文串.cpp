/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> m_cur;
    void init_dp(string &s, vector<vector<bool>> &is_sym) {
        for (int j = 0; j < s.size(); ++j) {
            for (int i = j; i >= 0; --i) {
                if (i == j) {
                    is_sym[i][j] = true;
                } else {
                    if (j - i + 1 == 2) { // e.g. 'ab' 'aa'
                        is_sym[i][j] = (s[i] == s[j]);
                    } else {    // e.g. 'abc' 'aba' 'abab'
                        is_sym[i][j] = (is_sym[i + 1][j - 1] && s[i] == s[j]);
                    }
                }
            }
        }
    }

    void backtrace(string &s, int i, vector<vector<bool>> &is_sym, vector<vector<string>> &ans) {
        if (i >= s.size()) {
            ans.emplace_back(m_cur);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (!is_sym[i][j]) {
                continue;
            }
            m_cur.emplace_back(s.substr(i, j - i + 1));
            backtrace(s, j + 1, is_sym, ans);
            m_cur.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> is_sym(s.size(), vector<bool>(s.size(), false));
        vector<vector<string>> ans;
        init_dp(s, is_sym);
        backtrace(s, 0, is_sym, ans);
        return ans;
    }
};
// @lc code=end

