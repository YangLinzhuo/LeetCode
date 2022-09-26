/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> candidate{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    unordered_map<int, string> table{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string intToRoman(int num) {
        string ans;
        for (int i = 0; i < candidate.size(); ++i) {
            while (num >= candidate[i]) {
                ans += table[candidate[i]];
                num -= candidate[i];
            }
        }
        return ans;
    }
};
// @lc code=end
