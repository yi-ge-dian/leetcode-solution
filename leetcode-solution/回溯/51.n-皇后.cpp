/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
class Solution {
  vector<vector<string>> ans;
  vector<string> board;

public:
  void dfs(int n, int row) {
    // 结束
    if (row == n) {
      ans.push_back(board);
    }

    // check
    for (int i = 0; i < n; i++) {
      if (check(row, i, board, n)) {
        board[row][i] = 'Q'; // 放置皇后
        dfs(n, row + 1);
        board[row][i] = '.'; // 撤回
      }
    }
  }

  bool check(int row, int col, vector<string> board, int n) {
    // 检查同一列
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }

    // 检查45度
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    // 检查 135度角是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }

  vector<vector<string>> solveNQueens(int n) {
    board.resize(n);
    fill(board.begin(), board.end(), string(n, '.'));
    dfs(n, 0);
    return ans;
  }
};
// @lc code=end
