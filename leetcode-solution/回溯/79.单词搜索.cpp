/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
  const int dr[4] = {0, -1, 0, 1};
  const int dc[4] = {-1, 0, 1, 0};

  int row = 0;
  int col = 0;

public:
  bool dfs(vector<vector<char>> &board, string word, int r, int c,
           int startIndex) {
    if (board[r][c] != word[startIndex]) {
        return false;
    }

    if (startIndex == word.size()-1) {
        return true;
    }

    char tmp = board[r][c];
    board[r][c] = '-';

    for (int i = 0 ; i < 4 ; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || rr >= row || cc < 0 || cc >= col||board[rr][cc]=='-') {
            continue;
        }

        if (dfs(board, word, r, c, startIndex+1)) {
            return true;
        }
    }

    board[r][c] = tmp;
    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    row = board.size();
    col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
