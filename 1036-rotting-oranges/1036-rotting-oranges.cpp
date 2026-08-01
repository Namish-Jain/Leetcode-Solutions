class Solution {
private:
    void addCell(int row, int col, vector<vector<int>>& grid, queue<pair<int,int>>& q, int& fresh) {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || grid[row][col] == 2) return;

        grid[row][col] = 2;
        q.push({row, col});
        fresh--;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int mins = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i,j});
                if (grid[i][j] == 1 ) fresh++;
            }
        }

        if (!fresh) return 0;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                addCell(row + 1, col, grid, q, fresh);
                addCell(row - 1, col, grid, q, fresh);
                addCell(row, col + 1, grid, q, fresh);
                addCell(row, col - 1, grid, q, fresh);
                size--;
            }
            mins++;
            if (fresh == 0) return mins;
        }
        return -1;
    }
};