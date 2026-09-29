class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<bool> cols(c, false);
        vector<bool> rows(r, false);

        for (int i{}; i < matrix.size(); ++i) {
            for (int j{}; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    cols[j] = true;
                    rows[i] = true;
                }
            }
        }

        for (int i{}; i < matrix.size(); ++i) {
            for (int j{}; j < matrix[0].size(); ++j) {
                if (cols[j] || rows[i]) matrix[i][j] = 0;
            }
        }
    }
};