/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    const int BOARD_SIZE = 9;
    int num_point = 0;
    vector<vector<bool>> row_used;
    vector<vector<bool>> col_used;
    vector<vector<bool>> blk_used;
    bool dfs(vector<vector<char>> &board, int i, int j) {
        board[i][j] = '0';
        auto coor = find_next(board, i, j);
        board[i][j] = '.';
        for (int k = 1; k <= BOARD_SIZE; ++k) {
            if (row_used[i][k] || col_used[j][k] || blk_used[(i / 3) * 3 + j / 3][k]) {
                continue;
            }
            board[i][j] = '0' + k;
            row_used[i][k] = true;
            col_used[j][k] = true;
            blk_used[(i / 3) * 3 + j / 3][k] = true;
            --num_point;
            if (num_point == 0) {
                return true;
            }
            if (coor.first >= 0 && coor.first < BOARD_SIZE && coor.second >= 0 && coor.second < BOARD_SIZE) {
                if (dfs(board, coor.first, coor.second)) {
                    return true;
                }
            }
            board[i][j] = '.';
            row_used[i][k] = false;
            col_used[j][k] = false;
            blk_used[(i / 3) * 3 + j / 3][k] = false;
            ++num_point;
        }
        return false;
    }

    pair<int, int> find_next(vector<vector<char>> &board, int row_start, int col_start) {
        int idx = row_start * BOARD_SIZE + col_start;
        while (idx < BOARD_SIZE * BOARD_SIZE) {
            int i = idx / BOARD_SIZE;
            int j = idx % BOARD_SIZE;
            if (board[i][j] == '.') {
                return make_pair(i, j);
            }
            ++idx;
        }
        return make_pair(-1, -1);
    }

    void solveSudoku(vector<vector<char>>& board) {
        row_used = vector<vector<bool>>(10, vector<bool>(10, false)); // whether used in row
        col_used = vector<vector<bool>>(10, vector<bool>(10, false)); // whether used in col
        blk_used = vector<vector<bool>>(10, vector<bool>(10, false)); // whether used in block
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == '.') { ++num_point; continue; }
                int num = board[i][j] - '0';
                row_used[i][num] = true;
                col_used[j][num] = true;
                blk_used[(i / 3) * 3 + j / 3][num] = true;
            }
        }
        auto coor = find_next(board, 0, 0);
        dfs(board, coor.first, coor.second);
    }
};
// @lc code=end



