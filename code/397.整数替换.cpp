/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

#include <numeric>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int min_cnt{INT_MAX};
    void dfs(long long n, int cnt) {
        while (!(n & 1)) {
            n /= 2;
            cnt += 1;
        }
        if (n == 1) {
            min_cnt = min(cnt, min_cnt);
            return;
        }
        dfs(n - 1, cnt + 1);
        dfs(n + 1, cnt + 1);
    }

    int integerReplacement(int n) {
        dfs(static_cast<long long>(n), 0);
        return min_cnt;
    }
};
// @lc code=end

