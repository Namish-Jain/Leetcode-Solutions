class Solution {

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index, vector<vector<bool>>& seen) {

        if (index == word.size()) return true;

        if (row >= board.size() || row < 0 || col < 0 || col >= board[0].size() || board[row][col] != word[index] || seen[row][col]) return false;

        seen[row][col] = true;

        bool ans = dfs(board, row + 1, col, word, index + 1, seen) || dfs(board, row - 1, col, word, index + 1, seen) ||
        dfs(board, row, col + 1, word, index + 1, seen) || dfs(board, row, col - 1, word, index + 1, seen);

        seen[row][col] = false;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();

        vector<vector<bool>> seen(r, vector<bool>(c, false));

        for (int i{}; i < r; ++i) {
            for (int j{}; j < c; ++j) {
                int row = i, col = j;
                if (dfs(board, row, col, word, 0, seen)) return true;
            }
        }
        return false;
    }
};