class Solution {
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++) dfs(r, 0, pacific, heights);
        for (int c = 0; c < cols; c++) dfs(0, c, pacific, heights);

        for (int r = 0; r < rows; r++) dfs(r, cols - 1,atlantic, heights);
        for (int c = 0; c < cols; c++) dfs(rows - 1, c, atlantic, heights);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {

        ocean[r][c] = true;

        for (auto& dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];

            if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
            if (ocean[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue;

            dfs(nr, nc, ocean, heights);
        }
    }
};