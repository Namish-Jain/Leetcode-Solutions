class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash table where row / col index is the key and a hash set for that specific row / col is the value
        unordered_map<int, unordered_set<int>> rows, cols;
        // hash table where {row index / 3, col index / 3} is the key and a hash set for that specific square is the value
        map<pair<int,int>, unordered_set<int>> squares;

        // loop through every cell in the grid
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                // if cell is empty then skip
                if (board[r][c] == '.') continue;

                // if value at that cell is in one of the hash sets then invalid
                if ((rows[r].count(board[r][c])) || (cols[c].count(board[r][c])) || squares[{r / 3, c / 3}].count(board[r][c])) return false;

                // add value to all 3 hash sets
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[{r / 3, c / 3}].insert(board[r][c]);
            }
        }

        return true;
    }
};