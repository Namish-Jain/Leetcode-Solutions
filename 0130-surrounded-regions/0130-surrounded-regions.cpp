class Solution {
public:
    void dfs(int row, int col,  vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') return;

        board[row][col] = 'T';
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if ((r == 0 || r == board.size() - 1 || c == 0 || c == board[0].size() - 1) && board[r][c] == 'O') dfs(r, c, board);
            }
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) { 
                if (board[r][c] == 'T') board[r][c] = 'O';
                else if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }
    }
};