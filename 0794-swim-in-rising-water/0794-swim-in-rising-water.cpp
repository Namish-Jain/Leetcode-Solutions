class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        set<pair<int,int>> seen;
        priority_queue<vector<int>,vector<vector<int>>, greater<>> minHeap;

        minHeap.push({grid[0][0], 0, 0});
        seen.insert({0,0});

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!minHeap.empty()) {

            auto curr = minHeap.top();
            minHeap.pop();
            int maxHeight = curr[0], row = curr[1], col = curr[2];

            if ((row == grid.size() - 1) && col == (grid[0].size() - 1)) return maxHeight;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || seen.contains({newRow, newCol})) continue;

                seen.insert({newRow, newCol});
                minHeap.push({max(maxHeight, grid[newRow][newCol]), newRow, newCol});
            }
        }
        return 0;       
    }
};